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

 /* 错误信息输出使用<>括号，正常输出使用[], 对话文本输出使用【】 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <curl/curl.h>
#include "cJSON.h"
#include <stdbool.h>

#include "depskmainCopy.h"
#include "lvgl/lvgl.h"
#include <stdio.h>
#include <errno.h>
#include "ui_helpers.h"
#include "ui_events.h"
#include "ui.h"

#include <inttypes.h>
#include "MessageHistory.h"





#define MAX_INPUT_LEN 2048  // 增大缓冲区
__attribute__((aligned(256))) 
char input[MAX_INPUT_LEN];  // 对齐边界

// 添加保护区域
uint8_t input_guard[128] = {0};  // 溢出检测区

DeepSeekSession *session = NULL;  // 远离输入缓冲区

// 对话历史结构体
extern MessageHistory * meghistory ;

// 重排token变量
int prompt_tokens;
int completion_tokens;
int total_tokens;

#define SESSION_MAGIC 0x5E5510DE


char textbuf[128] = "who are you";
// 文本输入
extern char * kbEntertext;

#define DP_OUT_SIZE 512
char dpOut[DP_OUT_SIZE] = {0};


// ================== 前置声明 ==================
struct MemoryStruct;
struct APIResponse;
char* get_api_key();
struct APIResponse call_deepseek(const char *api_key, const char *prompt);
void print_token_usage(int prompt_tokens, int completion_tokens, int total_tokens);



// 构造全局变量:messgaes 对象数组，然后每次输入和输出就向里面添加对象，不用中间消息数组，直接向数组添加消息对象
// 由于每次构造时都是新的局部变量，所以只添加一次消息对象

cJSON *root = NULL;
cJSON *messages =  NULL;
// char *post_data = NULL;
// struct curl_slist *headers = NULL;
// CURL *curl;

/*********************
 * @brief 创建初始化函数，负责一次性设置全局资源
 * @param  api_key 
 * @return true 
 * @return false 
 *************************************************/
#if 0
bool CompleteInit()
{
    // 1. 初始化libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    // curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "错误: 无法初始化cURL\n");
        return false;
    }

    // 设置请求头
    // struct curl_slist *headers = NULL;
    // headers = curl_slist_append(headers, "Content-Type: application/json");
    // char auth_header[256];
    // snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", api_key);
    // headers = curl_slist_append(headers, auth_header);
    // curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 3、初始化JSON请求体
    CompleteRequestBodyroot();

    // 4、初始化消息数组
    messages = cJSON_CreateArray();
    if (!messages) {
        fprintf(stderr, "错误: 无法创建消息数组\n");
        return false;
    }
    cJSON_AddItemToObject(root, "messages", messages);

    return true;
}
#endif

/*********************
 * @brief 清理API客户端资源
 *************************************************/
#if 0
void CleanupApiClient()
{
    if (post_data) {
        free(post_data);
        post_data = NULL;
    }
    
    if (headers) {
        curl_slist_free_all(headers);
        headers = NULL;
    }
    
    if (curl) {
        curl_easy_cleanup(curl);
        curl = NULL;
    }
    
    if (root) {
        cJSON_Delete(root);
        root = NULL;
    }
    
    curl_global_cleanup();
}
#endif

void CompleteRequestBodyroot()
{
    root = cJSON_CreateObject();
    if (!root) {
        fprintf(stderr, "错误: 无法创建JSON根对象\n");
        return false;
    }
    cJSON_AddStringToObject(root, "model", "deepseek-chat");
    cJSON_AddNumberToObject(root, "max_tokens", 2000);
}

/*********************
 * @brief 构造messages数组用户消息对象并添加到messages数组
 * @param  messages 
 * @param  prompt 
 *************************************************/
void MakeupUserMessageObj(cJSON *messages, const char *prompt)
{
    if (!messages || !prompt) return;  // 检查输入参数
    cJSON *message = cJSON_CreateObject();
    if (!message)  // 处理内存分配失败
    {
        fprintf(stderr, "错误：[cJSON_CreateObject](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        return;
    }
    cJSON_AddStringToObject(message, "role", "user");
    cJSON_AddStringToObject(message, "content", prompt);

        // 将message对象添加到messages数组
    cJSON_AddItemToArray(messages, message);
}

/*********************
 * @brief 构造messages数组AI消息对象并添加到messages数组
 * @param  messages 
 * @param  dpOutput 
 *************************************************/
void MakeupAIReplyMessageObj(cJSON *messages, const char *dpOutput)
{
    cJSON *AIReply = cJSON_CreateObject();
    cJSON_AddStringToObject(AIReply, "role", "assistant");
    cJSON_AddStringToObject(AIReply, "content", dpOutput);

        // 将message对象添加到messages数组
    cJSON_AddItemToArray(messages, AIReply);
}


void ResolveInputMessage()
{

}


/*********************
 * @brief 保护区域检查
 *************************************************/
void check_guard_zone() {
    for (int i = 0; i < sizeof(input_guard); i++) {
        if (input_guard[i] != 0) {
            printf("<!!! BUFFER OVERFLOW DETECTED at position %d !!!>\n", i);
            // 重置保护区域
            input_guard[i] = 0;
            // 可选：添加恢复逻辑或错误处理
        }
    }
}

/*********************
 * @brief 获取当前栈指针的辅助函数
 *************************************************/
static inline void* get_stack_pointer(void) {
    void *sp;
    asm volatile ("mov %%rsp, %0" : "=r"(sp));
    return sp;
}
/*********************
 * @brief deepseek与网络通信部份相应的全局变量
 *************************************************/
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
        fprintf(stderr, "<内存分配错误>\n");
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

    return api_key;
}

// ================== 核心API函数 ==================
/*********************
 * @brief 调用DeepSeek API
 * @param  api_key 
 * @param  prompt 
 * @return struct APIResponse 
 *************************************************/
//  struct APIResponse call_deepseek(const char *api_key, const char *prompt) {
//     // 函数入口栈指针检查
//     void *entry_sp = get_stack_pointer();
//     printf("[函数入口栈指针: %p]\n", entry_sp);
    
//     // 计算栈使用量
//     static void *last_pre_call_sp = NULL;
//     if (last_pre_call_sp) {
//         uintptr_t stack_used = (uintptr_t)last_pre_call_sp - (uintptr_t)entry_sp;
//         printf("[栈使用量: %" PRIuPTR " 字节]\n", stack_used);
//     }
//     last_pre_call_sp = entry_sp;

//     // 原有代码
//     CURL *curl;
//     CURLcode res;
//     struct MemoryStruct chunk = {0};
//     long http_code = 0;
//     struct APIResponse api_response = {0};

//     curl_global_init(CURL_GLOBAL_DEFAULT);
//     curl = curl_easy_init();
//     // curl_easy_reset(curl);
//     if(!curl) {
//         fprintf(stderr, "<无法初始化cURL>\n");
//         return api_response;
//     }

//     // // 设置API端点
//     curl_easy_setopt(curl, CURLOPT_URL, "https://api.deepseek.com/chat/completions");
    
//     /* -----------------------------------------------------*/

//     // 设置请求头
//     struct curl_slist *headers = NULL;
//     headers = curl_slist_append(headers, "Content-Type: application/json");
//     char auth_header[256];
//     snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", api_key);
//     headers = curl_slist_append(headers, auth_header);
//     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    
//     // 构建root请求体--使用函数代替，并设为全局变量，在事件层初始化
//     CompleteRequestBodyroot();

//     // 使用全局messages对象并进行构造添加
//     MakeupUserMessageObj(messages, prompt);

//     /* -----------------------------------------------------*/
//     cJSON_AddItemToObject(root, "messages", messages);

//     char *post_data = cJSON_PrintUnformatted(root);   // 有疑点，如何安置？？？
//     if (!post_data) {
//         fprintf(stderr, "错误: 无法生成JSON请求体\n");
//         return api_response;
//     }

//     // 打印最终cjson对象数据
//     if (root) {
//         char *jsonstring = cJSON_Print(root);
//         if (jsonstring) {
//             printf("%s\n", jsonstring);
//             free(jsonstring); // 必须释放!
//         } else {
//             fprintf(stderr, "<错误：JSON打印失败>\n");
//         }
//     } else {
//         fprintf(stderr, "<错误：root对象为空>\n");
//     }
    

//     // 设置POST数据
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(post_data));
//     // 设置响应回调
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
//     // 设置超时
//     curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    
//     // 执行请求
//     res = curl_easy_perform(curl);

//     // 检查不支持的协议
//     if(res == CURLE_UNSUPPORTED_PROTOCOL) {
//         fprintf(stderr, "<cURL错误: 不支持的协议 - URL: %s>\n", "https://api.deepseek.com/chat/completions");
        
//         // 获取支持的协议列表
//         curl_version_info_data *ver_info = curl_version_info(CURLVERSION_NOW);
//         if(ver_info && ver_info->protocols) {
//             fprintf(stderr, "<支持的协议列表: >\n");
//             const char * const *proto;
//             for(proto = ver_info->protocols; *proto; proto++) {
//                 fprintf(stderr, "- %s\n", *proto);
//             }
//         }
//     } else if(res != CURLE_OK) {
//         fprintf(stderr, "<cURL错误: %s>\n", curl_easy_strerror(res));
//     }
    
//     // 检查HTTP状态码
//     curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    
//     // 打印原始响应
//     printf("原始API响应: %s\n", chunk.memory ? chunk.memory : "(NULL)");
    
//     // 清理cURL资源
//     // 使用全局变量不删除root
//     curl_easy_cleanup(curl);
//     curl_slist_free_all(headers);
//     // cJSON_Delete(root);
//     free(post_data);
    
//     // 调试信息
//     printf("\n----- API请求详情 -----\n");
//     printf("端点: https://api.deepseek.com/chat/completions\n");
//     printf("模型: deepseek-chat\n");
//     printf("提示: %s\n", prompt);
//     printf("状态码: %ld\n", http_code);
    
//     if(res != CURLE_OK) {
//         fprintf(stderr, "<cURL错误: %s>\n", curl_easy_strerror(res));
//         curl_global_cleanup();
//         return api_response;
//     }
    
//     // 检查HTTP状态码
//     if(http_code != 200) {
//         fprintf(stderr, "<API错误: HTTP %ld>\n", http_code);
//         if(chunk.memory) {
//             printf("原始响应: %s\n", chunk.memory);
            
//             cJSON *error_json = cJSON_Parse(chunk.memory);
//             if(error_json) {
//                 cJSON *error_obj = cJSON_GetObjectItem(error_json, "error");
//                 if(error_obj) {
//                     cJSON *message = cJSON_GetObjectItem(error_obj, "message");
//                     cJSON *code = cJSON_GetObjectItem(error_obj, "code");
                    
//                     if(cJSON_IsString(message)) {
//                         fprintf(stderr, "<错误信息: %s>\n", message->valuestring);
//                     }
//                     if(cJSON_IsString(code)) {
//                         fprintf(stderr, "<错误代码: %s>\n", code->valuestring);
//                     }
//                 }
//                 cJSON_Delete(error_json);
//             }else
//             {
//                 fprintf(stderr, "<错误：【cJSON_parse】(错误码：%d, 详情：%s)>\n", errno, strerror(errno));
//             }
//         }
//         curl_global_cleanup();
//         return api_response;
//     }
    
//     curl_global_cleanup();
    
//     // 检查chunk.memory
//     if (!chunk.memory || !chunk.size) {
//         fprintf(stderr, "<API返回空响应>\n");
//         if (chunk.memory) free(chunk.memory);
//         return api_response;
//     }
//     // 解析API响应
//     cJSON *response_json = cJSON_Parse(chunk.memory);
    
//     if (!response_json) {
//         fprintf(stderr, "<错误：【cJSON_parse】(错误码：%d, 详情：%s,行号：%d)>\n", errno, strerror(errno), __LINE__);
//         const char *error_ptr = cJSON_GetErrorPtr();
//         if (error_ptr) fprintf(stderr, "<JSON解析错误: %s>\n", error_ptr);
//         fprintf(stderr, "原始响应: %s\n", chunk.memory);
//         if (chunk.memory) free(chunk.memory);
//         return api_response;
//     }
    
//     // 提取令牌使用信息
//     cJSON *usage = cJSON_GetObjectItem(response_json, "usage");
//     if (usage) {
//         cJSON *prompt_tokens = cJSON_GetObjectItem(usage, "prompt_tokens");
//         cJSON *completion_tokens = cJSON_GetObjectItem(usage, "completion_tokens");
//         cJSON *total_tokens = cJSON_GetObjectItem(usage, "total_tokens");
        
//         if (cJSON_IsNumber(prompt_tokens)) api_response.prompt_tokens = prompt_tokens->valueint;
//         if (cJSON_IsNumber(completion_tokens)) api_response.completion_tokens = completion_tokens->valueint;
//         if (cJSON_IsNumber(total_tokens)) api_response.total_tokens = total_tokens->valueint;
//     }
    
//     // 提取回复内容
//     cJSON *choices = cJSON_GetObjectItem(response_json, "choices");
//     if (cJSON_IsArray(choices) && cJSON_GetArraySize(choices) > 0) {
//         cJSON *first_choice = cJSON_GetArrayItem(choices, 0);
//         cJSON *message = cJSON_GetObjectItem(first_choice, "message");
//         cJSON *content = cJSON_GetObjectItem(message, "content");
        
//         if (cJSON_IsString(content) && content->valuestring != NULL) {
//             api_response.content = strdup(content->valuestring);
//         }
//     }
    
    
//     cJSON_Delete(response_json);
//     if(chunk.memory) {
//         free(chunk.memory);  // 确保只释放一次
//         chunk.memory = NULL; // 防止重复释放
//     }
//     return api_response;
// }


 struct APIResponse call_deepseek(const char *api_key, const char *prompt) {

    #if 0 /* 函数入口栈指针检查 */
    void *entry_sp = get_stack_pointer();
    printf("[函数入口栈指针: %p]\n", entry_sp);
    
    // 计算栈使用量
    static void *last_pre_call_sp = NULL;
    if (last_pre_call_sp) {
        uintptr_t stack_used = (uintptr_t)last_pre_call_sp - (uintptr_t)entry_sp;
        printf("[栈使用量: %" PRIuPTR " 字节]\n", stack_used);
    }
    last_pre_call_sp = entry_sp;
    #endif 

    // 原有代码
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk = {0};
    long http_code = 0;
    struct APIResponse api_response = {0};

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    // curl_easy_reset(curl);
    if(!curl) {
        fprintf(stderr, "<无法初始化cURL>\n");
        return api_response;
    }


    // 设置请求头
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    char auth_header[256];
    snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", api_key);
    headers = curl_slist_append(headers, auth_header);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    
    // 构建root请求体--使用函数代替，并设为全局变量，在事件层初始化
    CompleteRequestBodyroot();

    // 使用全局messages对象并进行构造添加
    MakeupUserMessageObj(messages, prompt);

    /* -----------------------------------------------------*/
    cJSON_AddItemToObject(root, "messages", messages);

    char *post_data = cJSON_PrintUnformatted(root);   // 有疑点，如何安置？？？
    if (!post_data) {
        fprintf(stderr, "错误: 无法生成JSON请求体\n");
        return api_response;
    }

    // 打印最终cjson对象数据
    if (root) {
        char *jsonstring = cJSON_Print(root);
        if (jsonstring) {
            printf("%s\n", jsonstring);
            free(jsonstring); // 必须释放!
        } else {
            fprintf(stderr, "<错误：JSON打印失败>\n");
        }
    } else {
        fprintf(stderr, "<错误：root对象为空>\n");
    }
    
    // 设置API端点,目标URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.deepseek.com/chat/completions");
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
        fprintf(stderr, "<cURL错误: 不支持的协议 - URL: %s>\n", "https://api.deepseek.com/chat/completions");
        
        // 获取支持的协议列表
        curl_version_info_data *ver_info = curl_version_info(CURLVERSION_NOW);
        if(ver_info && ver_info->protocols) {
            fprintf(stderr, "<支持的协议列表: >\n");
            const char * const *proto;
            for(proto = ver_info->protocols; *proto; proto++) {
                fprintf(stderr, "- %s\n", *proto);
            }
        }
    } else if(res != CURLE_OK) {
        fprintf(stderr, "<cURL错误: %s>\n", curl_easy_strerror(res));
    }
    
    // 检查HTTP状态码
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    
    // 打印原始响应
    printf("原始API响应: %s\n", chunk.memory ? chunk.memory : "(NULL)");
    
    // 清理cURL资源
    // 使用全局变量不删除root
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    // cJSON_Delete(root);
    free(post_data);
    
    #if 0   /* 调试信息 */
    printf("\n----- API请求详情 -----\n");
    printf("端点: https://api.deepseek.com/chat/completions\n");
    printf("模型: deepseek-chat\n");
    printf("提示: %s\n", prompt);
    printf("状态码: %ld\n", http_code);
    #endif

    if(res != CURLE_OK) {
        fprintf(stderr, "<cURL错误: %s>\n", curl_easy_strerror(res));
        curl_global_cleanup();
        return api_response;
    }
    
    // 检查HTTP状态码
    if(http_code != 200) {
        fprintf(stderr, "<API错误: HTTP %ld>\n", http_code);
        if(chunk.memory) {
            printf("原始响应: %s\n", chunk.memory);
            
            cJSON *error_json = cJSON_Parse(chunk.memory);
            if(error_json) {
                cJSON *error_obj = cJSON_GetObjectItem(error_json, "error");
                if(error_obj) {
                    cJSON *message = cJSON_GetObjectItem(error_obj, "message");
                    cJSON *code = cJSON_GetObjectItem(error_obj, "code");
                    
                    if(cJSON_IsString(message)) {
                        fprintf(stderr, "<错误信息: %s>\n", message->valuestring);
                    }
                    if(cJSON_IsString(code)) {
                        fprintf(stderr, "<错误代码: %s>\n", code->valuestring);
                    }
                }
                cJSON_Delete(error_json);
            }else
            {
                fprintf(stderr, "<错误：【cJSON_parse】(错误码：%d, 详情：%s)>\n", errno, strerror(errno));
            }
        }
        curl_global_cleanup();
        return api_response;
    }
    
    curl_global_cleanup();
    
    // 检查chunk.memory
    if (!chunk.memory || !chunk.size) {
        fprintf(stderr, "<API返回空响应>\n");
        if (chunk.memory) free(chunk.memory);
        return api_response;
    }

    // 解析API响应
    cJSON *response_json = cJSON_Parse(chunk.memory);
    
    if (!response_json) {
        fprintf(stderr, "<错误：【cJSON_parse】(错误码：%d, 详情：%s,行号：%d)>\n", errno, strerror(errno), __LINE__);
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr) fprintf(stderr, "<JSON解析错误: %s>\n", error_ptr);
        fprintf(stderr, "原始响应: %s\n", chunk.memory);
        if (chunk.memory) free(chunk.memory);
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
    if(chunk.memory) {
        free(chunk.memory);  // 确保只释放一次
        chunk.memory = NULL; // 防止重复释放
    }
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

    // 设置魔术字
    session->magic = SESSION_MAGIC;  // 添加魔术字

    session->api_key = get_api_key();
    session->total_prompt_tokens = 0;
    session->total_completion_tokens = 0;
    session->total_all_tokens = 0;

    return session;
}

/*********************
 * @brief 销毁会话
 * @param  session 
 *************************************************/
void deepseek_destroy_session(DeepSeekSession *session) {
    if (!session) return;
    // free(session->api_key);
    if (session->api_key) {
        // 安全擦除API密钥内存
        size_t len = strlen(session->api_key);
        volatile char *p = session->api_key;
        while (len--) {
            *p++ = 0;
        }
        free(session->api_key);
    }
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
//     // 在原有检查前添加魔术字验证
// #define SESSION_MAGIC 0x5E5510DE
    
    if (session == NULL) {
        fprintf(stderr, "CRITICAL: Session pointer is NULL\n");
        return NULL;
    }
    // 魔术字验证
    if (session->magic != SESSION_MAGIC) {
        fprintf(stderr, "<CRITICAL: Session magic mismatch! Expected 0x%X, got 0x%X>\n",
                SESSION_MAGIC, session->magic);
        fprintf(stderr, "Memory dump at %p:\n", session);
        // 打印session指针附近内存
        return NULL;
    }
    // 添加详细的调试信息
    printf("Session pointer: %p\n", (void*)session);
    if (session) {
        printf("API key: %s\n", session->api_key ? "VALID" : "NULL");
    } else {
        printf("<Session is NULL>\n");
    }

    // 添加安全检查
    if (!session || !session->api_key) {
        fprintf(stderr, "<错误: 会话未初始化或API密钥无效>\n");
        return NULL;
    }
    if (!session || !message) 
    {
        return NULL;
    }

    // 调用前栈指针检查
    void *pre_call_sp = get_stack_pointer();
    printf("调用前栈指针: %p\n", pre_call_sp);
    struct APIResponse api_res = call_deepseek(session->api_key, message);

    if (api_res.content) {
        // 更新会话令牌计数
        session->total_prompt_tokens += api_res.prompt_tokens;
        session->total_completion_tokens += api_res.completion_tokens;
        session->total_all_tokens += api_res.total_tokens;
        
        // 设置输出参数
        if (prompt_tokens) *prompt_tokens = api_res.prompt_tokens;
        if (completion_tokens) *completion_tokens = api_res.completion_tokens;
        if (total_tokens) *total_tokens = api_res.total_tokens;
        
        return api_res.content;
    }
    return NULL;
}

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
 * @note 该函数有些问题！！！
 *************************************************/
void get_full_text_input(char *dest, size_t dest_size) {
    // 清空缓冲区
    memset(dest, 0, dest_size);
    // 获取文本区域内容指针
    const char *text = lv_textarea_get_text(ui_TextArea1);
    if (!text) {
        dest[0] = '\0';
        return;
    }
    
    size_t text_len = strlen(text); // 计算实际文本长度（包括空格）
    
    // 安全复制文本（防止缓冲区溢出）
    size_t copy_len = text_len < dest_size - 1 ? text_len : dest_size - 1;
    strncpy(dest, text, copy_len);
    dest[copy_len] = '\0'; // 确保字符串终止
    
    // 调试检查
    if (text_len >= dest_size - 1) {
        lv_label_set_text(ui_AILabel, "输入过长已截断!");
    }

    // 移除末尾的换行符（如果有）
    char *newline = strchr(dest, '\n');
    if (newline) *newline = '\0';

    // 检查保护区域
    check_guard_zone();
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
        // 添加会话检查
        if (!session) {
            fprintf(stderr, "<错误: 会话未初始化，请先长按LOGO创建会话>\n");
            return -1;
        }

        // 判断键盘的状态，是否隐藏，若未隐藏，代表动画执行完毕，浮出，可以开始输入
        if( !lv_obj_has_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN)) {
            //  char input[1024] = {0};  // 本地声明，避免全局变量
            printf("-inputlogo被按下!-\n");
            get_full_text_input(input, sizeof(input));
            printf("【 input = %s 】\n", input);
            if( strcmp(input, "exit") == 0 )
            {
                // 清理资源
                deepseek_destroy_session(session);
                printf("退出！\n");
                return 0; 
            }
            printf("正在查询DeepSeek API...\n");    

            // 在调用前打印栈指针
            void *stack_ptr;
            asm("mov %%rsp, %0" : "=r"(stack_ptr));  // x86_64
            printf("调用前栈指针: %p\n", stack_ptr);

            char* local_response = deepseek_send_message(
                session, 
                input,  
                &prompt_tokens,
                &completion_tokens,
                &total_tokens
            );

            if(local_response) {
                // printf("\n--- DeepSeek回复 ---\n%s\n", local_response);
                printf("\n--- DeepSeek回复 ---\n");
                int written = snprintf(dpOut, sizeof(dpOut), "%s", local_response);

                // 检查是否被截断
                if(written >= (int)sizeof(dpOut)) {
                    fprintf(stderr, "警告: AI响应被截断 (原始长度: %d, 缓冲区大小: %zu)\n", 
                            written, sizeof(dpOut));
                    
                    // 可选：在截断处添加省略号
                    size_t last_pos = sizeof(dpOut) - 4; // 保留空间给 "..."
                    if(last_pos > 0) {
                        strcpy(dpOut + last_pos, "...");
                    }
                }

                printf("dpOut = %s\n", dpOut);
                lv_label_set_text(ui_AILabel, dpOut);
                // 将AI输出dpOut构造并添加到messages数组中
                MakeupAIReplyMessageObj(messages, dpOut);
                char * jsonstring = cJSON_Print(root);
                printf("jsonstring = %s\n", jsonstring);
                // char *json_str = cJSON_Print(messages);
                // if (json_str) {
                //     printf("messages = %s\n", json_str);
                //     free(json_str);
                // } else {
                //     printf("ERROR: Failed to print messages!\n");
                // }

                // 显示令牌使用
                print_token_usage(prompt_tokens, completion_tokens, total_tokens);
                free(local_response);
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

