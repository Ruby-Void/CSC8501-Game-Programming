#include "GeneratePuzzle.h"
#include <algorithm>
#include <numeric>


#define ARR_LEN(X) (sizeof(X) / sizeof(X[0]))

GeneratePuzzle::GeneratePuzzle(unsigned int size) :
	matrixSize(size), generation(randDev()) {
	puzzle = new Matrix<int>(matrixSize, matrixSize);
}

GeneratePuzzle::~GeneratePuzzle() {
	delete puzzle;
}

vector<int> GeneratePuzzle::generateSetOfNumbers(unsigned int start, unsigned int end) {
	const int puzzleSize = 15;
	vector<int> randomVector(end);
	iota(randomVector.begin(), randomVector.end(), start);
	shuffle(randomVector.begin(), randomVector.end(), generation);
	randomVector.erase(randomVector.begin() + puzzleSize, randomVector.end());
	return randomVector;
}

void GeneratePuzzle::populatePuzzle(unsigned int start, unsigned int end) {
	vector<int> numberSet = generateSetOfNumbers(start, end);

	int counter = -1;
	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			if (row == 0 && column == 0) {
				puzzle->setElement(row, column, NULL);
			}
			else {
				puzzle->setElement(row, column, numberSet.at(counter));
			}
			counter++;
		}
	}
}