#ifndef __MYSTR_H_
#define __MYSTR_H_

#ifdef __cplusplus
extern "C"{
#endif

char* split_string(const char* str, const char* fen, int index);
char* str_substr(char* str, const char* substr);
bool get_data(const char *data, const char *key, const char* end, char *_data, size_t length);

void mystr_test();

#ifdef __cplusplus
}
#endif


#endif

