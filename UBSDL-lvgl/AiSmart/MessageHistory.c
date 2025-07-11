/*********************
 * @file MessageHistory.c
 * @brief 消息历史上下文管理
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-07-09
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "MessageHistory.h"


// 对话历史结构体
// MessageHistory * meghistory = NULL;
MessageHistory * meghistory = NULL;

/*********************
 * @brief 初始化分配内存
 * @param  history 
 * @details 使用一次性分配内存的方式
 *************************************************/
MessageHistory* InitMessageHistory()
{
    if( meghistory && meghistory->initialized )
    {
        return meghistory;
    }
    // 计算总内存大小
    size_t total_size = 
        sizeof(MessageHistory) +                 // 结构体本身
        (CONVERSATIONMEGCAP * MAX_MSG_LEN) +     // 对话消息数组内存
        MAX_MSG_LEN +                            // megcontent内存
        MAX_HISTORY_LEN;                         // WholeHistoryMessage内存
    
    // 一次性分配整个内存块
    void *memory_block = malloc(total_size);
    if (!memory_block) 
    {
        fprintf(stderr, "错误：[内存分配失败](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        return NULL;
    }
    
    // 将内存块清零
    memset(memory_block, 0, total_size);
    
    // 设置结构体指针
    meghistory = (MessageHistory*)memory_block;
    
    // 计算对话消息数组的起始位置
    char *msg_ptr = (char*)(meghistory + 1); // 紧接在结构体之后
    
    // 初始化对话消息数组
    for (int i = 0; i < CONVERSATIONMEGCAP; i++) {
        meghistory->conversationMessage[i] = msg_ptr;
        msg_ptr[0] = '\0';  // 初始化为空字符串
        msg_ptr += MAX_MSG_LEN;
    }
    
    // 初始化megcontent
    meghistory->megcontent = msg_ptr;
    meghistory->megcontent[0] = '\0';
    msg_ptr += MAX_MSG_LEN;
    
    // 初始化WholeHistoryMessage
    meghistory->WholeHistoryMessage = msg_ptr;
    meghistory->WholeHistoryMessage[0] = '\0';

    meghistory->initialized = true;
    
    return meghistory;

    // 什么是全局单例？
    // 什么是魔术字？
    
}

/*********************
 * @brief 释放结构体内存
 * @param  hist 
 *************************************************/
void free_message_history_single(MessageHistory *meghistory) {
    if (meghistory) {
        // 因为是一次性分配，释放结构体指针即可
        free(meghistory);
    }
}

/*********************
 * @brief 判断消息历史数组是否为空
 * @param  meghistory 
 * @return int 
 *          -1 数组已满
 *          > 0 第一个空位
 *************************************************/
int JudgeFull(MessageHistory * meghistory)
{
    if(!meghistory)
    {
        fprintf(stderr, "错误：[meghistoryNULL](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        pause();
    }
    for (int i = 0; i < CONVERSATIONMEGCAP; i++)
    {
        if( meghistory->conversationMessage[i][0] == '\0' && i <= CONVERSATIONMEGCAP-1 )
        {
            return i;
        }
    }
    if(meghistory->conversationMessage[CONVERSATIONMEGCAP-1][0] != '\0')
        return -1;  // 满

}

/*********************
 * @brief 将消息添加进历史队列
 * @param  meghistory 
 * @param  megcontent 
 * @return int 
 *          -1 添加失败
 *          > 0 返回该消息存储在数组中的序列号
 *************************************************/
int DeepseekAddMessage(MessageHistory * meghistory, char *megcontent)
{
    if(!meghistory)
    {
        fprintf(stderr, "错误：[meghistoryNULL](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        pause();
    }
    int index = JudgeFull(meghistory);
    if(index < 0)  
    {
        fprintf(stderr, "错误：[JudgeFull](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        return -1;
    }

    // 计算源字符串长度（包含终止符）
    int len = strlen(megcontent) + 1;
    // 分配刚好足够的内存
    // meghistory->conversationMessage[index] = (char *)malloc(len);
    if(!meghistory->conversationMessage[index])
    {
        exit(EXIT_FAILURE);
    }
    // 使用 snprintf 复制（确保不溢出）
    int ret = snprintf(meghistory->conversationMessage[index], MAX_MSG_LEN, "%s", megcontent);
    if(ret < 0)
    {
        fprintf(stderr, "错误：[snprintf](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
    }
    // 饭hi做i后一个填充序号
    return index; 
}

/*********************
 * @brief 整合消息历史为一个字符串
 * @param  meghistory 
 * @return char* 
 *************************************************/
char * MessageIntegration(MessageHistory * meghistory)
{
    if(!meghistory)
    {
        fprintf(stderr, "错误：[meghistoryNULL](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        pause();
    }
    // 重置消息历史
    meghistory->WholeHistoryMessage[0] = '\0';

    for(int i = 0; i < CONVERSATIONMEGCAP; i++)
    {
        // 计算源字符串长度（包含终止符）
        int len = strlen(meghistory->conversationMessage[i]) + 1;
        // 分配刚好足够的内存
        // 使用 snprintf 复制（确保不溢出）
        strncat(meghistory->WholeHistoryMessage, meghistory->conversationMessage[i], len);
        
        // if(ret < 0)
        // {
        //     fprintf(stderr, "错误：[strncat](ERRNO:%d, DETAILS:%s, LINE:%d)\n", errno, strerror(errno), __LINE__);
        // }
    }
    printf("strncat 拼接后字符串：%s\n", meghistory->WholeHistoryMessage);
}

/*********************
 * @brief 清空消息历史
 * @param  session 
 * @param  meghistory 
 *************************************************/
int DeepseekClearMessage(MessageHistory * meghistory)
{
    


}
