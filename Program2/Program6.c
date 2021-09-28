#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GetReverse(int origin)
{
    int reverse = 0;
    for (int temp = origin; temp > 0; temp /= 10)
    {
        reverse = (reverse * 10) + temp % 10;
    }
    return reverse;
}

int reverse_add(int origin)
{
    return origin + GetReverse(origin);
}

int is_palindrome(int num) 
{  
    if (num == GetReverse(num)) return 1;
    else return 0;    
}

void main() 
{
    int r = 0;
    unsigned int p = 0;
    printf("Please enter a number : "); scanf("%d", &p);

    while (r++ < 1000)
    {
        p = reverse_add(p);
        if (is_palindrome(p)) break;
    }
   
    if (r < 1000) printf("%d %d", r, p);
    else printf("There is no palindrome.");    
}