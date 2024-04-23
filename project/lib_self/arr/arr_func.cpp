#include "arr_func.h"

#include<iostream>

static int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
static int arr_len = sizeof(arr) / sizeof(arr[0]);

void arr_func_test(void)
{
    int* p = arr;
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", *p);
        p++;
    }
    std::cout << std::endl;
}