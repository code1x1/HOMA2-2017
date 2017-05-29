#include "C_DGLSolver.h"
#include<iostream>

void C_DGLSolver::euler(double x_start, double x_end, int schritte, CMyVector y_Start)
{
	h = (x_end - x_start) / double(schritte);
	CMyVector y_unabgeleitet(y_Start.getSize());
	std::cout << "h = " << h << std::endl;
	CMyVector y_vorher = y_Start;
	for (int i = 0; i < schritte; i++)
	{
		for (size_t j = 0; j < y_vorher.getSize(); j++)
		{
			y_unabgeleitet[j] = y_vorher(j) + h *  ableitungen(y_vorher, x_start)[j];
		}
		CMyVector y_abgeleitet = ableitungen(y_vorher, x_start);

		std::cout << "Schritt " << i << ":\n";
		std::cout << "\tx = " << x_start << "\n";
		std::cout << "\ty = " << y_unabgeleitet << "\n";
		std::cout << "\ty' = " << y_abgeleitet << "\n";
		x_start += h;
		y_vorher = y_unabgeleitet;
	}
	std::cout << "Abweichung Euler für Schrittzahl " <<
		schritte << " : " << y_unabgeleitet(0) - 0.5;

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