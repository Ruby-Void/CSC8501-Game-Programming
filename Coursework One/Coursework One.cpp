#include "Puzzle.h"
#include "GeneratedPuzzle.h"
#include "UserPuzzle.h"
#include "FilePuzzle.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	const unsigned int POLYTEST = 5;
	vector<int> pattern = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	vector<Puzzle*> testVector;

	for (int i = 0; i < POLYTEST; i++) {
		FilePuzzle* clone = new FilePuzzle();
		clone->populatePuzzle(pattern);
		testVector.push_back(clone);
	}	

	for (auto puzzle : testVector) {
		puzzle->printPuzzle();
		cout << endl;
	}
}

/*	
	// GENERATE PUZZLE
	
	#include "GeneratePuzzle.h"

	const int numOfConfig = 4;
	GeneratePuzzle* puzzleConfig = new GeneratePuzzle(numOfConfig);
	puzzleConfig->populatePuzzle();

	for (auto puzzle : puzzleConfig->getPuzzleConfigurations()) {
		for (int row = 0; row < puzzleConfig->getMatrixSize(); row++) {
			for (int column = 0; column < puzzleConfig->getMatrixSize(); column++) {
				if (puzzle->getElement(row, column) == NULL) {
					cout << "NULL" << endl;
				}
				else {
					cout << puzzle->getElement(row, column) << endl;
				}
			}
		}
		cout << endl;
	}

	delete puzzleConfig;	
*/

/*
	// USER INPUT PUZZLE

	#include "UserPuzzle.h"

	unsigned int getIntegerInput(string message) {
		
	}

	UserPuzzle* puzzle = new UserPuzzle();
	vector<int> inputs;

	for (int row = 0; row < puzzle->getMatrixSize(); row++) {
		for (int column = 0; column < puzzle->getMatrixSize(); column++) {
			if (row == 3 && column == 3) {
				puzzle->addElement(row, column, NULL);
			}
			else {
				unsigned int input;
				do {
					input = getIntegerInput("Row: " + to_string(row + 1) + " Column: " + to_string(column + 1) + " Input: ");
				} while (find(inputs.begin(), inputs.end(), input) != inputs.end());
				inputs.push_back(input);
				puzzle->addElement(row, column, input);				
			}
		}
	}
	
	for (int row = 0; row < puzzle->getMatrixSize(); row++) {
		for (int column = 0; column < puzzle->getMatrixSize(); column++) {
			if (puzzle->getPuzzle()->getElement(row, column) == NULL) {
				cout << "NULL" << endl;
			}
			else {
				cout << puzzle->getPuzzle()->getElement(row, column) << endl;
			}
		}
	}
*/

/*
char getCharInput(string message) {
	string input;
	bool unclean = true;
	while (unclean) {
		cout << message;
		getline(cin, input);
		if (input.length() == 1) {
			return input[0];
		}
	}
	return ' ';
}
*/

/*
int getIntegerInput(string message) {
	string input;
	int numericalInput;
	bool unclean = true;
	while (unclean) {
		cout << message;
		getline(cin, input);
		stringstream numberStream(input);
		if (numberStream >> numericalInput) {
			return numericalInput;
		}
	}
	return 0;
}
*/