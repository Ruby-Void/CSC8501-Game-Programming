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
	Puzzle createGeneratedPattern(unsigned int start = defaultStart, unsigned int end = defaultEnd);
	Puzzle createUserPattern();
	Puzzle createFilePattern(vector<unsigned int> fileInput);
private:
	const static unsigned int puzzleSize = 15, defaultStart = 1, defaultEnd = 20;
	random_device randomDevice;
	mt19937 generation;
	Puzzle createPuzzle(vector<unsigned int> pattern);
};