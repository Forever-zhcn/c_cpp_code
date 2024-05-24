#ifndef __C_STR_FUNC_H_
#define __C_STR_FUNC_H_


#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stddef.h>

void remove_char_inplace(char *str, char c);

char* remove_char_dynamic(const char *str, char c);

char* split_string(const char* str, const char* fen, int index);
char* str_substr(char* str, const char* substr);
bool get_data(const char *data, const char *key, const char* end, char *_data, size_t length);

void mystr_test();

#ifdef __cplusplus
}
#endif

#endif


