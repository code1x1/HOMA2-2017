#pragma once
#include<vector>

class Tippzettel
{
	std::vector<int> zahlen;
	const unsigned int tipps = 6;
	int tippindex;
public:
	Tippzettel();
	~Tippzettel();
	bool schreibeWert(int x);
	bool wertSchonda(int x);
	std::vector<int> leseZettel();
};

