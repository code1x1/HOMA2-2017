#pragma once
#include"CMyVector.h"

class CMyMatrix
{
	int zeile, spalte;
	CMyVector* elem;
public:
	CMyMatrix(int n, int m);
	~CMyMatrix();
};

