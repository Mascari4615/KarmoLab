#pragma once
typedef struct
{
	int row;
	int col;
	int value;
} term;

void smTranspose(term a[], term b[]);