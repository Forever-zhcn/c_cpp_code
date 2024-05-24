#include "bubble_sort.h"

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS 1



static int arr[10] = { 0, 3, 5, 2, 9, 6, 8, 1, 4, 7 };
static int arr_len = sizeof(arr) / sizeof(arr[0]);


void bubble_test(void)
{
    // 输出数组原始内容
    printf("Original array\r\n");
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\r\n");

    // 冒泡排序
    for (int i = 0; i < arr_len - 1; i++)
    {
        for (int j = 0; j < arr_len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 输出排序后的数组内容
    printf("Sorted array: \r\n");
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\r\n");

}