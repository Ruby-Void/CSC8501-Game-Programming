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
	unsigned int getMatrixSize() const { return matrixSize; }
	void createSolutions();
	string printPuzzle();
	string printPuzzleSolution();
protected:
	const static unsigned int matrixSize = 4;
	Matrix<unsigned int> matrix;
	unsigned int rowSolutions, columnSolutions, reverseRowSolutions, reverseColumnSolutions;
};