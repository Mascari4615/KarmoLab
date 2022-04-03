#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Address
{
	char name[10];
	char phoneNumber[13];
	char address[10];
	char birthDay[10];
    struct Address* link;
};
typedef struct Address address;

void AddAddress(address*);
void DeleteAddress(address*);
void PrintAddress(address*);
void SearchAddress(address*);

void Program2_24()
{
    address* ptr = (address*)malloc(sizeof(address));
    ptr->link = NULL;

	while (1)
	{
		int command;

		printf("명령 : ");
		scanf("%d", &command);

		switch (command)
		{
			case 0: // 목록
                PrintAddress(ptr->link);
				break;
			case 1: // 추가
                AddAddress(ptr);
				break;
			case 2: // 탐색
                SearchAddress(ptr);
				break;
			case 3: // 삭제
                DeleteAddress(ptr);
				break;
            default:
				exit(0);
				break;
		}
	}
}

void main()
{
    Program2_24();
}

void PrintAddress(address* ptr) 
{
    printf("- 목록 \n");
    printf("이름\t\t전화번호\t주소\t\t생일\n");
    do 
        printf("%s\t\t%s\t\t%s\t\t%s\n", ptr->name, ptr->phoneNumber, ptr->address, ptr->birthDay);
    while ((ptr = ptr->link) != NULL);
    printf("\n");
}

void AddAddress(address* ptr) 
{
    printf("- 추가 \n");
    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = (address*)malloc(sizeof(address));
    ptr = ptr->link;

    printf("이름 : ");
    scanf("%s", ptr->name);
    printf("전화번호 : ");
    scanf("%s", ptr->phoneNumber);
    printf("주소 : ");
    scanf("%s", ptr->address);
    printf("생일 : ");
    scanf("%s", ptr->birthDay);
    
    ptr->link = NULL;
    printf("\n");

    while (getchar() != '\n');
}

void SearchAddress(address* ptr)
{
    printf("- 탐색 \n");
    char _name[15];

    printf("이름 : ");
    scanf("%s", _name);

    printf("이름\t\t전화번호\t주소\t\t생일\n");

    while (ptr != NULL) 
    {
        if (strcmp(_name, ptr->name) == 0) 
        {
            printf("%s\t\t%s\t\t%s\t\t%s\n", ptr->name, ptr->phoneNumber, ptr->address, ptr->birthDay);
        }
        ptr = ptr->link;
    }

    while (getchar() != '\n');
}

void DeleteAddress(address* ptr) 
{
    printf("- 삭제 \n");
    address* temp;
    char targetName[10];

    printf("이름 : ");
    scanf("%s", targetName);

    while (ptr->link != NULL) 
    {
        temp = ptr;
        ptr = ptr->link;

        if (strcmp(targetName, ptr->name) == 0) 
        {
            temp->link = ptr->link;
            free(ptr);
            break;
        }
    }

    while (getchar() != '\n');
}