/*********************
 * @file MessageHistory.h
 * @brief 
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-07-09
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/
#ifndef _MESSAGEHISTORY_H_
#define _MESSAGEHISTORY_H_


#define CONVERSATIONMEGCAP 100
#define MAX_MSG_LEN 256        // 单条消息最大长度
#define MAX_HISTORY_LEN 4096   // 完整历史消息最大长度

// 对话历史
/*********************
 * @brief 设计一个对话历史结构体，将对话历史 消息都包含进去，然后
 * 在输入内容后，将文本添加进结构体数组，再将所有的内容发送给AI
 *************************************************/
typedef struct history
{
    bool initialized;         // 初始化标志
    char * conversationMessage[CONVERSATIONMEGCAP];    // 对话内容数组
    char * megcontent;  // 消息内容
    char * WholeHistoryMessage; // 完整消息历史，整合内容

    // // 内存块指针（用于一次性释放）
    // void* memory_block;
} MessageHistory;

/*********************
 * @brief 初始化
 * @param  history 
 *************************************************/
MessageHistory* InitMessageHistory( );

/*********************
 * @brief 判断消息数组是否为空
 * @param  meghistory 
 * @return int 
 *************************************************/
int JudgeFull(MessageHistory * meghistory);

/*********************
 * @brief 将消息添加进历史队列
 *************************************************/
int DeepseekAddMessage(MessageHistory * meghistory, char *megcontent);

/*********************
 * @brief 整合消息历史为一个字符串
 *************************************************/
char * MessageIntegration(MessageHistory * meghistory);

/*********************
 * @brief 清空消息历史
 *************************************************/
int DeepseekClearMessage(MessageHistory * meghistory);


#endif