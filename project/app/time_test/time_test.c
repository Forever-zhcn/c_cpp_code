#include "time_test.h"

#include <stdio.h>
#include <time.h>


void time_test()
{
    // 获取当前时间 前面的时间戳表示获取到的距今1900年的秒数 2208988800表示70年的秒数
    time_t current_time = 0xE9D842E2 - 2208988800;
    // time_t current_time;
    // time(&current_time);

    // 将时间转换为时间戳
    printf("Timestamp1: %ld\n", (long)current_time);

    // printf("Formatted time1: %lld-%lld-%lld %lld:%lld:%lld\n", 
    //             current_time / 31556736 + 1970, (current_time / 3600) % 24+8, );

    printf("Formatted time1: %lld\n", (current_time / 3600) % 24);


    // 将时间戳转换为结构体 tm 的形式 此处是零时区的时间
    struct tm *tm_info = gmtime(&current_time);
    tm_info->tm_hour += 8;

    // 将结构体 tm 中的时间信息格式化为字符串（中国格式）
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", tm_info);

    // 输出格式化后的时间字符串
    printf("Formatted time: %s\n", buffer);

    // 将结构体 tm 中的时间信息格式化为字符串（欧洲格式）
    strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", tm_info);

    // // 输出格式化后的时间字符串
    // printf("Formatted time (European format): %s\n", buffer);
}
