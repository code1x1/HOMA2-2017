#include "CMyMatrix.h"


CMyMatrix::CMyMatrix(int m, int n): zeile(m), spalte(n)
{
	elem = new CMyVector[m];
}

CMyMatrix::~CMyMatrix()
{
}
