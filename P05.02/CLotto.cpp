#include"CLotto.h"
#include<iostream>

using namespace std;

void print_haufigkeit(int a, int b, vector<int> vec) {

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

void print_numbers(vector<int> vec) {

	for (size_t j = 0; j < vec.size(); j++) {

		cout << vec[j] << (j != vec.size() - 1 ? ", " : "");
	}

	cout << endl << endl << endl;
}

int anzahlGleich(std::vector<int> v1, std::vector<int> v2) {
	int anz = 0;
	for (size_t i = 0; i < v1.size(); i++)
	{
		for (size_t j = 0; j < v2.size(); j++)
		{
			if (v1.at(i) == v2.at(j)) anz++;
		}
	}
	return anz;
}

inline bool elementeDoppelt(std::vector<int> v) {
	int merke;
	for (int i = 0; i < v.size(); i++) {
		merke = v.at(i);
		for (size_t j = 0; j < v.size(); j++) {
			if (j != i && v.at(j) == merke) {
				return true;
			}
		}
	}
	return false;
}

std::vector<int> CLotto::simuliereZiehung() {
	std::vector<int> ziehung;
	ziehung = zufallsgenerator.test(1, 49, 6);
	while (elementeDoppelt(ziehung))
	{
		ziehung = zufallsgenerator.test(1, 49, 6);
	}
	return ziehung;
}

int CLotto::einzelZiehung(bool ausgabe) {
	std::vector<int> ziehung;
	ziehung = simuliereZiehung();
	if (ausgabe) {
		print_numbers(ziehung);
		print_numbers(tippzettel.leseZettel());
		cout << "Uebereinstimmungen: " << anzahlGleich(ziehung, tippzettel.leseZettel());
	}
	return anzahlGleich(ziehung, tippzettel.leseZettel());
}

int CLotto::doppelZiehung(bool ausgabe) {
	std::vector<int> ziehung1, ziehung2;
	ziehung1 = simuliereZiehung();
	ziehung2 = simuliereZiehung();
	if(ausgabe) {
		print_numbers(ziehung1);
		print_numbers(ziehung2);
		cout << "Uebereinstimmungen: " << anzahlGleich(ziehung1, ziehung2);
	}
	return anzahlGleich(ziehung1, ziehung2);
}

bool CLotto::schreibeTipp(int x) {
	return tippzettel.schreibeWert(x);
}

CLotto::CLotto(int n) {
	if (n < 0)
		zufallsgenerator.initialisiere(int(time(NULL)));
	else
		zufallsgenerator.initialisiere(n);
}


CLotto::~CLotto() {
}
