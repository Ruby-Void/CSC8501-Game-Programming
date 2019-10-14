#include "UserPuzzle.h"
#include <sstream>

UserPuzzle::UserPuzzle() {
	puzzle = new Matrix<int>(matrixSize, matrixSize);
}

UserPuzzle::~UserPuzzle() {
	delete puzzle;
}

void UserPuzzle::populatePuzzle() {
	vector<int> previousInputs;
	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			if (row == (matrixSize - 1) && column == (matrixSize - 1)) {
				puzzle->setElement(row, column, NULL);
			}
			else {
				unsigned int input;
				do {
					input = getIntegerInput("Row: " + to_string(row + 1) + " Column: " + to_string(column + 1) + " Input: ");
				} while (find(previousInputs.begin(), previousInputs.end(), input) != previousInputs.end());
				previousInputs.push_back(input);
				puzzle->setElement(row, column, input);
			} 
		}
	}
}

unsigned int UserPuzzle::getIntegerInput(string message) {
	string input;
	int numerical;
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
	return (unsigned int)numerical;
}