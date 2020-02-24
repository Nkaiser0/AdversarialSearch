#include <string>
using namespace std;
#pragma once

enum state {EMPTY, RED, GREEN};

class square {
public:
	state color;
	square();
	square(state);
	void print();
	square operator = (square);
	bool operator == (square);
	bool operator != (square);
};