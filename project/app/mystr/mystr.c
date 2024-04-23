#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mystr.h"

char aa[64];

char str[] = "abcdefghijklmnopq";
const char* fen = ",";
char str1[24];


char PRODUCT_KEY[32];       //产品ID
char DEVICE_NAME[64];       //设备名
char DEVICE_SECRET[64];     //设备key

const char serial_buffer[128] = "{{\"productkey\":\"a1Yud6xSXVd\"},{\"devicename\":\"BCM-1-B-2023071701-897000\"},{\"devicesecret\":\"021775312304e349631322b6320e60ec\"}}";



char* split_string(const char* str, const char* fen, int index) {
    const char* temp = str;
    int count = 0;
    
    while (count < index) {
        const char* pos = strstr(temp, fen);
        
        if (pos != NULL) {
            temp = pos + strlen(fen);
            count++;
        } else {
            return NULL; // 返回nullptr表示找不到分隔符或者分隔符不足index次
        }
    }

    // 计算要返回的子字符串的长度
    const char* end = strstr(temp, fen);
    size_t length;
    if (end != NULL) {
        length = end - temp;
    } else {
        length = strlen(temp);
    }

    char* result = (char *)malloc(length + 1); // 加1是为了存储字符串的终止符'\0'
    strncpy(result, temp, length);
    result[length] = '\0'; // 手动添加字符串终止符

    return result;
}

char* str_substr(char* str, const char* substr)
{
    const char* weizhi = strstr(str, substr);
    if(NULL != weizhi){
        // 计算子字符串的起始位置（weizhi + substr 的长度）
        int startPos = weizhi - str + strlen(substr);

        char* laststr = (str + startPos);
        return  laststr;
    }
    return NULL;
    
}


// @br 从data中提取key后的字段，以end作为结束字符
bool get_data(const char *data, const char *key, const char* end, char *_data, size_t length) {  
    if (data == NULL || _data == NULL || key == NULL) {  
        return 0;  
    }

    // 查找key
    char *start = strstr(data, key);  
    if (start == NULL)
        return 0; // 如果key不在data中，返回0
    
    char *_data_start = start + strlen(key);
    char *_data_end = strstr(_data_start, end);
    if(_data_end == NULL) {
        return 0; // 如果end不在_data_start中，返回0 
    }

    if(length < (size_t)(_data_end - _data_start))//防止越界
        return 0;

    memset(_data, 0, length);
    int i = 0;
    for( ; i < (_data_end - _data_start); i++){
        _data[i] = *(_data_start+i);
    }
    _data[i] = '\0';
    return 1; 
}


// @br 从data中提取key后的字段，以end作为结束字符
bool get_json(const char *data, const char *key, const char* end, char *_data, size_t length) {  
    if (data == NULL || _data == NULL || key == NULL) {  
        return 0;  
    }

    // 查找key
    char *start = strstr(data, key);  
    if (start == NULL)
        // Serial.printf("no find %s\r\n", key);
        return 0; // 如果key不在data中，返回0
    
    // key后紧接_data，算出end位置
    char *_data_start = start + strlen(key);
    char *_data_end = strstr(_data_start, end);
    if(_data_end == NULL) {
        // Serial.printf("no find %s\r\n", end);
        return 0; // 如果end不在_data_start中，返回0 
    }

    if(length < (size_t)(_data_end - _data_start))//防止越界 此处越界为处理好
        return 0;

    memset(_data, 0, length);
    int i = 0;
    // for(char *p=_data_start; (*p != *end)&&(*p != '\0'); p++){//此处有bug
    //     _data[i++] = *p;
    // }
    for(; i < (_data_end - _data_start); i++){
        _data[i] = *(_data_start+i);
    }
    _data[i] = '\0';
    return 1; 
}


void mystr_test()
{
    bool flag1 = get_data(serial_buffer, "\"productkey\":\"", "\"}", PRODUCT_KEY, sizeof(PRODUCT_KEY));
    bool flag2 = get_data(serial_buffer, "\"devicename\":\"", "\"}", DEVICE_NAME, sizeof(DEVICE_NAME));
    bool flag3 = get_data(serial_buffer, "\"devicesecret\":\"", "\"}", DEVICE_SECRET, sizeof(DEVICE_SECRET));

    printf("flag1:%d\r\n", flag1);
    printf("flag2:%d\r\n", flag2);
    printf("flag3:%d\r\n", flag3);

    printf("PRODUCT_KEY:%s\r\n", PRODUCT_KEY);
    printf("DEVICE_NAME:%s\r\n", DEVICE_NAME);
    printf("DEVICE_SECRET:%s\r\n", DEVICE_SECRET);

}