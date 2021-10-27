#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool IsUpperBiggerThenLower(int upper, int lower);
void GetBoundaries(int* upper, int* lower);
void Average();
void FrequencyDistribution();
void Sort();
void Variance();
void main()
{
	while (true)
	{
		char input = ' ';
		printf("실행할 함수를 선택하세요. : "); scanf("%c", &input);

		switch (input)
		{
			case 'A':
				Average();
				break;
			case 'F':
				FrequencyDistribution();
				break;
			case 'V':
				Variance();
				break;
			case 'S':
				Sort();
				break;
			case 'Q':
				exit();
				break;
			default:
				break;
		}
	}
	return 0;
}

void Average()
{
	int numCount = 0, total = 0;
	printf("Enter numCount : "); scanf("%d", &numCount);
	int* datas = malloc(sizeof(int) * numCount);
	for (int i = 0; i < numCount; i++) scanf("%d", &datas[i]);
	for (int i = 0; i < numCount; i++)
	{
		printf("%d번째 : %d", i + 1, total);
		total += datas[i];
		printf(" + %d = %d\n", datas[i], total);
	}
	printf("총 : %d\n", total);
	printf("실수 : %f\n", (float)total / numCount);

	free(datas);
}

void Variance()
{
	int numCount = 0, total = 0;
	printf("Enter numCount : "); scanf("%d", &numCount);
	int* datas = malloc(sizeof(int) * numCount);
	for (int i = 0; i < numCount; i++) scanf("%d", &datas[i]);
	for (int i = 0; i < numCount; i++)
	{
		printf("%d번째 : %d", i + 1, total);
		total += datas[i];
		printf(" + %d = %d\n", datas[i], total);
	}
	printf("총 : %d\n", total);
	printf("실수 : %f\n", (float)total / numCount);

	float average = 0;
	float ttotal = 0;
	printf("Enter Average : "); scanf("%f", &average);
	for (int i = 0; i < numCount; i++)
	{
		printf("%d번째 : %f", i + 1, ttotal);
		float temp = (float)datas[i] - average;
		ttotal += temp * temp;
		printf(" + %f * %f = %f\n", temp, temp, ttotal);
	}
	printf("총 : %f\n", ttotal);
	printf("정수 : %f\n", ttotal / numCount);
	printf("실수 : %f\n", ttotal / numCount);

	free(datas);
}

void Sort()
{
	int numCount = 0;
	printf("Enter numCount : "); scanf("%d", &numCount);
	int* buf = malloc(sizeof(int) * numCount);
	for (int i = 0; i < numCount; i++) scanf("%d", &buf[i]);
	int temp;
	for (int i = 0; i < numCount; i++)
	{
		for (int j = i + 1; j < numCount; j++)
		{
			if (buf[i] > buf[j])
			{
				temp = buf[i];
				buf[i] = buf[j];
				buf[j] = temp;
			}
		}

		printf("%d ", buf[i]);
	}
}

void FrequencyDistribution()
{
	int upper = 0, lower = 0, totalFrequency = 0, diff = 0;
	GetBoundaries(&upper, &lower);
	do printf("Enter TotalFrequency, Diff between classes (%d ~ %d): ", lower, upper);
	while (!scanf("%d %d", &totalFrequency, &diff) || (upper % diff != 0));

	int* datas = malloc(sizeof(int) * totalFrequency);
	for (int i = 0; i < totalFrequency; i++) scanf("%d", &datas[i]);

	int* classes = malloc(sizeof(int) * totalFrequency);
	int* frequencies = malloc(sizeof(int) * totalFrequency);
	for (int i = 0; i < totalFrequency; i++) frequencies[i] = 0;

	printf("계급(이상~미만)	계급값	도수\n");
	for (int i = 1; i <= upper / diff; i++)
	{
		printf("%d ~\t%d\t", lower + diff * (i - 1), lower + diff * i);

		classes[i - 1] = (2 * lower + diff * (2 * i - 1)) / 2;
		for (int j = 0; j < totalFrequency; j++)
			if (datas[j] >= lower + diff * (i - 1) && datas[j] < lower + diff * i) frequencies[i - 1]++;

		printf("%d\t", classes[i - 1]);
		printf("%d\n", frequencies[i - 1]);
	}

	printf("도수분포표 평균\n");
	float sum = 0;
	float average = 0;
	for (int i = 0; i < upper / diff; i++)
	{
		int result = classes[i] * frequencies[i];
		sum += result;
		printf("%d 번째 : (계급값)%d * (도수)%d = %d, 총합 : %.3f\n", i + 1, classes[i], frequencies[i], result, sum);
	}
	average = floor((sum / totalFrequency) * 1000) / 1000;
	printf("평균 : %f\n\n", average);
	
	printf("도수분포표 분산\n");
	sum = 0;
	float variance = 0;
	for (int i = 0; i < upper / diff; i++)
	{
		float deviation = classes[i] - average;
		float squared = deviation * deviation;
		float result = squared * frequencies[i];
		sum += result;
		printf("%d 번째 : (편차)%f, (편차제곱)%f, (도수)%d, (결과)%f, 총합 : %f\n", i + 1, deviation, squared, frequencies[i], result, sum);
	}
	variance = sum / totalFrequency;
	printf("분산 : %f\n\n", variance);

	printf("평균\n");
	sum = 0;
	for (int i = 0; i < totalFrequency; i++)
	{
		sum += datas[i];
		printf("%d 번째 : (데이터)%d, 총합 : %f\n", i + 1, datas[i], sum);
	}
	average = floor((sum / totalFrequency) * 1000) / 1000;
	printf("평균 : %f\n\n", average);

	printf("분산\n");
	sum = 0;
	variance = 0;
	for (int i = 0; i < totalFrequency; i++)
	{
		float deviation = datas[i] - average;
		float squared = deviation * deviation;
		sum += squared;
		printf("%d 번째 : (편차)%f, (편차제곱)%f, 총합 : %f\n", i + 1, deviation, squared, sum);
	}
	variance = sum / totalFrequency;
	printf("분산 : %f\n\n", variance);

	free(datas);
}

void GetBoundaries(int* upper, int* lower)
{
	int min = 0, max = 10000;

	do
	{
		do printf("Enter Lower (%d ~ %d) : ", min, max);
		while (!scanf("%d", lower) || (*lower < min || *lower > max));

		do printf("Enter Upper (%d ~ %d) : ", min, max);
		while (!scanf("%d", upper) || (*upper < min || *upper > max));

	} while (!IsUpperBiggerThenLower(*upper, *lower));
}

bool IsUpperBiggerThenLower(int upper, int lower)
{
	if (upper > lower) return true;
	else { printf("Your upper boundary cannot be smaller than your lower boundary"); return false; }
}