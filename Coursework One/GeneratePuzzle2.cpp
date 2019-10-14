// Generate Puzzle Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 14/10/2019
#include "GeneratePuzzle2.h"
#include <algorithm>
#include <numeric>

GeneratePuzzle::GeneratePuzzle(unsigned int config) :
	configurations(config), generation(randomDevice()) {
}

GeneratePuzzle::~GeneratePuzzle() {
	for (Matrix<unsigned int>* puzzle : puzzleConfigurations) {
		delete puzzle;
	}
}

vector<unsigned int> GeneratePuzzle::generateSetOfNumbers(unsigned int start, unsigned int end) {
	const unsigned int puzzleSize = 15;
	vector<unsigned int> randomVector(end);
	iota(randomVector.begin(), randomVector.end(), start);
	shuffle(randomVector.begin(), randomVector.end(), generation);
	randomVector.erase(randomVector.begin() + puzzleSize, randomVector.end());
	return randomVector;
}

void GeneratePuzzle::populatePuzzle(unsigned int start, unsigned int end) {	
	for (int i = 0; i < configurations; i++) {
		vector<unsigned int> numberSet = generateSetOfNumbers(start, end);
		Matrix<unsigned int>* puzzle = new Matrix<unsigned int>(matrixSize, matrixSize);

		unsigned int counter = 0;
		for (unsigned int row = 0; row < matrixSize; row++) {
			for (unsigned int column = 0; column < matrixSize; column++) {
				puzzle->setElement(row, column, (row == 3 && column == 3) ? NULL : numberSet.at(counter));
				counter++;
			}
		}
		puzzleConfigurations.push_back(puzzle);
	}
}