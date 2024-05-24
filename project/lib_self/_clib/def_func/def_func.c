#include "def_func.h"

#include <stdio.h>

// 实际的函数
void default_param_func_aa_func(int a, int b, int c, int d) {
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
}



void default_param_func_test()
{
    default_param_func_aa(1);
    default_param_func_aa(1,2);
    default_param_func_aa(1,2,3);
    default_param_func_aa(1,2,3,4);
}




