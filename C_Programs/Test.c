#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*윈도우 메모리 사용량 체크에 필요한 헤더*/
#include <Windows.h>
#include <psapi.h>
#include <conio.h>
#include<malloc.h>

/** 로딩 과정중에서 발생한 메모리 소요량을 측정한다. */
static PROCESS_MEMORY_COUNTERS_EX g_mc;

int main()
{
    PROCESS_MEMORY_COUNTERS_EX pmc;
    // 메모리 사용상태를 얻는다.
    GetProcessMemoryInfo(GetCurrentProcess(),
        (PROCESS_MEMORY_COUNTERS*)&g_mc, sizeof(g_mc));

    //메모리 로드 코드
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    char** inputs = NULL, temp[100] = { NULL, };
    while ((inputs = malloc(sizeof(char*) * n)) == NULL);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        while ((inputs[i] = malloc(strlen(temp) + 1)) == NULL);
        strcpy(inputs[i], temp);
    }


    //로드 후 메모리 사용량 표시
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    printf("Memory Usage : %u\n", (pmc.PrivateUsage - g_mc.PrivateUsage));

    //메모리 해제 코드
    for (int i = 0; i < n; i++)
    {
        free(inputs[i]);
    }

    free(inputs);

    /*해제 후 메모리 사용량 표시*/
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    printf("Memory Usage : %u\n", (pmc.PrivateUsage - g_mc.PrivateUsage));

    //콘솔모드 자동 종료 방지
    printf("\nPress any key to exit.");
    while (!_kbhit()); _getch();
}
