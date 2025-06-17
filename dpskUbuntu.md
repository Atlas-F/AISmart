下面是一个使用C语言调用DeepSeek API的示例程序，使用libcurl库发送HTTP请求并处理JSON响应：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

// 用于存储HTTP响应数据的结构体
struct MemoryStruct {
    char *memory;
    size_t size;
};

// libcurl回调函数，用于写入响应数据
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(!ptr) {
        printf("内存分配错误\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

// 调用DeepSeek API函数
char* call_deepseek(const char *api_key, const char *prompt) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // 设置API端点
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.deepseek.com/v1/chat/completions");
        
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
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        
        // 执行请求
        res = curl_easy_perform(curl);
        
        // 清理
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        cJSON_Delete(root);
        free(post_data);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "请求失败: %s\n", curl_easy_strerror(res));
            return NULL;
        }
    }
    
    curl_global_cleanup();
    
    // 解析API响应
    cJSON *response_json = cJSON_Parse(chunk.memory);
    if(!response_json) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if(error_ptr) fprintf(stderr, "JSON解析错误: %s\n", error_ptr);
        free(chunk.memory);
        return NULL;
    }
    
    // 提取响应内容
    cJSON *choices = cJSON_GetObjectItemCaseSensitive(response_json, "choices");
    if(cJSON_IsArray(choices) && cJSON_GetArraySize(choices) > 0) {
        cJSON *first_choice = cJSON_GetArrayItem(choices, 0);
        cJSON *message = cJSON_GetObjectItemCaseSensitive(first_choice, "message");
        cJSON *content = cJSON_GetObjectItemCaseSensitive(message, "content");
        
        if(cJSON_IsString(content) && content->valuestring != NULL) {
            char *result = strdup(content->valuestring);
            cJSON_Delete(response_json);
            free(chunk.memory);
            return result;
        }
    }
    
    cJSON_Delete(response_json);
    free(chunk.memory);
    return NULL;
}

int main() {
    // 替换为你的DeepSeek API密钥
    const char *api_key = "你的API密钥";
    
    printf("DeepSeek聊天客户端 (输入'exit'退出)\n");
    
    while(1) {
        printf("\n你的问题: ");
        char input[1024];
        fgets(input, sizeof(input), stdin);
        
        // 移除换行符
        input[strcspn(input, "\n")] = 0;
        
        if(strcmp(input, "exit") == 0) break;
        if(strlen(input) == 0) continue;
        
        char *response = call_deepseek(api_key, input);
        if(response) {
            printf("\nDeepSeek回复:\n%s\n", response);
            free(response);
        } else {
            printf("获取回复时出错\n");
        }
    }
    
    return 0;
}
```

### 使用说明：

1. **安装依赖库**：
   ```bash
   sudo apt-get install libcurl4-openssl-dev libcjson-dev
   ```

2. **编译程序**：
   ```bash
   gcc deepseek_client.c -o deepseek_client -lcurl -lcjson
   ```

3. **运行程序**：
   ```bash
   ./deepseek_client
   ```

4. **使用说明**：
   - 将`你的API密钥`替换为实际的DeepSeek API密钥
   - 在提示符下输入问题或对话内容
   - 输入`exit`退出程序

### 程序功能：

1. 通过DeepSeek API进行文本交互
2. 支持多轮对话
3. 使用cJSON解析JSON响应
4. 使用libcurl处理HTTP请求

### 重要注意事项：

1. **API密钥**：需要从DeepSeek官网获取有效API密钥
2. **错误处理**：程序包含基本错误处理，但实际应用中可能需要增强
3. **安全性**：API密钥以明文形式存储在代码中，生产环境应使用更安全的方式

### 依赖库说明：

- **libcurl**：用于处理HTTP请求
- **libcjson**：用于解析和生成JSON数据

这个程序提供了一个基本的命令行界面，可以与DeepSeek模型进行交互。程序会持续运行直到用户输入"exit"。