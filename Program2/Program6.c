#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse_add(int origin)
{
    int reverse = 0;
    for (int i = origin; i > 0; i /= 10)
    {
        reverse = (reverse * 10) + i % 10;
    }
    return origin + reverse;
}

int is_palindrome(int origin) 
{
    int reverse = 0;
    for (int i = origin; i > 0; i /= 10)
    {
        reverse = (reverse * 10) + i % 10;
    }
    if (origin == reverse) return 1;
    else return 0;    
}

void main() 
{
    int n; // 임의의 정수 (입력 값)
    int r = 0; // 회문인지를 알아내기 위한 반복 횟수
    int p = 0; // 회문에 해당하는 수
    printf("Please enter a number : ");
    scanf("%d", &n);

    if (is_palindrome(n))
    {
        r = 0;
        p = n;
    }
    else
    {
        while (r < 1000)
        {
            if (r == 0) p = reverse_add(n);
            else p = reverse_add(p);
            r++;
            if (is_palindrome(p)) break;
        }
    }    

    if (r < 1000 && p > 0 && p < 4294967295)
        printf("%d %d", r, p);
    else
        printf("There is no palindrome.");    
}