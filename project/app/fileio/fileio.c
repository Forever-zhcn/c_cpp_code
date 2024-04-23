#include <stdio.h>

#include "fileio.h"

    /*  @pa stdio 标准io(用户调用)      sysio 系统调用io（文件io 直接调用内核）
    *   
    *
    *   stdio:FILE类型贯穿始终
    *
    *   fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode);
    *   fclose(FILE *_File);
    *   fgetc(FILE *_File);     读到文件结尾返回EOF  #define EOF (-1)
    *   fputc(int _Ch,FILE *_File);     写失败返回 -1
    *   fgets(char * __restrict__ _Buf,int _MaxCount,FILE * __restrict__ _File);    遇到换行符\n会停止读取，长度要多预留一个字节的长度保存空字符'\0',函数会自动添加空字符'\0'
    *   fputs(const char * __restrict__ _Str,FILE * __restrict__ _File);    
    *   fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);     第二个参数为每块的字节数，第三个参数为总的块，存放在str指向的内存中，返回实际读到的块数
    *   fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File);
    *
    *   fprintf();
    *   fscanf();
    *
    *   rewind();   文件指针指向文件开头
    *   fseek(FILE *_File,long _Offset,int _Origin);    文件指针指向 _Origin（文件开头或文件当前位置或者文件末尾） 的偏移_Offset的位置
    *   ftell(FILE *_File); //文件读写位置距离文件开始有多少字节
    * 
    *   fflush(fflush);
    * 
    *   fgetc和fread()存在数组中时，需要在最后加空字符'\0'
    */

    /**
    *   r:打开文件，只读,若文件没有会出问题，不会创建文件
    *   w:打开文件，如果文件不在，会创建新文件；若文件存在会先清空原来的内容
    *   a:以追加方式打开文件，即再末尾添加内容；如果文件不在，会创建文件用于写；若文件存在且有内容，不会清空原来的内容，再写内容是追加再文件内容后面
    *   rb,wb,ab：是以二进制的形式打开文件
    *   +：对上面的权限进行增加，如：r+或rb+（以可读、可写的方式打开文件，不创建新文件）；
    *       w+或wb+（以可读、可写的方式打开文件，使文件长度为0字节（清空），若文件不存在则创建新文件）；
    *       a+或者ab+（以追加方式打开文件，打开文件并在末尾追加文件，若文件不存在则创建新文件）
    * 
    *   返回值：
    *       成功：打开的文件对应的文件指针
    *       失败：NULL
    * 
    * */
void fopen_test()
{
    
}



void fileio_test()
{
    FILE* fp = NULL;

    FILE* fp1 = NULL;

    fp = fopen(".\\fileio_test_file\\test.txt", "r");
    if(fp == NULL)
    {
        printf("open the file is filed!!\r\n");
        // perror("fopen()");//给出错误的信息，若无错会报 no error
        //return ;
    }
    else
    {
        printf("open the file is succeed!!\r\n");
    }

    fp1 = fopen(".\\fileio_test_file\\test1.txt", "w");
    if(fp1 == NULL)
    {
        printf("open the file(fp1) is filed!!\r\n");
        // perror("fopen()");//给出错误的信息，若无错会报 no error
        //return ;
    }
    else
    {
        printf("open the file(fp1) is succeed!!\r\n");
    }

    
    // char ch;
    // while ((ch = fgetc(fp)) != EOF)
    // {
    //     printf("%c", ch);
    // }
    // printf("\r\n");

    // char ch;
    // char ch1[100];
    // int index = 0;
    // while ((ch = fgetc(fp)) != EOF)
    // {
    //     ch1[index++] = ch;
    // }
    // ch1[index] = '\0';
    // printf("%s\r\n", ch1);
    // fputs(ch1, fp1);

    // char ch;
    // while ((ch = fgetc(fp)) != EOF)
    // {
    //     printf("%c", ch);
    //     fputc(ch, fp1);
    // }
    // printf("\r\n");


    // char str[100];
    // //第二个参数为每块的字节数，第三个参数为总的块，存放在str指向的内存中，返回实际读到的块数
    // fread(str, sizeof(char), 18, fp);

    // str[18] = '\0';
    // printf("str[]:%s\r\n", str);

    // fwrite(str, sizeof(char), 18, fp1);
    
    
    
    //fclose返回0则表示关闭成功
    int eclose = fclose(fp);
    if(eclose == 0)
    {
        printf("close the file is succeed!!\r\n");
    }
    else
    {
        printf("close the file is filed!!\r\n");
        // perror("fclose()");//给出错误的信息，若无错会报 no error
    }

    //fclose返回0则表示关闭成功
    int eclose1 = fclose(fp1);
    if(eclose1 == 0)
    {
        printf("close the file(fp1) is succeed!!\r\n");
    }
    else
    {
        printf("close the file(fp1) is filed!!\r\n");
        // perror("fclose()");//给出错误的信息，若无错会报 no error
    }
    
}
