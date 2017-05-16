#pragma once
#include<iostream>

class CMyVector
{
private:
	int size;
	double *elem;
public:
	CMyVector(int s);
	CMyVector();
	~CMyVector(); // Könnte Fehler verursachen!?
	int getSize();
	void setSize(int s);
	double operator()(int i);
	double& operator[](int i);
	void operator=(CMyVector& b);
	CMyVector(CMyVector & b);
};

CMyVector operator+(CMyVector a, CMyVector b);
CMyVector operator-(CMyVector a, CMyVector b);
CMyVector operator*(double lambda, CMyVector a);
CMyVector operator/(CMyVector a, double lambda);
double operator*(CMyVector a, CMyVector b);

double VecLength(CMyVector x);
std::ostream& operator<<(std::ostream& stream, CMyVector x);


