/*
  Copyright (c) 2009 Dave Gamble
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

/* Parse text to JSON, then render back to text, and print! */
void doit(char *text)
{
	char *out;cJSON *json;
	
	json=cJSON_Parse(text);
	if (!json) {printf("Error before: [%s]\n",cJSON_GetErrorPtr());}
	else
	{
		out=cJSON_Print(json);
		cJSON_Delete(json);
		printf("%s\n",out);
		free(out);
	}
}

/* Read a file, parse, render back, etc. */
void dofile(char *filename)
{
	FILE *f;long len;char *data;
	
	f=fopen(filename,"rb");fseek(f,0,SEEK_END);len=ftell(f);fseek(f,0,SEEK_SET);
	data=(char*)malloc(len+1);fread(data,1,len,f);fclose(f);
	doit(data);
	free(data);
}

/* Used by some code below as an example datatype. */
struct record {const char *precision;double lat,lon;const char *address,*city,*state,*zip,*country; };

/* Create a bunch of objects as demonstration. */
void create_objects()
{
	cJSON *root,*fmt,*img,*thm,*fld;char *out;int i;	/* declare a few. */
	/* Our "days of the week" array: */
	const char *strings[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	/* Our matrix: */
	int numbers[3][3]={{0,-1,0},{1,0,0},{0,0,1}};
	/* Our "gallery" item: */
	int ids[4]={116,943,234,38793};
	/* Our array of "records": */
	struct record fields[2]={
		{"zip",37.7668,-1.223959e+2,"","SAN FRANCISCO","CA","94107","US"},
		{"zip",37.371991,-1.22026e+2,"","SUNNYVALE","CA","94085","US"}};

	/* Here we construct some JSON standards, from the JSON site. */
	
	/* Our "Video" datatype: */
	root=cJSON_CreateObject();	
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
	cJSON_AddItemToObject(root, "format", fmt=cJSON_CreateObject());
	cJSON_AddStringToObject(fmt,"type",		"rect");
	cJSON_AddNumberToObject(fmt,"width",		1920);
	cJSON_AddNumberToObject(fmt,"height",		1080);
	cJSON_AddFalseToObject (fmt,"interlace");
	cJSON_AddNumberToObject(fmt,"frame rate",	24);
	
	out=cJSON_Print(root);	cJSON_Delete(root);	printf("%s\n",out);	free(out);	/* Print to text, Delete the cJSON, print it, release the string. */

	/* Our "days of the week" array: */
	root=cJSON_CreateStringArray(strings,7);

	out=cJSON_Print(root);	cJSON_Delete(root);	printf("%s\n",out);	free(out);

	/* Our matrix: */
	root=cJSON_CreateArray();
	for (i=0;i<3;i++) cJSON_AddItemToArray(root,cJSON_CreateIntArray(numbers[i],3));

/*	cJSON_ReplaceItemInArray(root,1,cJSON_CreateString("Replacement")); */
	
	out=cJSON_Print(root);	cJSON_Delete(root);	printf("%s\n",out);	free(out);


	/* Our "gallery" item: */
	root=cJSON_CreateObject();
	cJSON_AddItemToObject(root, "Image", img=cJSON_CreateObject());
	cJSON_AddNumberToObject(img,"Width",800);
	cJSON_AddNumberToObject(img,"Height",600);
	cJSON_AddStringToObject(img,"Title","View from 15th Floor");
	cJSON_AddItemToObject(img, "Thumbnail", thm=cJSON_CreateObject());
	cJSON_AddStringToObject(thm, "Url", "http:/*www.example.com/image/481989943");
	cJSON_AddNumberToObject(thm,"Height",125);
	cJSON_AddStringToObject(thm,"Width","100");
	cJSON_AddItemToObject(img,"IDs", cJSON_CreateIntArray(ids,4));

	out=cJSON_Print(root);	cJSON_Delete(root);	printf("%s\n",out);	free(out);

	/* Our array of "records": */

	root=cJSON_CreateArray();
	for (i=0;i<2;i++)
	{
		cJSON_AddItemToArray(root,fld=cJSON_CreateObject());
		cJSON_AddStringToObject(fld, "precision", fields[i].precision);
		cJSON_AddNumberToObject(fld, "Latitude", fields[i].lat);
		cJSON_AddNumberToObject(fld, "Longitude", fields[i].lon);
		cJSON_AddStringToObject(fld, "Address", fields[i].address);
		cJSON_AddStringToObject(fld, "City", fields[i].city);
		cJSON_AddStringToObject(fld, "State", fields[i].state);
		cJSON_AddStringToObject(fld, "Zip", fields[i].zip);
		cJSON_AddStringToObject(fld, "Country", fields[i].country);
	}
	
/*	cJSON_ReplaceItemInObject(cJSON_GetArrayItem(root,1),"City",cJSON_CreateIntArray(ids,4)); */
	
	out=cJSON_Print(root);	cJSON_Delete(root);	printf("%s\n",out);	free(out);

}

void cJSONTest() {
	/* a bunch of json: */
	char text1[]="{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  false,\"frame rate\": 24\n}\n}";	
	char text2[]="[\"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\", \"Saturday\"]";
	char text3[]="[\n    [0, -1, 0],\n    [1, 0, 0],\n    [0, 0, 1]\n	]\n";
	char text4[]="{\n		\"Image\": {\n			\"Width\":  800,\n			\"Height\": 600,\n			\"Title\":  \"View from 15th Floor\",\n			\"Thumbnail\": {\n				\"Url\":    \"http:/*www.example.com/image/481989943\",\n				\"Height\": 125,\n				\"Width\":  \"100\"\n			},\n			\"IDs\": [116, 943, 234, 38793]\n		}\n	}";
	char text5[]="[\n	 {\n	 \"precision\": \"zip\",\n	 \"Latitude\":  37.7668,\n	 \"Longitude\": -122.3959,\n	 \"Address\":   \"\",\n	 \"City\":      \"SAN FRANCISCO\",\n	 \"State\":     \"CA\",\n	 \"Zip\":       \"94107\",\n	 \"Country\":   \"US\"\n	 },\n	 {\n	 \"precision\": \"zip\",\n	 \"Latitude\":  37.371991,\n	 \"Longitude\": -122.026020,\n	 \"Address\":   \"\",\n	 \"City\":      \"SUNNYVALE\",\n	 \"State\":     \"CA\",\n	 \"Zip\":       \"94085\",\n	 \"Country\":   \"US\"\n	 }\n	 ]";

	/* Process each json textblock by parsing, then rebuilding: */
	doit(text1);
	doit(text2);	
	doit(text3);
	doit(text4);
	doit(text5);

	/* Parse standard testfiles: */
/*	dofile("../../tests/test1"); */
/*	dofile("../../tests/test2"); */
/*	dofile("../../tests/test3"); */
/*	dofile("../../tests/test4"); */
/*	dofile("../../tests/test5"); */

	/* Now some samplecode for building objects concisely: */
	create_objects();
}


void printJson(cJSON * root)//以递归的方式打印json的最内层键值对
{
    for(int i=0; i<cJSON_GetArraySize(root); i++)   //遍历最外层json键值对
    {
        cJSON * item = cJSON_GetArrayItem(root, i);        
        if(cJSON_Object == item->type)      //如果对应键的值仍为cJSON_Object就递归调用printJson
            printJson(item);
        else                                //值不为json对象就直接打印出键和值
        {
            printf("%s->", item->string);
            //printf("%s\n", cJSON_Print(item));//内存泄漏
        }
    }
}


static void analy_wifi()
{
    const char *json_data = "{\"wifiname\":\"aaa\",\"password\":\"12345678\"}";

	cJSON *cjson_data;
	cJSON *wifiname;
	cJSON *password;

	char wifi_ssid[64] = {0};
	char wifi_pass[64] = {0};
	int wifi_json_ok = 0;
	cjson_data = cJSON_Parse((char *)(json_data));//将json字符串转化成CJSON结构体类型的数据
	if(cjson_data)
	{
		//printf("这是json\r\n");
		wifiname = cJSON_GetObjectItem(cjson_data,"wifiname");//获取名称为name的值
		password = cJSON_GetObjectItem(cjson_data,"password");//获取名称为name的值
		if(wifiname)
		{
			// printf("json解析：%s\r\n",cjson_str->valuestring);
			strcpy(wifi_ssid, wifiname->valuestring);
			wifi_json_ok++;
		}

		if(password)
		{
			// printf("json解析：%s\r\n",password->valuestring);
			strcpy(wifi_pass, password->valuestring);
			wifi_json_ok++;
		}
		
		cJSON_Delete(cjson_data);
		// cJSON_Delete(cjson_str);
		// cJSON_Delete(cjson_str2);
	}
	else{
		fprintf(stderr, "Error in cJSON_Parse: %s\n", cJSON_GetErrorPtr());
	}
	printf("wifi_ssid:%s\n", wifi_ssid);
	printf("wifi_pass:%s\n", wifi_pass);
}



static int analy_value()
{
    // JSON 字符串
    const char *json_str = "{\"deviceType\":\"CustomCategory\",\"iotId\":\"2XrfXZh74DQDJPeMh3TA000000\",\"requestId\":\"null\",\"checkFailedData\":{},\"productKey\":\"a1vF4yG4xrh\",\"gmtCreate\":1713793968179,\"deviceName\":\"app_dev_111111\",\"items\":{\"LED1\":{\"time\":1713793968174,\"value\":1}}}";

    // 解析 JSON 字符串
    cJSON *root = cJSON_Parse(json_str);
    if (root == NULL) {
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        return 1;
    }

    // 获取 items 字段的 cJSON 对象
    cJSON *items = cJSON_GetObjectItemCaseSensitive(root, "items");
    if (items == NULL) {
        printf("Error: items not found\n");
        cJSON_Delete(root);
        return 1;
    }

    // 获取 LED1 字段的 cJSON 对象
    cJSON *LED1 = cJSON_GetObjectItemCaseSensitive(items, "LED1");
    if (LED1 == NULL) {
        printf("Error: LED1 not found\n");
        cJSON_Delete(root);
        return 1;
    }
    char *LED1_str = cJSON_Print(LED1);
    printf("LED1_str: %s\n", LED1_str);

    // 获取 value 字段的 cJSON 对象
    cJSON *value = cJSON_GetObjectItemCaseSensitive(LED1, "value");
    if (value == NULL) {
        printf("Error: value not found\n");
        cJSON_Delete(root);
        return 1;
    }

    char *value_str = cJSON_Print(value);
    printf("value_str: %s\n", value_str);

    // 判断 value 的类型并打印相应信息
    if (cJSON_IsString(value)) {
        printf("value is a string: %s\n", value->valuestring);
    } else if (cJSON_IsNumber(value)) {
        printf("value is a number\n");
        if (value->valuedouble == value->valueint) {
            printf("value is an integer: %d\n", value->valueint);
        } else {
            printf("value is a floating-point number: %f\n", value->valuedouble);
        }
    } else if (cJSON_IsBool(value)) {
        printf("value is a boolean: %s\n", cJSON_IsTrue(value) ? "true" : "false");
    } else if (cJSON_IsNull(value)) {
        printf("value is null\n");
    } else {
        printf("value is of unknown type\n");
    }

    // 获取 value 字段的值
    int value_int = cJSON_GetNumberValue(value);
    printf("LED1 value: %d\n", value_int);

    // 释放 cJSON 对象
    cJSON_Delete(root);

    return 0;
}


static void creat_json_demo()
{
    typedef __UINT8_TYPE__ __uint8_t;
    typedef __uint8_t uint8_t ;
    uint8_t Temp_Value = 28;
    uint8_t Temp_point_Value = 8;
    uint8_t Humi_Value = 28;
    uint8_t Humi_point_Value = 8;
    uint8_t led1_state = 1;


    // 创建根节点
    cJSON *root = cJSON_CreateObject();
    if (root == NULL) {
        printf("Error creating root object\n");
        return ;
    }
    // 创建 params 子节点
    cJSON *params = cJSON_CreateObject();
    if (params == NULL) {
        printf("Error creating params object\n");
        cJSON_Delete(root);
        return ;
    }
    // 将 params 节点添加到根节点
    cJSON_AddItemToObject(root, "params", params);

    // 添加 temp 字段到 params 节点
    cJSON_AddNumberToObject(params, "temp", Temp_Value + (float)Temp_point_Value / 10.0);

    // 添加 humi 字段到 params 节点
    cJSON_AddNumberToObject(params, "humi", Humi_Value + (float)Humi_point_Value / 10.0);

    // 添加 LED1 字段到 params 节点
    cJSON_AddNumberToObject(params, "LED1", !led1_state);

    

    // 将 cJSON 对象转换为字符串
    // char *jsonString = cJSON_Print(root);            // 创建出的json为带换行的格式
    char *jsonString = cJSON_PrintUnformatted(root);    // 创建出的json为不带换行的格式
    if (jsonString == NULL) {
        printf("Error converting cJSON to string\n");
        cJSON_Delete(root);
        return ;
    }

    printf("jsonString:%s\r\n", jsonString);

    // char Pub_Buffer[256];
    // // 将 JSON 字符串复制到 Pub_Buffer 中
    // strcpy(Pub_Buffer, jsonString);

    // 释放 cJSON 对象和 JSON 字符串
    cJSON_Delete(root);
    free(jsonString);

    
}

void cJSON_test()
{
    // analy_wifi();

    // analy_value();

    creat_json_demo();


}
