#include "Open_File.h"
#include <stdio.h>
void open_File(char* search)
{
	int c;
	FILE* fp = NULL;
	fp = fopen(search, "r");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
	}
	else
	{
		printf("���� ���� ����\n");
	}

	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	printf("\n");
	fclose(fp);
}