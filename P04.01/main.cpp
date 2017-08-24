#include"CEinAusgabe.h"
#include<iostream>


using namespace std;

int main(int argc, char* argv) 
{
	vector<CKomplex> werte = werte_einlesen("Praktikum4_Daten_original.txt");
	for each (CKomplex k in werte)
	{
		cout << k.re() << " " << k.im() << endl;
	}
	cin.get();
}