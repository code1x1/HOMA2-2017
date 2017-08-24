#include "CKomplex.h"
#include<math.h>

CKomplex::CKomplex()
{
}

CKomplex::CKomplex(double a, double b)
{
	this->a = a;
	this->b = b;
}

CKomplex::CKomplex(double phi)
{
	this->a = 1 * cos(phi);
	this->b = 1 * sin(phi);

}

double CKomplex::re()
{
	return a;
}

double CKomplex::im()
{
	return b;
}

double CKomplex::abs()
{
	return sqrt((a * a) + (b * b));
}

CKomplex::~CKomplex()
{
}

CKomplex operator+(CKomplex c1, CKomplex c2)
{
	CKomplex erg(c1.re() + c2.re(), c1.im() + c2.im());
	return erg;
}

CKomplex operator*(CKomplex c1, CKomplex c2)
{
	CKomplex erg(c1.re() * c2.re(), c1.im() * c2.im());
	return erg;
}

CKomplex operator*(double d, CKomplex c2)
{
	CKomplex erg(d * c2.re(), d * c2.im());
	return erg;
}
