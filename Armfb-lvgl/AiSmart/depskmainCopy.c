
/*********************
 * @file depskmainCopy.c
 * @brief ARm开发板使用deepseek接口文件
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-06-20
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/

#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

#include "depskmainCopy.h"

#include "lvgl/lvgl.h"

#include <stdio.h>

#include <errno.h>
#include "ui_helpers.h"
#include "ui_events.h"

#include "ui.h"
#include "ui_helpers.h"

#define DEBUG_MODE 1

// 使用缓冲区输入输出是没问题的，需要解决循环的问题，
char textbuf[128] = "who are you";

extern char * kbEntertext;
char dpOut[128] = {0};

// ================== 前置声明 ==================
struct MemoryStruct;
struct APIResponse;
char* get_api_key();
struct APIResponse call_deepseek(const char *api_key, const char *prompt);
void print_token_usage(int prompt_tokens, int completion_tokens, int total_tokens);


    DeepSeekSession *session;
    char input[1024];
    int prompt_tokens, completion_tokens, total_tokens;
    char *response;

// ================== 辅助函数 ==================
// libcurl回调函数
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
    
    input_key[strcspn(input_key, "\n")] = 0;
    return input_key;
}

// ================== 核心API函数 ==================
// 调用DeepSeek API
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

    // 设置OpenSSL引擎选项
    setenv("OPENSSL_ia32cap", "~0x200000200000000", 1);

    // 设置API端点
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.deepseek.com/chat/completions");

    // // 添加 SSL 版本和密码套件配置
    curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);
    // 使用兼容的密码套件
    curl_easy_setopt(curl, CURLOPT_SSL_CIPHER_LIST, "ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384");

    // 修改 call_deepseek 函数中的SSL设置部分
#ifdef  0 // 调试模式下禁用验证
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#else
    // 生产环境使用系统证书
    curl_easy_setopt(curl, CURLOPT_CAINFO, "/etc/ssl/certs/ca-certificates.crt");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
#endif


    // 资源优化设置
    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 1024L);
    curl_easy_setopt(curl, CURLOPT_UPLOAD_BUFFERSIZE, 1024L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    /*************************************************
     * @brief 有关于SSL证书配置
     *************************************************/

    // 添加详细的错误信息
    char errbuf[CURL_ERROR_SIZE];
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_CERTINFO, 1L);
    
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

    // 检查不支持的协议
    if(res == CURLE_UNSUPPORTED_PROTOCOL) {
        fprintf(stderr, "cURL错误: 不支持的协议 - URL: %s\n", 
                "https://api.deepseek.com/chat/completions");
        
        // 获取支持的协议列表
        curl_version_info_data *ver_info = curl_version_info(CURLVERSION_NOW);
        if(ver_info && ver_info->protocols) {
            fprintf(stderr, "支持的协议列表:\n");
            const char * const *proto;
            for(proto = ver_info->protocols; *proto; proto++) {
                fprintf(stderr, "- %s\n", *proto);
            }
        }
    } else if(res != CURLE_OK) {
    fprintf(stderr, "cURL错误详情: %s\n", curl_easy_strerror(res));
    
    // 获取SSL错误详情
    long verify_result;
    curl_easy_getinfo(curl, CURLINFO_SSL_VERIFYRESULT, &verify_result);
    fprintf(stderr, "SSL验证结果: %ld\n", verify_result);
    
    // 获取证书信息
    struct curl_certinfo *certinfo;
    curl_easy_getinfo(curl, CURLINFO_CERTINFO, &certinfo);
    if(certinfo) {
        fprintf(stderr, "证书信息:\n");
        for(int i = 0; i < certinfo->num_of_certs; i++) {
            struct curl_slist *slist;
            for(slist = certinfo->certinfo[i]; slist; slist = slist->next) {
                fprintf(stderr, "  %s\n", slist->data);
            }
        }
    }
} else if 
    (res == CURLE_SSL_PEER_CERTIFICATE) {
        fprintf(stderr, "SSL证书错误: %s\n", curl_easy_strerror(res));
        // 获取更多错误信息
        char error_buffer[CURL_ERROR_SIZE];
        curl_easy_getinfo(curl, CURLINFO_SSL_VERIFYRESULT, &error_buffer);
        fprintf(stderr, "SSL验证结果: %s\n", error_buffer);
    }
    
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

// 显示令牌使用信息
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
// 创建新会话
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

// 销毁会话
void deepseek_destroy_session(DeepSeekSession *session) {
    if (!session) return;
    
    free(session->api_key);
    free(session);
}

// 发送消息并获取回复
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

// 获取会话令牌统计
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
int depmainlong(lv_event_t * e) // 创建会话
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


int depmaintalk(lv_event_t * e) // 会话
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if( event_code == LV_EVENT_CLICKED )
    {
        if( !lv_obj_has_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN)) {
            printf("\n你的问题: ");
            // char input[1024];

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

