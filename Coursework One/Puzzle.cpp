// Coursework One - Puzzle Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "Puzzle.h"
#include <algorithm>

Puzzle::Puzzle(vector<unsigned int> newPattern) :
	matrixSize(unsigned int(sqrt(newPattern.size() + 1))), 
	puzzleSize(newPattern.size()), pattern(newPattern), orderedPattern(newPattern) {
	sort(orderedPattern.begin(), orderedPattern.end());
}

Puzzle::~Puzzle() {
	
}

void Puzzle::createStateSolution() {
	// Partial 2 Row
	for (int i = 0; i < (matrixSize - 1); i++) {
		if (pattern.at(i) + 1 == pattern.at(i + 1)) {
			twoStateSolutions++;
		}
		if (pattern.at(i + matrixSize) + 1 == pattern.at(i + matrixSize + 1)) {
			twoStateSolutions++;
		}
		if (pattern.at(i + matrixSize * 2) + 1 == pattern.at(i + matrixSize * 2 + 1)) {
			twoStateSolutions++;
		}	
	}

	// Partial 3 Row
	for (int i = 0; i < (matrixSize - 2); i++) {
		if (pattern.at(i) + 1 == pattern.at(i + 1) && pattern.at(i + 1) + 1 == pattern.at(i + 2)) {
			threeStateSolutions++;
		}
		if (pattern.at(i + matrixSize) + 1 == pattern.at(i + matrixSize + 1) && pattern.at(i + matrixSize + 1) + 1 == pattern.at(i + matrixSize + 2)) {
			threeStateSolutions++;
		}
		if (pattern.at(i + matrixSize * 2) + 1 == pattern.at(i + matrixSize * 2 + 1) && pattern.at(i + matrixSize * 2 + 1) + 1 == pattern.at(i + matrixSize * 2 + 2)) {
			threeStateSolutions++;
		}
	}

	// Partial 4 Row
	for (int i = 0; i < matrixSize - 1; i++) {
		if (pattern.at(i * matrixSize) + 1 == pattern.at(i * matrixSize + 1) && pattern.at(i * matrixSize + 1) + 1 == pattern.at(i * matrixSize + 2) && pattern.at(i * matrixSize + 2) + 1 == pattern.at(i * matrixSize + 3)) {
			fourStateSolutions++;
		}
	}
}

/*
for (unsigned int location = 0; location < matrixSize; location++) {
	if (matrix.getElement(location, 0) + 1 == matrix.getElement(location, 1) &&
		matrix.getElement(location, 1) + 1 == matrix.getElement(location, 2) &&
		matrix.getElement(location, 2) + 1 == matrix.getElement(location, 3)) {
		rowSolutions++;
	}
	if (matrix.getElement(location, 3) - 1 == matrix.getElement(location, 2) &&
		matrix.getElement(location, 2) - 1 == matrix.getElement(location, 1) &&
		matrix.getElement(location, 1) - 1 == matrix.getElement(location, 0)) {
		reverseRowSolutions++;
	}
	if (matrix.getElement(0, location) + 1 == matrix.getElement(1, location) &&
		matrix.getElement(1, location) + 1 == matrix.getElement(2, location) &&
		matrix.getElement(2, location) + 1 == matrix.getElement(3, location)) {
		columnSolutions++;
	}
	if (matrix.getElement(3, location) - 1 == matrix.getElement(2, location) &&
		matrix.getElement(2, location) - 1 == matrix.getElement(1, location) &&
		matrix.getElement(1, location) - 1 == matrix.getElement(0, location)) {
		reverseColumnSolutions++;
	}
}
*/

unsigned long long Puzzle::createSolution(unsigned int partials) {
	unsigned long long solution = 0;
	for (unsigned int i = 0; i < puzzleSize - (partials - 1); i++) {
		if (orderedPattern.at(i) + (partials - 1) == orderedPattern.at(i + partials - 1)) {
			solution += (((matrixSize - partials + 1) * (matrixSize - 1)) + (matrixSize - partials)) * (factorial(puzzleSize - partials) / 2);
		}
	}
	return solution;
}

string Puzzle::printPuzzle() {
	string puzzleFormat = "";
	unsigned int counter = 0;
	for (unsigned int row = 0; row < matrixSize; row++) {
		for (unsigned int column = 0; column < matrixSize; column++) {
			if (counter < puzzleSize) {
				puzzleFormat.append(((pattern.at(counter) != 0) ? to_string(pattern.at(counter)) : " ") + ((pattern.at(counter) < 10) ? "  " : " "));
			}
			counter++;
		}
		puzzleFormat.append("\n");
	}
	return puzzleFormat;
}

string Puzzle::printPuzzleSolution() {
	return printPuzzle() + "Row = " + to_string(fourSolutions) +
		"\nColumn = " + to_string(fourSolutions) + 
		"\nReverse Row = " + to_string(fourSolutions) + 
		"\nReverse Column = " + to_string(fourSolutions) + 
		"\n(total for row & column, including reverse, in this configuration)" +
		"\n2 = " + to_string(twoStateSolutions) +
		"\n3 = " + to_string(threeStateSolutions) +
		"\n4 = " + to_string(fourStateSolutions) +
		"\n(total for row and column, including reverse, for all valid turns)" +
		"\n2 = " + to_string(twoSolutions) + 
		"\n3 = " + to_string(threeSolutions) + 
		"\n4 = " + to_string(fourSolutions) + 
		"\n";
}

void Puzzle::setGivenSolutions(unsigned int partial, unsigned long long value) {
	if (partial == 2) {
		twoSolutions = value;
	}
	else if (partial == 3) {
		threeSolutions = value;
	}
	else if (partial == 4) {
		fourSolutions = value;
	}
}

unsigned int Puzzle::factorial(unsigned int value) {
	unsigned int returnValue = 1;
	for (int i = 1; i <= value; i++) {
		returnValue *= i;
	}
	return returnValue;
}