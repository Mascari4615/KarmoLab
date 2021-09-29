#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int GetReverse(unsigned int origin)
{
    unsigned int reverse = 0;
    for (unsigned int temp = origin; temp != 0; temp /= 10)
    {
        reverse = (reverse * 10) + temp % 10;
    }
    return reverse;
}

void reverse_add(unsigned int * origin)
{
    *origin += GetReverse(*origin);
}

int is_palindrome(unsigned int num)
{  
    if (num == GetReverse(num)) return 1;
    else return 0;    
}

void main() 
{
    int r = 0;
    unsigned int p = 0;
    unsigned int * pPointer = &p;
    printf("Please enter a number : "); scanf("%d", &p);

    while (r++ < 1000)
    {
        reverse_add(pPointer);
        if (is_palindrome(p)) break;
    }
   
    if (r < 1000) printf("%d %d", r, p);
    else printf("There is no palindrome.");    
}