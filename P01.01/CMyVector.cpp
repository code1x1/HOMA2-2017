#include "CMyVector.h"



CMyVector::CMyVector(int s): size(s)
{
	a = new double[s];
}


CMyVector::~CMyVector()
{
	delete a;
}

int CMyVector::getSize()
{
	return size;
}

double CMyVector::operator()(int i)
{
	if (i < size)
	{
		return a[i];
	}
	else
	{
		throw("Error");
	}
}

double& CMyVector::operator[](int i)
{
	if (i < size)
	{
		return a[i];
	}
	else
	{
		throw("Error");
	}
	
}
