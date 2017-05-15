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

CMyVector& CMyVector::operator=(CMyVector& b)
{
	CMyVector a(b.getSize());
	// TODO: hier Rückgabeanweisung eingeben
	for (size_t i = 0; i < b.getSize(); i++)
	{
		a[i] = b(i);
	}
	return a;
}

CMyVector & CMyVector::operator=(CMyVector * b)
{
	CMyVector a(b->getSize());
	// TODO: hier Rückgabeanweisung eingeben
	for (size_t i = 0; i < b->getSize(); i++)
	{
		a[i] = b->operator()(i);
	}
	return a;
}

CMyVector::CMyVector(CMyVector& b)
{
	size = b.getSize();
	elem = new double[size];
	for (int i = 0; i < size; i++)
	{
		elem[i] = b(i);
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

// Gibt länge des Vektors zurück
double VecLength(CMyVector x) {
	double erg = 0.0;
	for (int i = 0; i < x.getSize(); i++)
	{
		erg += (x(i) * x(i));
	}
	return sqrt(erg);
}

	