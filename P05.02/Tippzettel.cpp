#include "Tippzettel.h"


Tippzettel::Tippzettel()
{
	zahlen.resize(6);
	tippindex = 0;
}


Tippzettel::~Tippzettel()
{
}

bool Tippzettel::schreibeWert(int x)
{
	if(tippindex < tipps && !wertSchonda(x)) {

		zahlen[tippindex] = x;
		tippindex++;
		return true;
	}
	return false;
}

bool Tippzettel::wertSchonda(int x)
{
	for (size_t i = 0; i < zahlen.size(); i++)
	{
		if (zahlen.at(i) == x)
			return true;
	}
	return false;
}

std::vector<int> Tippzettel::leseZettel()
{
	return zahlen;
}
