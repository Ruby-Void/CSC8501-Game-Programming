#include <iostream>
#include "GeneratePuzzle.h"

using namespace std;

int main() {
	const int MATRIXSIZE = 4;	
	GeneratePuzzle* puzzle = new GeneratePuzzle(MATRIXSIZE);
	puzzle->populatePuzzle(1, 10000);

	for (int row = 0; row < MATRIXSIZE; row++) {
		for (int column = 0; column < MATRIXSIZE; column++) {
			if (puzzle->getPuzzle()->getElement(row, column) == NULL) {
				cout << "NULL" << endl;
			}
			else {
				cout << puzzle->getPuzzle()->getElement(row, column) << endl;
			}
		}
	}

	cout << endl;

	GeneratePuzzle* puzzle2 = new GeneratePuzzle(MATRIXSIZE);
	puzzle2->populatePuzzle(1, 10000);

	for (int row = 0; row < MATRIXSIZE; row++) {
		for (int column = 0; column < MATRIXSIZE; column++) {
			if (puzzle2->getPuzzle()->getElement(row, column) == NULL) {
				cout << "NULL" << endl;
			}
			else {
				cout << puzzle2->getPuzzle()->getElement(row, column) << endl;
			}
		}
	}
}



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

const int SIZE = 4;
int gridTest[SIZE][SIZE];

char* inputType = new char(' ');

bool playing = true;
while (playing) {
	while (*inputType != 'M' && *inputType != 'A') {
		string message = "Manual (M) or Automatic (A) input: ";
		*inputType = getCharInput(message);
	}

	if (*inputType == 'M') {
		cout << "Manual" << endl;
		for (int row = 0; row < SIZE; row++) {
			for (int column = 0; column < SIZE; column++) {
				if (row == 3 && column == 3) {
					gridTest[row][column] = NULL;
				}
				else {
					string message = "Value at (" + to_string(row) + ", " + to_string(column) + "): ";
					gridTest[row][column] = getIntegerInput(message);
				}
			}
		}
	}
	else if (*inputType == 'A') {
		cout << "Automatic" << endl;
	}

	cout << "Grid: 4 X 4" << endl;
	for (int row = 0; row < SIZE; row++) {
		string output = " ------------------------------\n";
		for (int column = 0; column < SIZE; column++) {
			(gridTest[row][column] < 10) ? output.append(" |  ") : output.append(" | ");
			output.append(to_string(gridTest[row][column]));
			output.append(" | ");
		}
		cout << output << endl;
	}

	playing = false;
}
*/