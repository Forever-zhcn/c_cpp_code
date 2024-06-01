#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // 包含 sleep 函数的头文件
#include <time.h>

#include "hello.h"
#include "fileio.h"
#include "cJSON.h"
#include "cJSON_test.h"
#include "time_test.h"
#include "WString_test.h"



#include "WString.h"

static void main_test_func()
{
    // String str_demo = "hello world!";
    // printf("%s\r\n", str_demo.c_str());
    WString_test();

    // hello_test();

    // cJSON_test();

    // testtest();

    // char ch[] = "+IPD,113:0o@/sys/a1vF4yG4xrh/forever-240223-111111/thing/event/property/post";

    // char *ptrIPD = strchr(ch, ':');

    // printf("ptrIPD:\r\n%s\r\n", ptrIPD);

    // time_test();
    // usleep(1000 * 1000);
}


int main(int argc, const char* argv[])
{
    // printf("你好，世界\r\n");
    main_test_func();

    // while(1)
    // {
        
    // }

    

    // system("pause");
    return 0;
}





