// Coursework One - Puzzle Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "Puzzle.h"
#include <algorithm>
#include <sstream>
#include <iostream>

Puzzle::Puzzle(vector<unsigned int> newPattern) :
	matrixSize(unsigned int(sqrt(newPattern.size() + 1))), 
	puzzleSize(newPattern.size()), pattern(newPattern), orderedPattern(newPattern) {
	sort(orderedPattern.begin(), orderedPattern.end());
}

Puzzle::~Puzzle() {
	
}

unsigned int Puzzle::createStateSolution(int partials) {
	int solution = 0;
	for (int column = 0; column < matrixSize; column++) { //looping coloumns
		for (int row = 0; row <= matrixSize - partials; row++) { //looping Rows
			int itterator = row * matrixSize + column;
			bool forward = true, reverse = true;
			for (int i = 1; i < partials; i++) {
				if (itterator + matrixSize * i < puzzleSize) {
					forward = (pattern.at(itterator) + i != pattern.at(itterator + matrixSize * i)) ? false : true;
					reverse = (pattern.at(itterator) != pattern.at(itterator + matrixSize * i) + i) ? false : true;
				}
				else {
					forward = reverse = false;
				}
			}
			if (forward) {
				solution++;
			}
			if (reverse) {
				solution++;
			}
		}
	}

	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column <= matrixSize - partials; column++) {
			int itterator = row * matrixSize + column;
			bool forward = true, reverse = true;
			for (int i = 1; i < partials; i++) {
				if (itterator + i < puzzleSize) {
					forward = (pattern.at(itterator) + i != pattern.at(itterator + i)) ? false : true;
					reverse = (pattern.at(itterator) != pattern.at(itterator + i) + i) ? false : true;
				}
				else {
					forward = reverse = false;
				}
			}
			if (forward) {
				solution++;
			}
			if (reverse) {
				solution++;
			}
		}
	}

	return solution;
}

bigint Puzzle::createSolution(unsigned int partials) {
	bigint solution;
	#pragma loop(hint_parallel(6))
	for (unsigned int i = 0; i < puzzleSize - (partials - 1); i++) {
		if (orderedPattern.at(i) + (partials - 1) == orderedPattern.at(i + partials - 1)) {
			solution += (factorial(puzzleSize - partials) * (((matrixSize - partials + 1) * (matrixSize - 1)) + (matrixSize - partials)) / 2);
		}
	}
	cout << solution << endl;
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
	stringstream number;
	number << fourSolutions;
	string solutionFormat = printPuzzle() + "\nRow = " + number.str() +
		"\nColumn = " + number.str() +
		"\nReverse Row = " + number.str() +
		"\nReverse Column = " + number.str() +
		"\n(total for row & column, including reverse, in this configuration)" +
		"\n2 = " + to_string(twoStateSolutions) +
		"\n3 = " + to_string(threeStateSolutions) +
		"\n4 = " + to_string(fourStateSolutions) +
		"\n(total for row and column, including reverse, for all valid turns)";
	number.str(string());
	number << twoSolutions;
	solutionFormat.append("\n2 = " + number.str());
	number.str(string());
	number << threeSolutions;
	solutionFormat.append("\n3 = " + number.str());
	number.str(string());
	number << fourSolutions;
	solutionFormat.append("\n4 = " + number.str() + "\n");
	return solutionFormat;
}

void Puzzle::setStateSolutions(unsigned int partial, unsigned int value){
	if (partial == 2) {
		twoStateSolutions = value;
	}
	else if (partial == 3) {
		threeStateSolutions = value;
	}
	else if (partial == 4) {
		fourStateSolutions = value;
	}
}

void Puzzle::setSolutions(unsigned int partial, bigint value) {
	if (partial == 2) {
		twoSolutions = bigint(value);
	}

	if (partial == 3) {
		threeSolutions = bigint(value);
	}

	if (partial == 4) {
		fourSolutions = bigint(value);
	}
}

bigint Puzzle::factorial(unsigned int value) {
	bigint returnValue = 1;
	for (int i = 1; i <= value; i++) {
		returnValue *= i;
	}
	return returnValue;
}