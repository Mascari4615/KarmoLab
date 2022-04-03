#include "multyPoly.h"

polynomial multyPoly(polynomial A, polynomial B)
{
    polynomial C;
    int A_degree = A.degree, B_degree = B.degree;
    C.degree = A_degree + B_degree;

    for (int i = 0; i < A_degree + 1; i++)
        for (int j = 0; j < B_degree + 1; j++)
            C.coef[i + j] += A.coef[i] * B.coef[j];

    return C;
}

void printPoly(polynomial P)
{
    int i, degree;
    degree = P.degree;

    for (i = 0; i <= P.degree; i++)
    {
        printf("%3.0fx^%d", P.coef[i], degree--);
        if (i < P.degree)
            printf(" +");
    }
    printf("\n");
}
