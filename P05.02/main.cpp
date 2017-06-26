#include"CZufall.h"
#include"CLotto.h"



int main() {

	CLotto lotto(-2);
	lotto.schreibeTipp(2);
	lotto.schreibeTipp(20);
	lotto.schreibeTipp(5);
	lotto.schreibeTipp(36);
	lotto.schreibeTipp(37);
	lotto.schreibeTipp(47);
	lotto.einzelZiehung();


	system("pause");
}