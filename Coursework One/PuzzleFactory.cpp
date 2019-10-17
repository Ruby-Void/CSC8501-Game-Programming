// Coursework One - Puzzle Factory Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "PuzzleFactory.h"
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>

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
			tempPuzzle.getPuzzle().setElement(row, column, (row == 3 && column == 3) ? NULL : pattern.at(counter));
			counter++;
		}
	}
	return tempPuzzle;
}

Puzzle PuzzleFactory::createGeneratedPattern(unsigned int start, unsigned int end) {
	vector<unsigned int> pattern(end);
	iota(pattern.begin(), pattern.end(), start);
	shuffle(pattern.begin(), pattern.end(), generation);
	pattern.erase(pattern.begin() + puzzleSize, pattern.end());
	return createPuzzle(pattern);
}

Puzzle PuzzleFactory::createUserPattern() {
	vector<unsigned int> pattern;
	unsigned int input;
	for (int i = 0; i < puzzleSize; i++) {
		do {
			input = getIntegerInput(("Input (" + to_string(i + 1) + "): "));
		} while (find(pattern.begin(), pattern.end(), input) != pattern.end());
		pattern.push_back(input);
	}
	return createPuzzle(pattern);
}

Puzzle PuzzleFactory::createFilePattern(vector<unsigned int> fileInput) {
	return createPuzzle(fileInput);
}

unsigned int PuzzleFactory::getIntegerInput(string message) {
	string input;
	unsigned int numerical;
	bool breaker = true;
	while (breaker) {
		cout << message;
		getline(cin, input);
		if (stringstream(input) >> numerical) {
			if (numerical > 0) {
				breaker = false;
			}
		}
	}
	return numerical;
}