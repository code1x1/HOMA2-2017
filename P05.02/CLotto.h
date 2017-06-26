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
	int einzelZiehung();
	int doppelZiehung();
	bool schreibeTipp(int x);
	CLotto(int n);
	~CLotto();
};

