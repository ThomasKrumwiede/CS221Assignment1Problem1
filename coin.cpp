#include <iostream>
#include <set>
#include "coin.h"
using namespace std;

coin::coin(string name, double value)
{
	coinType = name;
	coinValue = value;
}

bool coin::operator<(const coin& other) const {
	return coinValue < other.coinValue;
}