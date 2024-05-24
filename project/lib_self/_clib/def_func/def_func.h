#ifndef __DEF_FUNC_H_
#define __DEF_FUNC_H_


#ifdef __cplusplus
extern "C"{
#endif

void default_param_func_aa_func(int a, int b, int c, int d);              //函数原型

#define default_param_func_aa4(a, b, c, d)    default_param_func_aa_func(a, b, c, d)    // 如果有4个参数，则调用default_param_func_aa_4
#define default_param_func_aa3(a, b, c)       default_param_func_aa_func(a, b, c, 0)    // 如果有三个参数，则调用default_param_func_aa_3；否则调用default_param_func_aa_2
#define default_param_func_aa2(a, b)          default_param_func_aa_func(a, b, 0, 0)
#define default_param_func_aa1(a)             default_param_func_aa_func(a, 0, 0, 0)


#define _default_param_func_aa(arg1, arg2, arg3, arg4, FUNC, ...) FUNC      

// 确定参数个数，以积极对应参数个数所调用的函数形式，个数多的在前
// __VA_ARGS__: 这是一个特殊的宏参数，表示宏调用时除去前面已经命名的参数之外的所有可变数量参数。
#define default_param_func_aa(...)  \
            _default_param_func_aa( \
            __VA_ARGS__, \
            default_param_func_aa4, \
            default_param_func_aa3, \
            default_param_func_aa2, \
            default_param_func_aa1  \
            )(__VA_ARGS__)        // 调用此处方能实现默认参数



void default_param_func_test();

#ifdef __cplusplus
}
#endif


#endif


