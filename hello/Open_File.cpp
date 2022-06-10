#include "Open_File.h"
#include <stdio.h>
void open_File(char* search)
{
	int c;
	FILE* fp = NULL;
	fp = fopen(search, "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}

	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	printf("\n");
	fclose(fp);
}