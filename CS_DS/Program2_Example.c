#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void Program2_1()
{
	char c, c_array[100];
	int i, i_array[100];
	short s, s_array[100];
	float f, f_array[100];
	long l, l_array[100];

	printf("\n char c 크기 = %d \t: char c_array 크기 = %4d", sizeof(c), sizeof(c_array));
	printf("\n int i 크기 = %d \t: int i_array 크기 = %4d", sizeof(i), sizeof(i_array));
	printf("\n short s 크기 = %d \t: short s_array 크기 = %4d", sizeof(s), sizeof(s_array));
	printf("\n float f 크기 = %d \t: float f_array 크기 = %4d", sizeof(f), sizeof(f_array));
	printf("\n long l 크기 = %d \t: long l_array 크기 = %4d", sizeof(l), sizeof(l_array));

	getchar();
}

void Program2_2()
{
	int i;
	// 1차원 배열 초기화
	int score[3] = { 91, 86, 97 };
	char grade[3] = { 'A','B','A' };

	printf("\n *** 학년별 취득 학점 *** \n\n");

	for (i = 0; i < 3; i++)
	{
		printf("%3d학년 : 총점 = %d, 등급 = %c\n", i + 1, score[i], grade[i]);
	}

	getchar();
}

void Program2_3()
{
	int i = 0, n;
	int multiply[9];

	printf("\n1~9의 정수를 입력하세요 : ");

	while (1)
	{
		scanf("%d", &n);
		if (n < 0 || n > 9)
		{
			printf("\n 1~9의 정수를 입력하세요 : ");
		}
		else
		{
			break;
		}
	}

	printf("\n");

	for (i = 0; i < 9; i++)
	{
		multiply[i] = n * (i + 1);
		printf(" %d * %d = %d \n", n, (i + 1), multiply[i]);
	}

	getchar();
	getchar();
}

void Program2_4()
{
	char str[20] = "Data Structure!";
	int i;
	printf("\n문자 배열 str[] : ");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
	}
	getchar();
}

void Program2_5()
{
	int i, length = 0;
	char str[50];
	printf("\n문자열을 입력하세요 : ");
	gets(str);
	printf("\n입력된 문자열은 \n \"");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n입니다.");
	printf("\n\n입력된 문자열의 길이 = %d \n", length);

	getchar();
}

void Program2_6()
{
	int array[2][3][4];
	int i, j, k, value = 1;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				array[i][j][k] = value;
				printf("\n array[%d][%d][%d] = %d", i, j, k, array[i][j][k]);
				value++;
			}
		}
	}
	getchar();
}

void Program2_7()
{
	int i, j, k;
	char student[2][3][20];
	for (i = 0; i < 2; i++)
	{
		printf("\n 학생 %d의 이름 : ", i + 1);
		gets(student[i][0]);
		printf("\n 학생 %d의 학과 : ", i + 1);
		gets(student[i][1]);
		printf("\n 학생 %d의 학번 : ", i + 1);
		gets(student[i][2]);
	}

	for (i = 0; i < 2; i++)
	{
		printf("\n\n 학생 %d", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("\n\t");
			for (k = 0; student[i][j][k] != '0'; k++)
			{
				printf("%c", student[i][j][k]);
			}
		}
	}
	getchar();
}

void Program2_8()
{
	int i = 10, j = 20;
	int* ptr;
	printf("\n i의 값 = %d \n j의 값 = %d", i, j);
	printf("\n i의 메모리 주소(&i) = %u", &i);
	printf("\n j의 메모리 주소(&j) = %u", &j);

	ptr = &i;
	printf("\n\n << ptr = &i 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr = &j 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	i = *ptr;
	printf("\n\n << i=*ptr 실행 >>");
	printf("\n i의 값 = %d", i);

	getchar();
}

void Program2_9()
{
	int i;
	char string1[20] = "Dreams come true!", string2[20], * ptr1, * ptr2;

	ptr1 = string1;
	printf("\n string1의 주소 = %u \t ptr1 = %u", string1, string2);
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);
	printf("\n\n %s", ptr1 + 7);
	ptr2 = &string1[7];
	printf("\n %s \n\n ", ptr2);

	for (i = 16; i >= 0; i--)
	{
		putchar(*(ptr1 + i));
	}

	for (i = 0; i < 20; i++)
	{
		string2[i] = *(ptr1 + 1);
	}
	printf("\n\n string1 = %s", string1);
	printf("\n string2 = %s", string2);

	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1);

	getchar();
}

void Program2_10()
{
	int i;
	char* ptrArray[4] = { {"Korea"}, {"Seoul"}, {"Mapo"},  {"152번지 2 / 3"} };

	for (i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	ptrArray[2] = "Jongno";
	printf("\n\n");
	for (i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	getchar();
}

void Program2_11()
{
	char* ptrArray[2];
	char** ptrptr;
	int i;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Seoul";

	ptrptr = ptrArray;
	printf("\n ptrArray[0]의 주소 (&ptrArray[0]) = %u", &ptrArray[0]);
	printf("\n ptrArray[0]의 값 (&ptrArray[0]) = %u", ptrArray[0]);
	printf("\n ptrArray[0]의 참조값 (*ptrArray[0]) = %ㅊ", *ptrArray[0]);
	printf("\n ptrArray[0]의 참조 문자열 (*&ptrArray[0]) = %s \n", *ptrArray);

	printf("\n ptrArray[1]의 주소 (&ptrArray[1]) = %u", &ptrArray[1]);
	printf("\n ptrArray[1]의 값 (&ptrArray[1]) = %u", ptrArray[1]);
	printf("\n ptrArray[1]의 참조값 (*ptrArray[1]) = %ㅊ", *ptrArray[1]);
	printf("\n ptrArray[1]의 참조 문자열 (*&ptrArray[1]) = %s \n", *(ptrArray + 1));

	printf("\n ptrptr의 주소 (&ptrArray[0]) = %u", &ptrArray[0]);
	printf("\n ptrptr의 값 (&ptrArray[0]) = %u", ptrArray[0]);
	printf("\n ptrptr의 1차 참조값 (*ptrptr) = %u", *ptrptr);
	printf("\n ptrptr의 2차 참조값 (**ptrptr) = %c", **ptrptr);
	printf("\n ptrptr의 2차 참조 문자열 (**ptrptr) = %s", *ptrptr);

	printf("\n\n *ptrArray[0] : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrArray[0] + i));
	}
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrptr + i));
	}

	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrArray[1] + i));
	}
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *((ptrptr + 1) + i));
	}

	getchar();
}

struct employee
{
	char name[10];
	int year;
	int pay;
};

void Program2_12()
{
	int i;
	struct employee Lee[4] =
	{
		{ "이진호", 2022, 5200},
		{ "이한영", 2023, 4300},
		{ "이상원", 2023, 4500},
		{ "이상법", 2024, 3900},
	};

	for (i = 0; i < 4; i++)
	{
		printf("\n 이름 : %s", Lee[i].name);
		printf("\n 입사 : %s", Lee[i].year);
		printf("\n 연봉 : %s", Lee[i].pay);
	}

	getchar();
}


void Program2_13()
{
	int i;
	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "이순신");
	Sptr->year = 2023;
	Sptr->pay = 6900;

	printf("\n 이름 : %s", Sptr->name);
	printf("\n 입사 : %s", Sptr->year);
	printf("\n 연봉 : %s", Sptr->pay);

	getchar();
}

long int fact(int n)
{
	int value;
	if (n <= 1)
	{
		printf("\n fact(1) 함수 호출!");
		printf("\n fact(1) 값 1 반환!!");
		return;
	}
	else
	{
		printf("\n fact(%d) 함수 호출!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) 값 %ld 반환!!", n, value);
		return value;
	}
}

void Program2_14()
{
	int n, result;
	printf("\n 정수를 입력하세요 : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d의 팩토리얼 값은 %ld입니다.\n", n, result);
	getchar(); getchar();
}

void hanoi(int n, int start, int work, int target)
{
	if (n == 1)
	{
		printf(" %c에서 원반 %d를(을) %c로 옮김 \n", start, n, target);
	}
	else
	{
		hanoi(n - 1, start, target, work);
		printf(" %c에서 원반 %d를(을) %c로 옮김 \n", start, n, target);
		hanoi(n - 1, work, start, target);
	}
}

void Program2_15()
{
	hanoi(3, 'A', 'B', 'C');
	getchar();
}

void main()
{
	Program2_15();

	return 0;
}