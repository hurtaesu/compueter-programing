/*
�й�: 202203776
�̸�: ���¼�
Ư�� ������ �˻��ϸ� �� ������ �ڷγ� ������ �����ִ� ���α׷�
*/
#include <stdio.h>
#include <string.h>
#include "Open_File.h" //���� �ҽ� ����
#define _CRT_SECURE_NO_WARNINGS

struct Date //����ü ���
{
	int year;
	int month;
	int day;
};
void search_location(char (*location)[20], char *search /*������ ���, ������ Ȱ��*/) //�Լ� ���
{
	int i;
	printf("�˻��ϰ���� ����(��)�� �Է��Ͻʽÿ� :");
	gets_s(search, 100); //���ڿ� ���
	for (i = 0;i < 6; i++)
	{
		if (strcmp(search,*(location + i)) == 0)
		{
			printf("%s�� ã�ҽ��ϴ�\n",*(location + i));
		}
	}
}

int main(void)
{
	struct Date date;
	
	char search[100]; // ���ڿ� ���
	char location[6][20] = {"��⵵","������","��û��","����","���","���ֵ�"};  //�迭 ���
	search_location(location,search);
	strcat(search, ".txt");
	open_File(search); //���� �����

	printf("�⵵�� �Է��Ͻÿ�: ");
	scanf("%d", &date.year);
	printf("���� �Է��Ͻÿ�: ");
	scanf("%d", &date.month);
	printf("��¥�� �Է��Ͻÿ�: ");

	scanf("%d", &date.day);

	printf("�˻��� �ñ�(��.��.��)\n");
	printf("%d.", date.year);
	printf("%d.", date.month);
	printf("%d.\n", date.day);

	FILE* log = NULL;// ���� �����

	log = fopen("log.txt", "a");
	if (log != NULL)
	{
		printf("�˻��� �ñⰡ ����Ǿ����ϴ�.");
	}
	fprintf(log, "%d %d %d\n", date.year, date.month, date.day);

	return 0;
}