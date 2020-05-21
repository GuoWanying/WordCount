// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

int main(int argc, char* argv[]) {
    char c;
    int Ccnt = 0, Wcnt = 0;
        FILE * f;
 //   if (argc != 3) {
 //       printf("Parameter error!\n");
//    }
    if ((f = fopen(argv[2], "rb")) == NULL) {
        printf("Can not open the source file!\n");
            exit(0);
    }
    fseek(f, 0L, 0);
        while (!feof(f)) {
            fread(&c, 1, 1, f);
                if (c == ' ' || c == ',')  Wcnt++;
                Ccnt++;
        }
    Wcnt++;
    if (strcmp(argv[1], "-w") == 0) printf("单词数：%d\n", Wcnt);
    else if (strcmp(argv[1], "-c") == 0) printf("字符数：%d\n", Ccnt);
    fclose(f);
    return 0;
}