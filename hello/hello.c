/*
학번: 202203776
이름: 허태수
특정 지역을 검색하면 그 지역의 코로나 정보를 보여주는 프로그램
*/
#include <stdio.h>
#include <string.h>
#include "Open_File.h" //다중 소스 파일
#define _CRT_SECURE_NO_WARNINGS

struct Date //구조체 사용
{
	int year;
	int month;
	int day;
};
void search_location(char (*location)[20], char *search /*포인터 사용, 포인터 활용*/) //함수 사용
{
	int i;
	printf("검색하고싶은 지역(도)을 입력하십시오 :");
	gets_s(search, 100); //문자열 사용
	for (i = 0;i < 6; i++)
	{
		if (strcmp(search,*(location + i)) == 0)
		{
			printf("%s을 찾았습니다\n",*(location + i));
		}
	}
}

int main(void)
{
	struct Date date;
	
	char search[100]; // 문자열 사용
	char location[6][20] = {"경기도","강원도","충청동","전라도","경상도","제주도"};  //배열 사용
	search_location(location,search);
	strcat(search, ".txt");
	open_File(search); //파일 입출력

	printf("년도를 입력하시오: ");
	scanf("%d", &date.year);
	printf("월을 입력하시오: ");
	scanf("%d", &date.month);
	printf("날짜를 입력하시오: ");

	scanf("%d", &date.day);

	printf("검색한 시기(년.월.일)\n");
	printf("%d.", date.year);
	printf("%d.", date.month);
	printf("%d.\n", date.day);

	FILE* log = NULL;// 파일 입출력

	log = fopen("log.txt", "a");
	if (log != NULL)
	{
		printf("검색한 시기가 저장되었습니다.");
	}
	fprintf(log, "%d %d %d\n", date.year, date.month, date.day);

	return 0;
}