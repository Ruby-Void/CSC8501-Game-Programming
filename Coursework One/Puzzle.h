// Coursework One - Puzzle Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include <string>
#include <vector>

using namespace std;

class Puzzle {
public:
	Puzzle(vector<unsigned int> newPattern);
	~Puzzle();
	unsigned int getMatrixSize() const { return matrixSize; }
	void createStateSolution();
	unsigned long long createSolution(unsigned int partials);
	string printPuzzle();
	string printPuzzleSolution();
	void setGivenSolutions(unsigned int partial, unsigned long long value);
private:
	const static unsigned int defaultMatrix = 1, defaultPuzzleSize = 15;
	unsigned int twoSolutions = 0, threeSolutions = 0, fourSolutions = 0;
	unsigned int twoStateSolutions = 0, threeStateSolutions = 0, fourStateSolutions = 0;
	unsigned int matrixSize, puzzleSize;
	vector<unsigned int> pattern, orderedPattern;
	unsigned int factorial(unsigned int value);
};