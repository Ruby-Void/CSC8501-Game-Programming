#pragma once
#include "Puzzle.h"
#include <random>

using namespace std;

class GeneratedPuzzle : public Puzzle {
public:
	GeneratedPuzzle();
	~GeneratedPuzzle();
	void populatePuzzle(unsigned int start = defaultStart, unsigned int end = defaultEnd);
protected:
	const static unsigned int defaultStart = 1, defaultEnd = 20;
	random_device randomDevice;
	mt19937 generation;	
	vector<unsigned int> generateSetOfNumbers(unsigned int start = defaultStart, unsigned int end = defaultEnd);
};