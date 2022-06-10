#include <stdio.h>
#include "stackL2.h"

int main(void)
{
    Program5_43();
    getchar(); return 0;
}

void Program5_43()
{
    char* string = "ABC";
    char* reverse = "   ";
    top = NULL;
    printf("\n** 문자열 역순으로 바꾸기 **\n");
    printStack();

    push(string[0]); printStack();
    push(string[1]); printStack();
    push(string[2]); printStack();

    reverse[0] = pop();
    reverse[1] = pop();
    reverse[2] = pop();

    printf("\t %s", reverse);
}