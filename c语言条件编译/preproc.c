/*
 * Copyright(c) 2008 - 2021 Allwinner Technology Co. Ltd.
 * All rights reserved.
 * 
 * CreateDate   : 2020-10-10
 * Author       : Jianxiong Tang
 * LastEditTime : 2020-10-10
 * FilePath     : /tech_accumulation/c语言条件编译/preproc.c
 * Description  : 简单的预处理示例
 */

#include <stdio.h>
#define TWO 2
#define OW "the world is\
beautiful!"

#define FOUR TWO *TWO
#define PX printf("X is %d.\n", x)
#define FMT "X is %d.\n"

int main()
{
	int x = TWO;

	PX;
	x = FOUR;
	printf(FMT, x);
	printf("%s\n", OW);
	printf("TWO:OW\n");

	return 0;
}