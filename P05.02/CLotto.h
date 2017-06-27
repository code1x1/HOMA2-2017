#pragma once
#include"CZufall.h"
#include"Tippzettel.h"
#include<vector>

class CLotto
{
	Tippzettel tippzettel;
	CZufall zufallsgenerator;
	std::vector<int> simuliereZiehung();
public:
	int einzelZiehung(bool ausgabe = false);
	int doppelZiehung(bool ausgabe = false);
	bool schreibeTipp(int x);
	CLotto(int n);
	~CLotto();
};

