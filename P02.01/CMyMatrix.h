#pragma once
#include"CMyVector.h"
#include<iostream>

class CMyMatrix
{
	int zeile, spalte;
	CMyVector* elem;
	double determinante();
public:
	// Zeile , Spalte
	CMyMatrix(int n, int m);
	CMyMatrix(CMyMatrix& b);
	double operator()(int i, int j);
	CMyVector& operator[](int i);
	int getZeile();
	int getSpalte();
	bool invers();
	~CMyMatrix();
};

CMyMatrix operator*(double lambda, CMyMatrix a);
CMyVector operator*(CMyMatrix A, CMyVector x);
std::ostream& operator<<(std::ostream& stream, CMyMatrix M);
CMyMatrix jacobi(CMyVector x, CMyVector(*funktion)(CMyVector x));
