// Coursework One - Puzzle Factory Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "PuzzleFactory.h"
#include "UserInputHandler.h"
#include <algorithm>
#include <numeric>

PuzzleFactory::PuzzleFactory() :
	generation(randomDevice()) {
}

PuzzleFactory::~PuzzleFactory() {

}

Puzzle PuzzleFactory::createPuzzle(vector<unsigned int> pattern) {
	Puzzle tempPuzzle = Puzzle();
	unsigned int counter = 0;
	for (int row = 0; row < tempPuzzle.getMatrixSize(); row++) {
		for (int column = 0; column < tempPuzzle.getMatrixSize(); column++) {
			tempPuzzle.getPuzzle().setElement(row, column, (row == 3 && column == 3) ? 0 : pattern.at(counter));
			counter++;
		}
	}
	tempPuzzle.setPattern(pattern);
	return tempPuzzle;
}

Puzzle PuzzleFactory::createGeneratedPattern(unsigned int start, unsigned int end) {
	unsigned int startPoint = (start > 0) ? start : defaultStart, endpoint = (end > 14) ? end : defaultEnd;
	vector<unsigned int> pattern(endpoint);
	iota(pattern.begin(), pattern.end(), startPoint);
	shuffle(pattern.begin(), pattern.end(), generation);
	pattern.erase(pattern.begin() + puzzleSize, pattern.end());
	return createPuzzle(pattern);
}

Puzzle PuzzleFactory::createUserPattern() {
	UserInputHandler userInput;
	vector<unsigned int> pattern;
	unsigned int input;
	for (int i = 0; i < puzzleSize; i++) {
		do {
			input = userInput.getUnsignedIntInput(("Input (" + to_string(i + 1) + "): "));
		} while (find(pattern.begin(), pattern.end(), input) != pattern.end() || input > 20);
		pattern.push_back(input);
	}
	return createPuzzle(pattern);
}

Puzzle PuzzleFactory::createFilePattern(vector<unsigned int> fileInput) {
	return createPuzzle(fileInput);
}