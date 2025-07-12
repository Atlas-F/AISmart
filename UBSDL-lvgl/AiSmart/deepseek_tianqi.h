#ifndef _DEEPSEEK_TIANQI_H_
#define _DEEPSEEK_TIANQI_H_


// 定义内存结构体，用于存储HTTP响应数据
struct WeatherMemoryStruct {
    char *memory;
    int size;
};

// 定义数据结构体，用于存储解析响应后需要传出的数据
struct WeatherResultStruct
{
    char * cityName;
    char * country;
    char * weatherText;
    char * tempurature;
    char * weathercode;
};

// void InitWeatherResult()
// {
//     // 初始化结果结构体
//     struct WeatherResultStruct weatherResult ;
//     weatherResult.cityName = malloc(16);
//     weatherResult.weatherText = malloc(16);
//     weatherResult.tempurature = malloc(8);

// }

// 回调函数用于存储HTTP响应数据
static int write_callback(void *contents, int size, int nmemb, void *userp) ;

// 获取天气函数
void get_weather(const char *location) ;




#endif