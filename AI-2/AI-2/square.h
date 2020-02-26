#include <string>
using namespace std;
#pragma once

enum state {EMPTY=0, RED=1, GREEN=2};

class square {
public:
	state color;
	square();
	square(state);
	void print();
	square& operator=(square&);
	bool operator == (square);
	bool operator != (square);
};