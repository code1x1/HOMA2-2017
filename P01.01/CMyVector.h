#pragma once
class CMyVector
{
private:
	int size;
	double *elem;
public:
	CMyVector(int s);
	~CMyVector();
	int getSize();
	double operator()(int i);
	double& operator[](int i);
};

CMyVector operator+(CMyVector a, CMyVector b);
CMyVector operator*(double lambda, CMyVector a);

double VecLength(CMyVector x);



