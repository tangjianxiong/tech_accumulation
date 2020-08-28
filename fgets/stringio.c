#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

int main()
{
    char src[LEN];
    char *find;
    printf("please enter:\n");
    fgets(src, LEN, stdin);

    find = strchr(src, '\n'); //查找换行符
    if (find)                 //如果find不为空指针
        *find = '\0';         //就把一个空字符放在这里

    printf("your enter is:\n");
    fputs(src, stdout);
    char src1[LEN] = "hello world!";

    int res = strcmp(src, src1);
    if (res != 0)
    {
        printf("src  is different from src1\n");
    }
    else
    {
        printf("src is the same as src1\n");
    }

    return 0;
}