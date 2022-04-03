#include <stdio.h>
#include "addPoly.h"

int main(void)
{
    polynomial A ={3,{4,3,5,0}};
    polynomial B = {4,{3,1,0,2,1}};
    polynomial C;

    C = addPoly(A,B);

    printf("\n A(x) ="); printPoly(A);
    printf("\n B(x) ="); printPoly(B);
    printf("\n C(x) ="); printPoly(C);

    getchar(); return 0;
}