#pragma once
#include"CMyVector.h"
class C_DGLSolver
{
	double (*f_DGL_nterOrdnung)(CMyVector y, double x);
	CMyVector (*f_DGL_System)(CMyVector y, double x);
	CMyVector ableitungen(CMyVector y, double x);
	enum DGL_Type {System, nterOrdnung} type;
public:
	C_DGLSolver(CMyVector (*f_DGL_System)(CMyVector y, double x));
	C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVector y, double x));
	~C_DGLSolver();
};

