// Generate Puzzle Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 14/10/2019
#pragma once
#include "MatrixTemplate.h"
#include <vector>
#include <random>

using namespace std;

class GeneratePuzzle {
public:
	GeneratePuzzle(unsigned int config);
	~GeneratePuzzle();
	const vector<Matrix<unsigned int>*>& getPuzzleConfigurations() const { return puzzleConfigurations; }
	unsigned int getMatrixSize() const { return matrixSize; }
	void populatePuzzle(unsigned int start = defaultStart, unsigned int end = defaultEnd);
protected:
	unsigned int configurations;
	vector<Matrix<unsigned int>*> puzzleConfigurations;	
private:
	const static unsigned int matrixSize = 4, defaultStart = 1, defaultEnd = 20;
	vector<unsigned int> generateSetOfNumbers(unsigned int start = defaultStart, unsigned int end = defaultEnd);
	random_device randomDevice;
	mt19937 generation;
};