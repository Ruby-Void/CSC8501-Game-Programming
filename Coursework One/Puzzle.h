// Coursework One - Puzzle Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include "MatrixTemplate.h"
#include <vector>

using namespace std;

class Puzzle {
public:
	Puzzle();
	~Puzzle();
	Matrix<unsigned int>& getPuzzle() { return matrix; }
	vector<unsigned int> getPattern() { return pattern; }
	unsigned int getMatrixSize() const { return matrixSize; }
	void setPattern(vector<unsigned int> newPattern) { pattern = newPattern; }
	void createSolutions();
	string printPuzzle();
	string printPuzzleSolution();
private:
	const static unsigned int matrixSize = 4;
	Matrix<unsigned int> matrix;
	vector<unsigned int> pattern;
	unsigned int rowSolutions = 0; 
	unsigned int columnSolutions = 0;
	unsigned int reverseRowSolutions = 0;
	unsigned int reverseColumnSolutions = 0;
};