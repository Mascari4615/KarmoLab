#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int*, int, int);
void multiplyArray(int**, int, int, int**, int, int);
/**
* 두 개의 행렬을 곱하는 프로그램.
*/
int main(void) {

	int oneRow, oneColumn, otherRow, otherColumn;

	printf("첫 번째 행렬의 행 개수를 입력하세요: ");
	scanf_s("%d", &oneRow);
	printf("첫 번째 행렬의 열 개수를 입력하세요: ");
	scanf_s("%d", &oneColumn);
	printf("두 번째 행렬의 행 개수를 입력하세요: ");
	scanf_s("%d", &otherRow);
	printf("두 번째 행렬의 열 개수를 입력하세요: ");
	scanf_s("%d", &otherColumn);

	if (oneColumn != otherRow) {
		printf("두 행렬의 곱을 구할 수 없는 상황입니다.\n");
		return 0;
	}

	// 첫 번째 배열 생성
	int** one = (int**)malloc(sizeof(int*) * oneRow);
	for (int i = 0; i < oneRow; i++) {
		one[i] = (int*)malloc(sizeof(int) * oneColumn);
	}
	// 두 번째 배열 생성
	int** other = (int**)malloc(sizeof(int*) * otherRow);
	for (int i = 0; i < otherRow; i++) {
		other[i] = (int*)malloc(sizeof(int) * otherColumn);
	}
	// 첫 번째 배열에 값 할당
	srand(time(NULL));
	for (int i = 0; i < oneRow; i++) {
		for (int j = 0; j < oneColumn; j++) {
			one[i][j] = rand() % 9 + 1;
		}
	}
	// 두 번째 배열에 값 할당
	for (int i = 0; i < otherRow; i++) {
		for (int j = 0; j < otherColumn; j++) {
			other[i][j] = rand() % 9 + 1;
		}
	}

	printArray(one, oneRow, oneColumn);
	printf("----------\n");
	printArray(other, otherRow, otherColumn);
	printf("----두 행렬의 합은----\n");
	multiplyArray(one, oneRow, oneColumn, other, otherRow, otherColumn);

	for (int i = 0; i < oneRow; i++) {
		free(one[i]);
	}
	free(one);
	for (int i = 0; i < otherRow; i++) {
		free(other[i]);
	}
	free(other);

	return 0;
}
/**
* 행렬(배열)을 출력하는 메소드.
*/
void printArray(int** one, int row, int column) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d ", one[i][j]);
		}
		printf("\n");
	}

}
/**
* 두 행렬을 곱하는 메소드.
*/
void multiplyArray(int** one, int oneRow, int oneColumn, int** other, int otherRow, int otherColumn) {

	// 두 행렬을 곱한 새 행렬을 저장할 새 배열
	int newRow = oneRow; //2
	int newColumn = otherColumn; //3
	int** newOne = (int**)malloc(sizeof(int*) * newRow);
	for (int i = 0; i < newRow; i++) {
		newOne[i] = (int*)malloc(sizeof(int) * newColumn);
	}

	// 행렬 곱셈 값 저장
	for (int i = 0; i < newRow; i++) 
	{
		for (int j = 0; j < newColumn; j++) 
		{
			newOne[i][j] = 0;
			for (int k = 0; k < oneColumn; k++)
			{
				newOne[i][j] += one[i][k] * other[k][j];
			}
		}
	}

	printArray(newOne, newRow, newColumn);

	for (int i = 0; i < newRow; i++) {
		free(newOne[i]);
	}
	free(newOne);

}