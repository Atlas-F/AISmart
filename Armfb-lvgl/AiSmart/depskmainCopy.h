#ifndef _DEPSKMAINCOPY_H_
#define _DEPSKMAINCOPY_H_

#include "lvgl/lvgl.h"
// #include <curl/curl.h>


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
} DeepSeekSession;



static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) ;

char* get_api_key();

struct APIResponse call_deepseek(const char *api_key, const char *prompt) ;

void print_token_usage(int prompt_tokens, int completion_tokens, int total_tokens) ;

DeepSeekSession* deepseek_create_session(const char *api_key);

void deepseek_destroy_session(DeepSeekSession *session);

char* deepseek_send_message(
    DeepSeekSession *session, 
    const char *message,
    int *prompt_tokens,  // 返回本次提示令牌
    int *completion_tokens,  // 返回本次完成令牌
    int *total_tokens    // 返回本次总令牌
);

void deepseek_get_token_stats(
    DeepSeekSession *session,
    int *total_prompt,
    int *total_completion,
    int *total_all
);

void get_full_text_input(char *dest, size_t dest_size) ;


int depmainlong(lv_event_t * e) ;


int depmaintalk(lv_event_t * e);

#endif