// Coursework One - Puzzle Factory Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include "Puzzle.h"
#include <random>
#include <string>
#include <vector>

using namespace std;

class PuzzleFactory {
public:
	PuzzleFactory();
	~PuzzleFactory();	
	Puzzle createGeneratedPattern(unsigned int size = defaultSize);
	Puzzle createUserPattern(unsigned int size = defaultSize);
	Puzzle createFilePattern(vector<unsigned int> fileInput);
private:
	const static unsigned int defaultStart = 1, defaultSize = 4;
	random_device randomDevice;
	mt19937 generation;
};