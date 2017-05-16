#include<iostream>
#include"CMyMatrix.h"

using namespace std;

int main()
{

	CMyMatrix M(2, 2);
	M[0][0] = 2;
	M[1][1] = 3;
	M[0][1] = -4;
	M[1][0] = 5;
	cout << M << endl;
	if (M.invers())
		cout << M << endl;


	system("PAUSE");
	return 0;
}