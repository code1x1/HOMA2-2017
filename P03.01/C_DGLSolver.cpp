#include "C_DGLSolver.h"

CMyVector C_DGLSolver::ableitungen(CMyVector y, double x)
{
	return CMyVector();
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

C_DGLSolver::~C_DGLSolver()
{
}
