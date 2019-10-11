#pragma once
#include "MatrixTemplate.h"
#include <vector>
#include <random>

using namespace std;

class GeneratePuzzle {
public:
	GeneratePuzzle(unsigned int size);
	~GeneratePuzzle();
	Matrix<int>* getPuzzle() const{ return puzzle; }	
	void populatePuzzle(unsigned int start, unsigned int end);
protected:
	Matrix<int>* puzzle;
	int matrixSize;
	random_device randDev;
	mt19937 generation;
private:
	vector<int> generateSetOfNumbers(unsigned int start, unsigned int end);
};