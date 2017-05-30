#include "C_DGLSolver.h"
#include<iostream>

using namespace std;

void C_DGLSolver::euler(double x_start, double x_end, int schritte, CMyVector y_Start)
{
	h = (x_end - x_start) / double(schritte);
	cout << "h = " << h << endl;
	CMyVector y(y_Start.getSize());
	CMyVector y_vorher = y_Start;
	for (int i = 0; i < schritte; i++)
	{
		for (size_t j = 0; j < y_vorher.getSize(); j++)
		{
			y[j] = y_vorher(j) + h *  ableitungen(y_vorher, x_start)[j];
		}
		CMyVector y_abgeleitet = ableitungen(y_vorher, x_start);

		cout << "Schritt " << i << ":\n";
		cout << "\tx = " << x_start << "\n";
		cout << "\ty = " << y_vorher;
		cout << "\ty' = " << y_abgeleitet;
		x_start += h;
		y_vorher = y;
	}
	cout << "Abweichung Euler fuer Schrittzahl " <<
		schritte << " : " << y(0) - 0.5;

}

void C_DGLSolver::heun(double x_start, double x_end, int schritte, CMyVector y_Start)
{
	h = (x_end - x_start) / double(schritte);
	cout << "h = " << h << endl;

	CMyVector y(y_Start.getSize());
	CMyVector y_vorher = y_Start;
	CMyVector y_test(y_Start.getSize());

	for (int i = 0; i < schritte; i++)
	{
		for (size_t j = 0; j < y_vorher.getSize(); j++)
		{
			y[j] = y_vorher(j) + h *  ableitungen(y_vorher, x_start)[j];
		}
		CMyVector y_abgeleitet = ableitungen(y_vorher, x_start);

		cout << "Schritt " << i << ":\n";
		cout << "\tx = " << x_start << ":\n";
		cout << "\ty = " << y;
		cout << "\ty' = " << y_abgeleitet;
		x_start += h;

		CMyVector s = 0.5 * (y_abgeleitet + ableitungen(y, x_start));
		CMyVector y_mittel(y_test.getSize());
		for (size_t j = 0; j < y_Start.getSize(); j++)
		{
			y_mittel[j] = y_vorher(j) + h * s(j);
		}

		

		y_vorher = y;
		cout << "\ty_test = " << y_test;
		cout << "\ty'_test = " << ableitungen(y_test, x_start);
		cout << "\ty'_mittel = " << y_mittel;

	}
	cout << "Abweichung Heun fuer Schrittzahl " <<
		schritte << " : " << y_vorher(0) - 0.5 << endl;

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