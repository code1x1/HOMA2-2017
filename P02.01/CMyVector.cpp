#include "CMyVector.h"
#include<math.h>

CMyVector::CMyVector(int s): size(s)
{
	elem = new double[s];
	for (int i = 0; i < s; i++)
	{
		elem[i] = 0.0;
	}
}

CMyVector::CMyVector() : size(0)
{
}

CMyVector::~CMyVector()
{
}

int CMyVector::getSize()
{
	return size;
}

void CMyVector::setSize(int s)
{
	size = s;
	elem = new double[size];
	for (int i = 0; i < size; i++)
	{
		elem[i] = 0.0;
	}
}

double CMyVector::operator()(int i)
{
	return elem[i];
}

double& CMyVector::operator[](int i)
{
	return elem[i];
}

void CMyVector::operator=(CMyVector& b)
{
	this->size = b.getSize();
	// TODO: hier Rückgabeanweisung eingeben
	for (int i = 0; i < b.getSize(); i++)
	{
		this->operator[](i) = b(i);
	}
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

CMyVector operator-(CMyVector a, CMyVector b)
{

	CMyVector tmp = CMyVector(a.getSize());

	for (int i = 0; i < tmp.getSize(); i++)
	{
		tmp[i] = a(i) - b(i);
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

CMyVector operator/(CMyVector a, double lambda)
{

	CMyVector tmp = CMyVector(a.getSize());

	for (int i = 0; i < tmp.getSize(); i++)
	{
		tmp[i] = a(i) / lambda;
	}

	return tmp;
}

double operator*(CMyVector a, CMyVector b)
{
	double erg = 0.0;
	for (int i = 0; i < a.getSize(); i++)
	{
		erg += a(i)*b(i);
	}
	return erg;
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

std::ostream& operator<<(std::ostream& stream, CMyVector x)
{
		stream << "( ";
		for (int j = 0; j < x.getSize(); j++)
		{
			stream << x(j) << (j == x.getSize() - 1 ? "" : ", ");
		}
		stream << ")\n";
	return stream;
}