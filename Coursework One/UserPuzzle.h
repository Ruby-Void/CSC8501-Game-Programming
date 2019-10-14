#pragma once
#include "Puzzle.h"
#include <string>

using namespace std;

class UserPuzzle : public Puzzle {
public:
	UserPuzzle();
	~UserPuzzle();
	void populatePuzzle();
protected:
	unsigned int getIntegerInput(string message);
};