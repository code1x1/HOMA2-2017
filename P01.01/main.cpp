#include<iostream>
#include"CMyVector.h"
using namespace std;

int main()
{
	CMyVector mv = CMyVector(4);
	mv[0] = 3.3;
	mv[1] = 2.3;
	mv[3] = 5.3;

	cout << mv(3);

	system("PAUSE");
	return 0;
}