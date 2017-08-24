#pragma once 
#include <vector>
#include"CKomplex.h"

std::vector<CKomplex>  werte_einlesen(char *dateiname);
void werte_ausgeben(char *dateiname, std::vector<CKomplex> werte, double epsilon = -1);