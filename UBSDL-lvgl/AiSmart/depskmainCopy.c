/*********************
 * @file depskmainCopy.c
 * @brief deepseek 接口操作函数
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-06-17
 * 
 * @details 使用cjson和curl库
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

#include "depskmainCopy.h"
#include "lvgl/lvgl.h"
#include <stdio.h>
#include <errno.h>
#include "ui_helpers.h"
#include "ui_events.h"


#include "ui.h"
#include "ui_helpers.h"

// 使用缓冲区输入输出是没问题的，需要解决循环的问题，不使用循环
// 模拟测试文本缓冲区
char textbuf[128] = "who are you";

// 文本输入
extern char * kbEntertext;
char dpOut[128] = {0};

// ================== 前置声明 ==================
struct MemoryStruct;
struct APIResponse;
char* get_api_key();
struct APIResponse call_deepseek(const char *api_key, const char *prompt);
void print_token_usage(int prompt_tokens, int completion_tokens, int total_tokens);


/*********************
 * @brief deepseek与网络通信部份相应的全局变量
 *************************************************/
DeepSeekSession *session;
char input[1024];
int prompt_tokens, completion_tokens, total_tokens;
char *response;


// ================== 辅助函数 ==================
/*********************
 * @brief libcurl回调函数
 * @param  contents 
 * @param  size 
 * @param  nmemb 
 * @param  userp 
 * @return size_t 
 *************************************************/
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(!ptr) {
        fprintf(stderr, "内存分配错误\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

// 获取API密钥
/*********************
 * @brief Get the api key object
 * @return char* 
 *************************************************/
char* get_api_key() {
    char *api_key = getenv("DEEPSEEK_API_KEY");
    if (api_key && strlen(api_key) > 0) {
        return strdup(api_key);
    }
    
    printf("未找到环境变量 DEEPSEEK_API_KEY\n");
    printf("请访问 https://platform.deepseek.com/api-keys 创建API密钥\n");
    
    char *input_key = malloc(256);
    if (!input_key) {
        fprintf(stderr, "内存分配失败\n");
        return NULL;
    }
    
    printf("请输入您的DeepSeek API密钥: ");
    if (fgets(input_key, 256, stdin) == NULL) {
        free(input_key);
        return NULL;
    }
    
    // 这是什么语法
    input_key[strcspn(input_key, "\n")] = 0;
    return input_key;
}

// ================== 核心API函数 ==================
/*********************
 * @brief 调用DeepSeek API
 * @param  api_key 
 * @param  prompt 
 * @return struct APIResponse 
 *************************************************/
struct APIResponse call_deepseek(const char *api_key, const char *prompt) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk = {0};
    long http_code = 0;
    struct APIResponse api_response = {0};

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(!curl) {
        fprintf(stderr, "无法初始化cURL\n");
        return api_response;
    }

    // 设置API端点
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.deepseek.com/chat/completions");
    
    // 设置请求头
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    char auth_header[256];
    snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", api_key);
    headers = curl_slist_append(headers, auth_header);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    
    // 构建请求体
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "model", "deepseek-chat");
    cJSON_AddNumberToObject(root, "max_tokens", 2000);
    
    cJSON *messages = cJSON_CreateArray();
    cJSON *message = cJSON_CreateObject();
    cJSON_AddStringToObject(message, "role", "user");
    cJSON_AddStringToObject(message, "content", prompt);
    cJSON_AddItemToArray(messages, message);
    
    cJSON_AddItemToObject(root, "messages", messages);
    char *post_data = cJSON_PrintUnformatted(root);
    
    // 设置POST数据
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(post_data));
    
    // 设置响应回调
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    
    // 设置超时
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    
    // 执行请求
    res = curl_easy_perform(curl);
    
    // 检查HTTP状态码
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    
    // 清理cURL资源
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    cJSON_Delete(root);
    free(post_data);
    
    // 调试信息
    printf("\n--- API请求详情 ---\n");
    printf("端点: https://api.deepseek.com/chat/completions\n");
    printf("模型: deepseek-chat\n");
    printf("提示: %s\n", prompt);
    printf("状态码: %ld\n", http_code);
    
    if(res != CURLE_OK) {
        fprintf(stderr, "cURL错误: %s\n", curl_easy_strerror(res));
        if(chunk.memory) free(chunk.memory);
        curl_global_cleanup();
        return api_response;
    }
    
    // 检查HTTP状态码
    if(http_code != 200) {
        fprintf(stderr, "API错误: HTTP %ld\n", http_code);
        if(chunk.memory) {
            printf("原始响应: %s\n", chunk.memory);
            
            cJSON *error_json = cJSON_Parse(chunk.memory);
            if(error_json) {
                cJSON *error_obj = cJSON_GetObjectItem(error_json, "error");
                if(error_obj) {
                    cJSON *message = cJSON_GetObjectItem(error_obj, "message");
                    cJSON *code = cJSON_GetObjectItem(error_obj, "code");
                    
                    if(cJSON_IsString(message)) {
                        fprintf(stderr, "错误信息: %s\n", message->valuestring);
                    }
                    if(cJSON_IsString(code)) {
                        fprintf(stderr, "错误代码: %s\n", code->valuestring);
                    }
                }
                cJSON_Delete(error_json);
            }
        }
        if(chunk.memory) free(chunk.memory);
        curl_global_cleanup();
        return api_response;
    }
    
    curl_global_cleanup();
    
    // 解析API响应
    cJSON *response_json = cJSON_Parse(chunk.memory);
    if (!response_json) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr) fprintf(stderr, "JSON解析错误: %s\n", error_ptr);
        fprintf(stderr, "原始响应: %s\n", chunk.memory);
        free(chunk.memory);
        return api_response;
    }
    
    // 提取令牌使用信息
    cJSON *usage = cJSON_GetObjectItem(response_json, "usage");
    if (usage) {
        cJSON *prompt_tokens = cJSON_GetObjectItem(usage, "prompt_tokens");
        cJSON *completion_tokens = cJSON_GetObjectItem(usage, "completion_tokens");
        cJSON *total_tokens = cJSON_GetObjectItem(usage, "total_tokens");
        
        if (cJSON_IsNumber(prompt_tokens)) api_response.prompt_tokens = prompt_tokens->valueint;
        if (cJSON_IsNumber(completion_tokens)) api_response.completion_tokens = completion_tokens->valueint;
        if (cJSON_IsNumber(total_tokens)) api_response.total_tokens = total_tokens->valueint;
    }
    
    // 提取回复内容
    cJSON *choices = cJSON_GetObjectItem(response_json, "choices");
    if (cJSON_IsArray(choices) && cJSON_GetArraySize(choices) > 0) {
        cJSON *first_choice = cJSON_GetArrayItem(choices, 0);
        cJSON *message = cJSON_GetObjectItem(first_choice, "message");
        cJSON *content = cJSON_GetObjectItem(message, "content");
        
        if (cJSON_IsString(content) && content->valuestring != NULL) {
            api_response.content = strdup(content->valuestring);
        }
    }
    
    cJSON_Delete(response_json);
    free(chunk.memory);
    return api_response;
}

/*********************
 * @brief 显示令牌使用信息
 * @param  prompt_tokens 
 * @param  completion_tokens 
 * @param  total_tokens 
 *************************************************/
void print_token_usage(int prompt_tokens, int completion_tokens, int total_tokens) {
    printf("\n--- 令牌使用 ---\n");
    printf("提示令牌: %d\n", prompt_tokens);
    printf("完成令牌: %d\n", completion_tokens);
    printf("总令牌: %d\n", total_tokens);
    
    // 估算成本
    double estimated_cost = total_tokens * 0.0000015; // $0.0015/1K tokens
    printf("估算成本: $%.6f\n", estimated_cost);
}

// ================== 会话管理函数 ==================
/*********************
 * @brief 创建新会话
 * @param  api_key 
 * @return DeepSeekSession* 
 *************************************************/
DeepSeekSession* deepseek_create_session(const char *api_key) {
    DeepSeekSession *session = malloc(sizeof(DeepSeekSession));
    if (!session) return NULL;
    
    // 修复类型不匹配问题
    if (api_key) {
        session->api_key = strdup(api_key);
    } else {
        session->api_key = get_api_key();
    }
    
    session->total_prompt_tokens = 0;
    session->total_completion_tokens = 0;
    session->total_all_tokens = 0;
    
    return session;
}

// 
/*********************
 * @brief 销毁会话
 * @param  session 
 *************************************************/
void deepseek_destroy_session(DeepSeekSession *session) {
    if (!session) return;
    
    free(session->api_key);
    free(session);
}

// 
/*********************
 * @brief 发送消息并获取回复
 * @param  session 
 * @param  message 
 * @param  prompt_tokens 
 * @param  completion_tokens 
 * @param  total_tokens 
 * @return char* 
 *************************************************/
char* deepseek_send_message(
    DeepSeekSession *session, 
    const char *message,
    int *prompt_tokens,  // 返回本次提示令牌
    int *completion_tokens,  // 返回本次完成令牌
    int *total_tokens    // 返回本次总令牌
) {
    if (!session || !message) return NULL;
    
    struct APIResponse response = call_deepseek(session->api_key, message);
    
    if (response.content) {
        // 更新会话令牌计数
        session->total_prompt_tokens += response.prompt_tokens;
        session->total_completion_tokens += response.completion_tokens;
        session->total_all_tokens += response.total_tokens;
        
        // 设置输出参数
        if (prompt_tokens) *prompt_tokens = response.prompt_tokens;
        if (completion_tokens) *completion_tokens = response.completion_tokens;
        if (total_tokens) *total_tokens = response.total_tokens;
        
        return response.content;
    }
    
    return NULL;
}

// 
/*********************
 * @brief 获取会话令牌统计
 * @param  session 
 * @param  total_prompt 
 * @param  total_completion 
 * @param  total_all 
 *************************************************/
void deepseek_get_token_stats(
    DeepSeekSession *session,
    int *total_prompt,
    int *total_completion,
    int *total_all
) {
    if (!session) return;
    
    if (total_prompt) *total_prompt = session->total_prompt_tokens;
    if (total_completion) *total_completion = session->total_completion_tokens;
    if (total_all) *total_all = session->total_all_tokens;
}

/*********************
 * @brief Get the full text input object
 * @details 获取完整的文本内容并输入到指定的缓冲区，未修正之前无法获取完整的文本框内容
 *          遇到空格会中断文本内容，无法获取空格之后的文本内容
 * @param  dest 
 * @param  dest_size 
 *************************************************/
void get_full_text_input(char *dest, size_t dest_size) {
    // 获取文本区域内容指针
    const char *text = lv_textarea_get_text(ui_TextArea1);
    if (!text) {
        dest[0] = '\0';
        return;
    }
    
    // 计算实际文本长度（包括空格）
    size_t text_len = strlen(text);
    
    // 安全复制文本（防止缓冲区溢出）
    size_t copy_len = text_len < dest_size - 1 ? text_len : dest_size - 1;
    strncpy(dest, text, copy_len);
    dest[copy_len] = '\0'; // 确保字符串终止
    
    // 移除末尾的换行符（如果有）
    char *newline = strchr(dest, '\n');
    if (newline) *newline = '\0';
}

// ================== 主函数 ==================
/*********************
 * @brief 创建会话
 * @param  e 
 * @details 加入LVGL，在函数void ui_event_inputlogo(lv_event_t * e)
 *          中初始化，长按召出键盘与输入框，点击提交输入内容。
 *          但是将创建会话的功能剥离出去，该函数已经可有可无了
 * @return int 
 *************************************************/
int depmainlong(lv_event_t * e) // 创建会话标志，拉出键盘，标志进入会话
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if( event_code == LV_EVENT_LONG_PRESSED )
    {
        printf("DeepSeek聊天客户端 (输入'exit'退出)\n");
        printf("使用的API密钥: %.6s...\n", session->api_key);
        return 0; 
    }   
}

/*********************
 * @brief 会话
 * @param  e 
 * @details 交互会话，输入完成之后点击logo提交文本内容
 * @return int 
 *************************************************/
int depmaintalk(lv_event_t * e) // 会话
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if( event_code == LV_EVENT_CLICKED )
    {
        // 判断键盘的状态，是否隐藏，若未隐藏，代表动画执行完毕，浮出，可以开始输入
        if( !lv_obj_has_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN)) {
            printf("\n你的问题: ");
                printf("inputlogo被anxia!\n");

                get_full_text_input(input, sizeof(input));
                // sscanf(lv_textarea_get_text(ui_TextArea1), "%s", input);
                printf("kbEntertext = %s\n", kbEntertext);
                printf("input = %s\n", input);

                if( strcmp(input, "exit") == 0 )
                {
                     // 清理资源
                    deepseek_destroy_session(session);
                    printf("退出！\n");
                    return 0; 
                }

            printf("正在查询DeepSeek API...\n");

            // char *response = deepseek_send_message
                response = deepseek_send_message(
                session, 
                input,
                &prompt_tokens,
                &completion_tokens,
                &total_tokens
            );
            
            if(response) {
                // printf("\n--- DeepSeek回复 ---\n%s\n", response);
                printf("\n--- DeepSeek回复 ---\n");
                sprintf(dpOut, "%s", response);
                printf("%s\n", dpOut);
                lv_label_set_text(ui_AILabel, dpOut);
                
                // 显示令牌使用
                print_token_usage(prompt_tokens, completion_tokens, total_tokens);
                
                free(response);
            } else {
                printf("获取回复时出错\n");
            }
        }
        if( strcmp(input, "exit") == 0 )
        {
            // 清理资源
            deepseek_destroy_session(session);
            return 0; 
        }
        
    }   
}

