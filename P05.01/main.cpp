#include"CZufall.h"
#include<iostream>

using namespace std;

void print_numvec(int a, int b, vector<int> vec) {
	
	for (size_t i = a; i <= b; i++)
		cout << i << (i != b ? " \t|" : "");
	cout << endl;
	for (size_t i = a; i <= b; i++)
		cout << "-------";
	cout << endl;
	for (size_t i = a; i <= b; i++) {
		int anz = 0;
		for (size_t j = 0; j < vec.size(); j++)
		{
			if (vec[j] == i) anz++;
		}
		cout << anz << (i != b ? " \t|" : "");
	}
	cout << endl << endl << endl;
}


int main() {

	////Aufgabe 1a)
	//cout << "1a:" << endl;
	//CZufall zufall_1a;
	//zufall_1a.initialisiere(5);
	//vector<int> erg_1a;
	//erg_1a = zufall_1a.test(3, 7, 10000);
	//print_numvec(3, 7, erg_1a);


	////Aufgabe 1b)
	//cout << "1b:" << endl;
	//CZufall zufall_1b;
	//for(int i = 0; i<10; i++) {
	//	zufall_1b.initialisiere(5);
	//	vector<int> erg_1b;
	//	erg_1b = zufall_1a.test(3, 7, 10000);
	//	print_numvec(3, 7, erg_1b);
	//}

	////Aufgabe 1c)
	//cout << "1c:" << endl;
	//CZufall zufall_1c;
	//for (int i = 423; i< 423+10; i++) {
	//	zufall_1c.initialisiere(i);
	//	vector<int> erg_1c;
	//	erg_1c = zufall_1c.test(3, 7, 10000);
	//	print_numvec(3, 7, erg_1c);
	//}

	////Aufgabe 1d)
	//cout << "1d:" << endl;
	//CZufall zufall_1d;
	//for(int i = 0; i<100; i++) {
	//	zufall_1d.initialisiere(time(NULL));
	//	vector<int> erg_1d;
	//	erg_1d = zufall_1d.test(3, 7, 10000);
	//	print_numvec(3, 7, erg_1d);
	//}

	//Aufgabe 1e)
	cout << "1e:" << endl;
	CZufall zufall_1e;
	vector<int> erg_1e;
	erg_1e = zufall_1e.test_falsch(3, 7, 10000);
	print_numvec(3, 7, erg_1e);


	system("pause");
}