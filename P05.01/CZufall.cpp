#include "CZufall.h"


int CZufall::wert(int a, int b)
{
	return (rand() % (b - a + 1)) + a;
}

void CZufall::initialisiere(int n)
{
	srand(n);
}

std::vector<int> CZufall::test(int a, int b, int N)
{
	std::vector<int> v;
	v.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		v[i] = wert(a, b);
	}
	return v;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N)
{
	initialisiere(time(NULL));
	std::vector<int> v;
	v.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		v[i] = wert(a, b);
	}
	return v;
}
