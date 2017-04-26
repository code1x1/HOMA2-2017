#include "CMyVector.h"
#include<math.h>
#include<iostream>
CMyVector::CMyVector(int s): size(s)
{
	elem = new double[s];
	for (int i = 0; i < s; i++)
	{
		elem[i] = 0.0;
	}
}

CMyVector::~CMyVector()
{
}

int CMyVector::getSize()
{
	return size;
}

double CMyVector::operator()(int i)
{
	if (i < size)
	{
		return elem[i];
	}
	else
	{
		throw("Indexfehler");
	}
}

double& CMyVector::operator[](int i)
{
	if (i < size)
	{
		return elem[i];
	}
	else
	{
		throw("Indexfehler");
	}
	
}

CMyVector operator+(CMyVector a, CMyVector b)
{

	CMyVector tmp = CMyVector(a.getSize());

	for (int i = 0; i < tmp.getSize(); i++)
	{
		tmp[i] = a(i) + b(i);
	}

	return tmp;
}

CMyVector operator*(double lambda, CMyVector a)
{

	CMyVector tmp = CMyVector(a.getSize());

	for (int i = 0; i < tmp.getSize(); i++)
	{
		tmp[i] = lambda * a(i);
	}

	return tmp;
}


	