#include <stdio.h>
#include <string.h>

#include "callbackfunc.h"

void show(void(*pf)(int),int b)
{
    printf("表白之前的准备工作已完成。\r\n");
    pf(b);
    printf("表白之后的收尾工作已完成。\r\n");
}

void zs(int i)
{
    printf("张三向女神表白a\r\n");
}

void ls(int i)
{
    printf("李四向女神表白a\r\n");
}

