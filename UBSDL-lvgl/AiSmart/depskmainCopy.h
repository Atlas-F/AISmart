#ifndef _DEPSKMAINCOPY_H_
#define _DEPSKMAINCOPY_H_

#include "lvgl/lvgl.h"

#define CONVERSATIONMEGCAP 10


// extern DeepSeekSession *session;    // 声明外部变量

// ================== 数据结构定义 ==================


// 存储HTTP响应
struct MemoryStruct {
    char *memory;
    size_t size;
};

// 存储API响应内容
struct APIResponse {
    char *content;
    int prompt_tokens;
    int completion_tokens;
    int total_tokens;
};

// 会话上下文
typedef struct {
    char *api_key;
    int total_prompt_tokens;
    int total_completion_tokens;
    int total_all_tokens;
    int magic;
} DeepSeekSession;






// ================== 封装函数声明 ==================
/*********************
 * @brief libcurl回调函数
 * @param  contents 
 * @param  size 
 * @param  nmemb 
 * @param  userp 
 * @return size_t 
 *************************************************/
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) ;

/*********************
 * @brief Get the api key object
 * @return char* 
 *************************************************/
char* get_api_key();

/*********************
 * @brief 调用DeepSeek API
 * @param  api_key 
 * @param  prompt 
 * @return struct APIResponse 
 *************************************************/
struct APIResponse call_deepseek(const char *api_key, const char *prompt) ;

/*********************
 * @brief // 显示令牌使用信息
 * @param  prompt_tokens 
 * @param  completion_tokens 
 * @param  total_tokens 
 *************************************************/
void print_token_usage(int prompt_tokens, int completion_tokens, int total_tokens) ;

/*********************
 * @brief 创建新会话
 * @param  api_key 
 * @return DeepSeekSession* 
 *************************************************/
DeepSeekSession* deepseek_create_session(const char *api_key);

/*********************
 * @brief 销毁会话
 * @param  session 
 *************************************************/
void deepseek_destroy_session(DeepSeekSession *session);

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
);

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
);

/*********************
 * @brief Get the full text input object
 * @param  dest 
 * @param  dest_size 
 * @note 使用lv_textarea_get_text可能无法获取全部文本内容，只能获取单个单词
 *************************************************/
void get_full_text_input(char *dest, size_t dest_size) ;

/*********************
 * @brief 创建会话函数，其实没啥用
 * @param  e 
 * @return int 
 *************************************************/
int depmainlong(lv_event_t * e) ;

/*********************
 * @brief 封装会话函数
 * @param  e 
 * @return int 
 *************************************************/
int depmaintalk(lv_event_t * e);

#endif