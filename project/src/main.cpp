#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // 包含 sleep 函数的头文件

#include "hello.h"
#include "fileio.h"
#include "mystr.h"
#include "cJSON.h"
#include "cJSONTest.h"
#include "WString.h"


int main(int argc, const char* argv[])
{
    
    // char str[] = "hello:world";

    // const char* str1 = strstr(str, "llo:");

    // printf("你好，世界\r\n");

    // printf("%s\r\n", str1);

    // const char *devSubtopic[] = {"/sys/a1vF4yG4xrh/forever-240223-111111/thing/service/property/set"};

    // #define devSubtopic "/sys/a1vF4yG4xrh/forever-240223-111111/thing/service/property/set"

    // printf("devSubtopic:\r\n%s\r\n\r\n", devSubtopic);

    // const char *devSubtopic1 = devSubtopic;
    // const char **devSubtopic11 = &devSubtopic1;

    // const char **devSubtopic11 = (char *)devSubtopic;

    // printf("devSubtopic1:\r\n%s\r\n\r\n", devSubtopic1);

    // printf("devSubtopic11:\r\n%s\r\n\r\n", *devSubtopic11);


    // printf("0x%02x\n", atoi("14"));
    // printf("0x%02x\n", atoi("15"));

    // String str_demo = "hello world!";
    // printf("%s\r\n", str_demo.c_str());

    // hello_test();

    // printf("%s\r\n", (8/8 == 8.5/8) ? "true":"false");


    while(1)
    {
        printf((String("Work hard") == String("promotion and pay increase")) ? "true" : "false");
        printf("\r\n");
        usleep(1000 * 1000);
    }


    

    // system("pause");
    return 0;
}





