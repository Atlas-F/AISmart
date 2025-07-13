/*********************
 * @file deepseek_tianqi.c
 * @brief 获取天气情况，保留城市地址作为接口
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-07-13
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/
#include "deepseek_tianqi.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"
#include "ui.h"

#include "lvgl/lvgl.h"



/*********************
 * @brief 回调函数用于存储HTTP响应数据，对数据进行处理。
 * @param  contents 
 * @param  size 
 * @param  nmemb 
 * @param  userp 
 * @return int 
 *************************************************/
static int write_callback(void *contents, int size, int nmemb, void *userp) {
    int realsize = size * nmemb;
    struct WeatherMemoryStruct *mem = (struct WeatherMemoryStruct *)userp;
    
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(!ptr) {
        fprintf(stderr, "内存分配失败\n");
        return 0;
    }
    
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

/*********************
 * @brief Get the weather object
 * @param  location 城市
 * @details 将https的直接响应数据再添加一层中间层传递出来，同时也保护原始数据
 *          将天气代码code用于设置天气UI
 *************************************************/
void get_weather(const char *location) {
    CURL *curl;
    CURLcode res;
    
    // 初始化内存结构体
    struct WeatherMemoryStruct chunk;
    chunk.memory = malloc(1);  // 初始分配1字节，后面realloc会调整
    chunk.size = 0;

    // 初始化结果结构体
    struct WeatherResultStruct weatherResult ;
    weatherResult.cityName = malloc(16);
    weatherResult.weatherText = malloc(16);
    weatherResult.tempurature = malloc(8);
    weatherResult.weathercode = malloc(8);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        // 构建API请求URL
        char url[256];
        const char *api_key = "S5s2v5deZctn-lyum";
        snprintf(url, sizeof(url), 
                 "https://api.seniverse.com/v3/weather/now.json?key=%s&location=%s&language=zh-Hans&unit=c",
                 api_key, location);
        
        // 设置cURL选项
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // 简化SSL验证
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        
        // 执行HTTP请求
        res = curl_easy_perform(curl);
        
        // 检查请求结果
        if(res != CURLE_OK) {
            fprintf(stderr, "请求失败: %s\n", curl_easy_strerror(res));
        } else {
            // 解析JSON响应
            cJSON *json = cJSON_Parse(chunk.memory);
            if(!json) {
                const char *error_ptr = cJSON_GetErrorPtr();
                if (error_ptr) {
                    fprintf(stderr, "JSON解析错误: %s\n", error_ptr);
                }
            } else {
                cJSON *results = cJSON_GetObjectItemCaseSensitive(json, "results");
                if(cJSON_IsArray(results) && cJSON_GetArraySize(results) > 0) {
                    cJSON *result = cJSON_GetArrayItem(results, 0);
                    cJSON *now = cJSON_GetObjectItemCaseSensitive(result, "now");
                    cJSON *location_obj = cJSON_GetObjectItemCaseSensitive(result, "location");
                    cJSON *location_name = cJSON_GetObjectItemCaseSensitive(location_obj, "name");
                    cJSON *text = cJSON_GetObjectItemCaseSensitive(now, "text");
                    cJSON *temp = cJSON_GetObjectItemCaseSensitive(now, "temperature");
                    cJSON *code = cJSON_GetObjectItemCaseSensitive(now, "code");
                    
                    if(location_name && text && temp && code) {
                        printf("地点: %s\n", location_name->valuestring);
                        printf("天气: %s\n", text->valuestring);
                        printf("温度: %s°C\n", temp->valuestring);
                        printf("code: %s\n", code->valuestring);

                        // weatherResult.cityName = location_name->valuestring;
                        // weatherResult.weatherText = text->valuestring;
                        // weatherResult.tempurature = temp->valuestring;

                        // 使用strncpy函数复制会有些特殊的符号，除非精确知道复制的字符的个数
                        // strncpy(weatherResult.cityName, location_name->valuestring, strlen(location_name->valuestring));
                        // strncpy(weatherResult.weatherText, text->valuestring, strlen(text->valuestring));
                        // strncpy(weatherResult.tempurature, temp->valuestring, strlen(temp->valuestring));

                        strcpy(weatherResult.cityName, location_name->valuestring);
                        strcpy(weatherResult.weatherText, text->valuestring);
                        strcpy(weatherResult.tempurature, temp->valuestring);
                        strcpy(weatherResult.weathercode, code->valuestring);

                        printf("result地点: %s\n", weatherResult.cityName);
                        printf("result天气: %s\n", weatherResult.weatherText);
                        printf("result温度: %s°C\n", weatherResult.tempurature);
                        printf("resultcode: %d\n", atoi(weatherResult.weathercode));

                        // 设置到lvgl 的label 
                        lv_label_set_text_fmt(ui_locationtempurature, "%s-%s-%s度",weatherResult.cityName,weatherResult.weatherText,weatherResult.tempurature);
                        // 设置到lvgl的天气logo，
                        lv_obj_t * weathercjild = lv_obj_get_child(ui_weather, atoi(weatherResult.weathercode));
                        lv_obj_clear_flag(weathercjild, LV_OBJ_FLAG_HIDDEN);


                    } else {
                        fprintf(stderr, "解析天气数据失败\n");
                    }
                } else {
                    cJSON *status = cJSON_GetObjectItemCaseSensitive(json, "status");
                    if (status) {
                        cJSON *status_code = cJSON_GetObjectItemCaseSensitive(status, "code");
                        cJSON *status_message = cJSON_GetObjectItemCaseSensitive(status, "message");
                        if (status_code && status_message) {
                            fprintf(stderr, "API错误: [%s] %s\n", 
                                    cJSON_IsString(status_code) ? status_code->valuestring : "?",
                                    status_message->valuestring);
                        }
                    } else {
                        fprintf(stderr, "未返回结果或结果为空\n");
                    }
                }
                cJSON_Delete(json);
            }
        }
        
        // 清理cURL资源
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
    // 释放结果结构体
    free(weatherResult.cityName);
    free(weatherResult.weatherText);
    free(weatherResult.tempurature);
    free(weatherResult.weathercode);


    curl_global_cleanup();
}

// // 示例用法
//     get_weather("广州"); // 获取北京的天气


//int main(int argc, char* argv[])