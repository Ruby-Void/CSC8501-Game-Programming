#include "GeneratedPuzzle.h"
#include <algorithm>
#include <numeric>

GeneratedPuzzle::GeneratedPuzzle() :
	generation(randomDevice()) {
}

GeneratedPuzzle::~GeneratedPuzzle() {

}

void GeneratedPuzzle::populatePuzzle(unsigned int start, unsigned int end) {
	vector<unsigned int> numberSet = generateSetOfNumbers(start, end);
	unsigned int counter = 0;
	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			puzzle->setElement(row, column, (row == 3 && column == 3) ? NULL : numberSet.at(counter));
			counter++;
		}
	}
}

vector<unsigned int> GeneratedPuzzle::generateSetOfNumbers(unsigned int start, unsigned int end) {
	const unsigned int puzzleSize = 15;
	vector<unsigned int> randomVector(end);
	iota(randomVector.begin(), randomVector.end(), start);
	shuffle(randomVector.begin(), randomVector.end(), generation);
	randomVector.erase(randomVector.begin() + puzzleSize, randomVector.end());
	return randomVector;
}