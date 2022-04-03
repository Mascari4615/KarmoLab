#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "multyPoly.h"

void Program21()
{
    polynomial A ={3,{4,3,5,0}};
    polynomial B = {4,{3,1,0,2,1}};
    polynomial C;

    C = multyPoly(A,B);

    printf("\n A(x) ="); printPoly(A);
    printf("\n B(x) ="); printPoly(B);
    printf("\n C(x) ="); printPoly(C);

    getchar(); return 0;
}

void main()
{
	Program21();
}