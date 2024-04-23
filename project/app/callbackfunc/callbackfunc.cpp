#include <iostream>
#include <vector>
#include <string>
#include "callbackfunc.h"

using namespace std;

void show(void(*pf)(int),int b)
{
    cout<<"表白之前的准备工作已完成。\r\n";
    pf(b);
    cout<<"表白之后的收尾工作已完成。\r\n";
}

void zs(int i)
{
    cout<<"张三向女神表白a\r\n";
}

void ls(int i)
{
    cout<<"李四向女神表白a\r\n";
}

