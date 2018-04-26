#pragma once
class CMyVector
{
private:
	int size;
	double *elem;
public:
	CMyVector(int s);
	CMyVector();
	~CMyVector();
	int getSize();
	void setSize(int s);
	double operator()(int i);
	double& operator[](int i);
	CMyVector& operator=(CMyVector& b);
	CMyVector& operator=(CMyVector* b);
	CMyVector(CMyVector & b);
	double length();
};

CMyVector operator+(CMyVector a, CMyVector b);
CMyVector operator*(double lambda, CMyVector a);




