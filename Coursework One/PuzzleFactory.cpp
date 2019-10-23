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

Puzzle PuzzleFactory::createGeneratedPattern(unsigned int start, unsigned int end, unsigned int size) {
	unsigned int endpoint = (end >= (size * size - 1)) ? end : (size * size - 1);
	unsigned int startPoint = (start > 0 && endpoint - start < (size * size - 1)) ? start : 1;
	vector<unsigned int> pattern(endpoint);
	iota(pattern.begin(), pattern.end(), startPoint);
	shuffle(pattern.begin(), pattern.end(), generation);
	pattern.erase(pattern.begin() + size * size - 1, pattern.end());
	return Puzzle(pattern);
}

Puzzle PuzzleFactory::createUserPattern(unsigned int size) {
	UserInputHandler userInput;
	vector<unsigned int> pattern;
	unsigned int input;
	for (int i = 0; i < (size * size - 1); i++) {
		do {
			input = userInput.getUnsignedIntInput(("Input (" + to_string(i + 1) + "): "));
		} while (find(pattern.begin(), pattern.end(), input) != pattern.end() || input > 20);
		pattern.push_back(input);
	}
	return Puzzle(pattern);
}

Puzzle PuzzleFactory::createFilePattern(vector<unsigned int> fileInput) {
	return Puzzle(fileInput);
}