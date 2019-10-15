#pragma once
#include "MatrixTemplate.h"
#include <vector>

using namespace std;

class Puzzle {
public:
	Puzzle();
	~Puzzle();
	Matrix<int>& getPuzzle() { return matrix; }
	unsigned int getMatrixSize() const { return matrixSize; }
	void createSolutions();
	string printPuzzle();
	string printPuzzleSolution();
protected:
	const static unsigned int matrixSize = 4;
	Matrix<int> matrix;
	unsigned int rowSolutions, columnSolutions, reverseRowSolutions, reverseColumnSolutions;
};