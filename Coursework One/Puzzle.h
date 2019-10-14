#pragma once
#include "MatrixTemplate.h"
#include <vector>

using namespace std;

class Puzzle {
public:
	Puzzle();
	virtual ~Puzzle();
	virtual unsigned int getMatrixSize() const { return matrixSize; }
	virtual Matrix<int>* getPuzzle() const { return puzzle; }	
	virtual void printPuzzle();
protected:
	Matrix<int>* puzzle;
	const static unsigned int matrixSize = 4;
};