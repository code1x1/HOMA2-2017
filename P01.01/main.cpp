#include<iostream>
#include<math.h>
#include"CMyVector.h"
using namespace std;



// Stellt sozusagen die Steigung in allen Richtungen da
CMyVector gradient(CMyVector x, double(*funktion)(CMyVector x))
{
	const double h = 10e-8;
	CMyVector x2 = CMyVector(x.getSize());
	CMyVector x3 = CMyVector(x.getSize());
	
	for (int i = 0; i < x.getSize(); i++)
		x2[i] = x(i);

	for (int i = 0; i < x.getSize(); i++)
	{
		x2[i] = x(i) + h;
		x3[i] = (funktion(x2) - funktion(x)) / h;
		x2[i] = x(i);
	}

	return x3;
}

// Gibt länge des Vektors zurück
double VectorLength(CMyVector x) {
	double erg = 0.0;
	for (int i = 0; i < x.getSize(); i++)
	{
		erg += (x(i) * x(i));
	}
	erg = sqrt(erg);

	return erg;
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


int main()
{
	const char tab = '\t';
	CMyVector x = CMyVector(2);
	x[0] = 3;
	x[1] = 3;
	double lambda = 1.0;
	CMyVector grad = CMyVector(2);

	for (int i = 0;; i++)
	{
		grad = gradient(x, *fx);
		if (i == 0)
		{
			cout << "Berechnungen beim Gradientenverfahren zur Testfunktion f:" << endl << endl;
		}

		if (VectorLength(grad) < 10e-5) 
		{
			cout << "Ende wegen Laenge grad < 10e-5" << endl;
		}
		else if (!(i < 50))
		{
			cout << "Ende wegen Schrittanzahl = 50 bei " << endl;
		}
		else
		{
			cout << "Schritt " << i << ":" << endl;
		}
			
		cout << "\t" << "lambda = " << lambda << endl;
		cout << "\t" << "f(x) = " << fx(x) << endl;
		cout << "\t" << "grad f(x) = ( " << grad(0) << ";" << grad(1) << ")" << endl;
		cout << "\t" << "|grad f(x)| = " << VectorLength(grad) << endl;
		CMyVector xneu = x + lambda * grad;

		cout << "x_neu = ( " << xneu(0) << "; " << xneu(1) << ")" << endl;
		cout << "f(x_neu) = " << fx(xneu) << endl;
		if (fx(xneu) > fx(x)) 
		{
			CMyVector xtest = x + (2. * lambda) * grad;
			if (fx(xtest) > fx(xneu))
			{
				x = xtest;
				lambda *= 2.;
				cout << "Test mit doppelter Schrittweite(lambda = " << lambda << ") :" << endl;
				cout << "x_test = ( " << xtest(0) << "; " << xtest(1) << ")" << endl;
				cout << "f(x_test) = " << fx(xtest) << endl;
			}
			else
			{
				x = xneu;
			}
		}
		else if (fx(xneu) <= fx(x))
		{
			do
			{
				lambda *= 0.5;
				xneu = x + lambda * grad;
			} while (fx(xneu) > fx(x));
			x = xneu;
		}

#pragma region Abbruch
		if (VectorLength(grad) < 10e-5)
		{
			break;
		}
		else if (!(i < 50))
		{
			break;
		}
#pragma endregion Abbruch

	}

	system("PAUSE");
	return 0;
}