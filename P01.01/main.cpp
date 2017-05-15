#include<iostream>
#include<math.h>
#include"CMyVector.h"
using namespace std;



// Stellt sozusagen die Steigung in allen Richtungen da
CMyVector gradient(CMyVector x, double(*funktion)(CMyVector x))
{
	const double h = 10e-8;
	
	CMyVector g = CMyVector(x.getSize());

	for (int i = 0; i < x.getSize(); i++)
	{
		CMyVector x2 = x;
		x2[i] = x(i) + h;
		g[i] = (funktion(x2) - funktion(x)) / h;
	}

	return g;
}

ostream& operator<<(ostream& stream, CMyVector x) 
{
	stream << "( ";
	for (size_t i = 0; i < x.getSize(); i++)
		stream << x(i) << (i == x.getSize() - 1 ? ")" : ", ");
	return stream;
}

double f(CMyVector x) 
{
	return sin(x(0) + pow(x(1), 2)) + pow(x(1), 3) - 6 * pow(x(1), 2) + 9 * x(1);
}

double g(CMyVector x)
{
	return 0.0;
}

double fx(CMyVector x) {
	return f(x);
}

void verfahren(CMyVector x, double(*funktion)(CMyVector x), double lambda = 1.0) {

	cout << "Berechnungen beim Gradientenverfahren zur Testfunktion f:" << endl << endl;


	for (int i = 0;i <= 50; i++)
	{
		cout << "Schritt " << i << ":" << endl;
		cout << "x = " << x << endl;
		cout << "f(x) = " << funktion(x) << endl;
		cout << "lambda = " << lambda << endl;
		cout << "grad f(x) = " << gradient(x, funktion) << endl;
		cout << "||grad f(x)|| = " << VecLength( gradient(x, funktion)) << endl;
		
		CMyVector x_neu = x + lambda * gradient(x, funktion);
		
		if (funktion(x_neu) > funktion(x))
		{
			CMyVector x_test = x + 2 * lambda * gradient(x, funktion);
			if (funktion(x_test) > funktion(x_neu))
			{
				lambda *= 2.;
				x = x_test;
			}
			else
				x = x_neu;
		}
		else
		{
			do
			{
				lambda *= 0.5;
				x_neu = x + lambda * gradient(x, funktion);
			} while (funktion(x_neu)>funktion(x));
			x = x_neu;
		}

#pragma region Abbruch
		if (i > 49 || VecLength(x) < 10e-5)break;
#pragma endregion Abbruch

	}
}


int main()
{
	
	CMyVector x = CMyVector(2);
	x[0] = 3;
	x[1] = 2;
	double lambda = 1.0;
	
	verfahren(x, fx);


	system("PAUSE");
	return 0;
}