#include<iostream>
#include<math.h>
#include"C_DGLSolver.h"

using namespace std;

CMyVector dlg_erster(CMyVector y, double x) 
{

	CMyVector erg(2);
	erg[0] = 2 * y(1) - x * y(0);
	erg[1] = y(0) * y(1) - 2 *x*x*x;
	return erg;
}

double dgl_dritter(CMyVector y, double x)
{
	return 2 * x*y(1)*y(2) + 2 * y(0)*y(0)*y(1);
}

int main()
{

	//double x = 0;
	//CMyVector y_start(2);
	//y_start[0] = 0;
	//y_start[1] = 1;
	//C_DGLSolver test(dlg_erster);
	//test.euler(x, 2, 100, y_start);
	
	C_DGLSolver solver(dgl_dritter);
	CMyVector vec(3);
	vec[0] = 1;
	vec[1] = -1;
	vec[2] = 2;
	solver.euler(1, 2, 10, vec);



	system("pause");
}