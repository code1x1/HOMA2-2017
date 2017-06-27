#include"CZufall.h"
#include"CLotto.h"
#include<iostream>


int main() {

	CLotto lotto(-1);
	lotto.schreibeTipp(2);
	lotto.schreibeTipp(20);
	lotto.schreibeTipp(5);
	lotto.schreibeTipp(36);
	lotto.schreibeTipp(37);
	lotto.schreibeTipp(47);
	int montecarlo1 = 0;
	const int ZIEHUNG = 100000;
	for (size_t i = 0; i < ZIEHUNG; i++) {
		if (lotto.einzelZiehung() == 3) {
			montecarlo1++;
		}
	}

	std::cout << "dass eine Ziehung genau 3 uebereinstimmende Zahlen " <<
		"mit einem vorher festgelegten Tippzettel hat liegt bei: " <<
		(montecarlo1 / (long double)ZIEHUNG) << std::endl;


	int montecarlo2 = 0;
	for (size_t i = 0; i < ZIEHUNG; i++) {
		if (lotto.einzelZiehung() == 3) {
			montecarlo2++;
		}
	}

	std::cout << "dass zwei Ziehungen genau 3 uebereinstimmende Zahlen " <<
		"haben liegt bei: " << (montecarlo2 / (long double)ZIEHUNG) << std::endl;

	system("pause");
}