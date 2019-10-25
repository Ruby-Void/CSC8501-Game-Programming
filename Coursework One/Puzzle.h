// Coursework One - Puzzle Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Last Edited: 17-10-2019
#pragma once
#include "BigInt.h"
#include <string>
#include <vector>

using namespace std;

class Puzzle {
public:
	Puzzle(vector<unsigned int> newPattern);
	~Puzzle();
	unsigned int getMatrixSize() const { return matrixSize; }
	unsigned int createStateSolution(int partials);
	bigint createSolution(unsigned int partials);
	string printPuzzle();
	string printPuzzleSolution(vector<unsigned int> sequence);
	void setStateSolutions(unsigned int partial, unsigned int value);
	void setSolutions(unsigned int partial, bigint value);
private:
	const static unsigned int defaultMatrix = 1, defaultPuzzleSize = 15;
	bigint twoSolutions, threeSolutions, fourSolutions;
	unsigned int twoStateSolutions = 0, threeStateSolutions = 0, fourStateSolutions = 0;
	unsigned int matrixSize, tileSet;
	vector<unsigned int> pattern, orderedPattern;
	bigint factorial(unsigned int value);
};