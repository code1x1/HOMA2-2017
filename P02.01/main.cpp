#include<iostream>
#include<math.h>
#include"CMyMatrix.h"

using namespace std;

CMyVector f2(CMyVector x)
{
	
	double x1 = x(0), x2 = x(1), x3 = x(2), x4 = x(3);
	CMyVector erg(3);
	erg[0] = x1*x2*exp(x3);
	erg[1] = x2*x3*x4;
	erg[2] = x4;
	return erg;
}
CMyVector f3(CMyVector xV)
{

	double x = xV(0), y = xV(1);
	CMyVector erg(2);
	erg[0] = (pow(x,3) * pow(y,3)) - (2 * y);
	erg[1] = x - 2;
	
	return erg;
}

void newtonVerfahren(CMyVector x, CMyVector(*funktion)(CMyVector x))
{
	
	for (int i = 0; i < 50; i++)
	{
		cout << "Schritt " << i << ":\n";
		cout << "\tx =" << x << endl;
		cout << "\tf(x) =" << funktion(x) << endl;
		CMyMatrix jk = jacobi(x, funktion);
		cout << "\tf'(x) =" << jk << endl;
		if (jk.invers())
			cout << "\t(f'(x))^(-1) =" << jk << endl;
		else
			return;
		CMyVector dx = -1* jk * funktion(x);
		cout << "\tdx =" << dx << endl;
		cout << "\t||f(x)|| = " << VecLength(funktion(x)) << endl;
		if (VecLength(funktion(x)) < 10e-5)
			return;

		x = x + dx;
		
	}
}

int main()
{
	//Aufgabe 2 jakobi Matrix
	{
		CMyMatrix M(4, 3);
		CMyVector x(4);
		x[0] = 1;
		x[1] = 2;
		x[2] = 0;
		x[3] = 3;
		M = jacobi(x, f2);
		cout << M << endl;
	}
	
	//Aufgabe 2 test mit funktion aus Aufgabe 3
	{
		CMyVector x(2);
		x[0] = 1;
		x[1] = 1;
		cout << jacobi(x, f3) << endl;
	}

	//Aufgabe 3 Newton Verfahren
	{
		CMyVector x(2);
		x[0] = 1;
		x[1] = 1;
		newtonVerfahren(x,f3);
	}

	system("PAUSE");
	return 0;
}