#include "C_DGLSolver.h"
#include<iostream>

using namespace std;

double C_DGLSolver::euler(double x_start, double x_end, int schritte, CMyVector y_Start, bool ausgabe)
{
	double h = (x_end - x_start) / double(schritte);
	if(ausgabe)
		cout << "h = " << h << "\n\n\n";
	CMyVector y(y_Start.getSize());
	CMyVector y_vorher = y_Start;
	for (int i = 0; i < schritte; i++)
	{
		y = y_vorher + h *  ableitungen(y_vorher, x_start);	
		CMyVector y_abgeleitet = ableitungen(y_vorher, x_start);
		if (ausgabe) 
		{
			cout << "Schritt " << i << ":\n";
			cout << "\tx = " << x_start << "\n";
			cout << "\ty = " << y_vorher;
			cout << "\ty' = " << y_abgeleitet << "\n";
		}
		x_start += h;
		y_vorher = y;
	}
	if (ausgabe)
	{
		cout << "Ende bei\n";
		cout << "\tx = " << x_start << "\n";
		cout << "\ty = " << y << "\n";
	}

	/*cout << "Abweichung Euler fuer Schrittzahl " <<
		schritte << " : " << y(0) - 0.5;*/
	return (y(0) - 0.5);

}

double C_DGLSolver::heun(double x_start, double x_end, int schritte, CMyVector y_Start, bool ausgabe)
{
	double h = (x_end - x_start) / double(schritte);
	int d = y_Start.getSize();
	double x_neu = x_start, x_alt;
	CMyVector y_neu = y_Start, y_hilf(d), s(d), steigung(d);
	if (ausgabe)
		cout << "h = " << h << "\n\n\n";
	for (int i = 0; i < schritte; i++)
	{
		y_hilf = y_neu;
		if (ausgabe)
		{
			cout << "Schritt " << i << ":\n";
			cout << "\tx = " << x_neu << "\n";
			cout << "\ty = " << y_hilf;
			cout << "\ty' = " << ableitungen(y_hilf, x_neu);
		}


		y_neu = y_neu + h * ableitungen(y_neu, x_neu);
		x_alt = x_neu;
		x_neu += h;
		steigung = ableitungen(y_neu, x_neu);
		s = 0.5 * (ableitungen(y_hilf, x_alt) + steigung);
		if (ausgabe)
		{
			cout << "\n\ty_test = " << y_neu;
			cout << "\ty'_test = " << ableitungen(y_neu, x_neu);
			cout << "\n\ty'_mittel = " << s << "\n";
		}

		y_neu = y_hilf + h * s;
	}
	if (ausgabe)
	{
		cout << "Ende bei\n";
		cout << "\tx = " << x_neu << "\n";
		cout << "\ty = " << y_neu << "\n";
	}


	/*cout << "Abweichung Heun fuer Schrittzahl " <<
		schritte << " : " << y_neu(0) - 0.5 << endl;*/
	return (y_neu(0) - 0.5);
}

CMyVector C_DGLSolver::ableitungen(CMyVector y, double x)
{

	if (this->type == System)
	{
		return this->f_DGL_System(y,x);
	}
	else if (this->type == nterOrdnung)
	{
		return this->transform(y, x);
	}
}

CMyVector C_DGLSolver::transform(CMyVector y, double x)
{
	CMyVector erg(y.getSize());

	for (size_t i = 0; i < y.getSize() - 1; i++)
	{
		erg[i] = y(i + 1);
	}
	erg[y.getSize() - 1] = f_DGL_nterOrdnung(y,x);

	return erg;

}

C_DGLSolver::~C_DGLSolver()
{
}

C_DGLSolver::C_DGLSolver(CMyVector(*f_DGL_System)(CMyVector y, double x))
{
	this->f_DGL_System = f_DGL_System;
	this->type = System;
}

C_DGLSolver::C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVector y, double x))
{
	this->f_DGL_nterOrdnung = f_DGL_nterOrdnung;
	this->type = nterOrdnung;
}