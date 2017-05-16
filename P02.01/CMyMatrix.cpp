#include "CMyMatrix.h"
#include<algorithm>


CMyMatrix::CMyMatrix(const int m, const int n): zeile(m), spalte(n)
{
	elem = new CMyVector[zeile];
	for (int i = 0; i < zeile; i++)
	{
		elem[i].setSize(spalte);
	}
}

CMyMatrix::CMyMatrix(CMyMatrix& b)
{
	zeile = b.getZeile();
	spalte = b.getSpalte();
	elem = new CMyVector[zeile];
	for (int i = 0; i < zeile; i++)
	{
		elem[i].setSize(b[i].getSize());
		for (int j = 0; j < spalte; j++)
		{
			elem[i][j] = b[i](j);
		}
	}
}

double CMyMatrix::operator()(int i, int j)
{
	return elem[i](j);
}

CMyVector& CMyMatrix::operator[](int i)
{
	return elem[i];
}

int CMyMatrix::getZeile()
{
	return zeile;
}

int CMyMatrix::getSpalte()
{
	return spalte;
}

double CMyMatrix::determinante()
{
	return (elem[0](0) * elem[1](1))
		- (elem[0](1) * elem[1](0));
}

bool CMyMatrix::invers()
{
	if (determinante() != 0)
	{
		CMyMatrix tmp = *this;
		std::swap(tmp[0][0], tmp[1][1]);
		tmp[0][1] *= -1;
		tmp[1][0] *= -1;
		*this = (1 / determinante()) * tmp;
		return true;
	}
	return false;
}

CMyMatrix::~CMyMatrix()
{
}

CMyMatrix operator*(double lambda, CMyMatrix a)
{
	for (int i = 0; i < a.getZeile(); i++)
	{
		a[i] = lambda * a[i];
	}
	return a;
}

CMyVector operator*(CMyMatrix A, CMyVector x) 
{
	CMyVector erg(A.getZeile());
	for (int i = 0; i < A.getZeile(); i++)
	{
		erg[i] = A[i] * x;
	}
	return erg;
}

std::ostream& operator<<(std::ostream& stream,CMyMatrix M)
{
	for (int i = 0; i < M.getZeile(); i++)
	{
		stream << "( ";
		CMyVector tmp = M[i];
		for (int j = 0; j < M.getSpalte(); j++)
		{
			stream << tmp(j) << (j == M.getSpalte() - 1 ? "" : ", ");
		}
		stream << ")\n";
	}
	return stream;
}


CMyMatrix jacobi(CMyVector x, CMyVector(*funktion)(CMyVector x))
{
	CMyMatrix Jf();

}
