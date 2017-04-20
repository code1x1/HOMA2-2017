#pragma once
class CMyVector
{
private:
	int size;
	double *a;
public:
	CMyVector(int s);
	~CMyVector();
	int getSize();
	double operator()(int i);
	double& operator[](int i);
};

