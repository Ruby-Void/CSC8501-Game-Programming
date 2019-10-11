#include <iostream>
#include <sstream>
#include <string>
#include "MatrixTemplate.h"
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int* generateSetOfNumbers(int n) {
	int p[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	for (int i = 19; i > 0; --i) {
		int j = rand() % i;
		int temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}

	//copy first n elements from p to arr
	static int returnArray[15];
	for (int i = 0; i < n; ++i) {
		returnArray[i] = p[i];
	}

	return returnArray;
}

int main() {
	srand(time(0));

	const int MATRIXSIZE = 4;
	const int MINRANGE = 1;
	const int MAXRANGE = 21;

	Matrix<int>* puzzle = new Matrix<int>(MATRIXSIZE, MATRIXSIZE);

	int* testArray = generateSetOfNumbers(15);

	for (int i = 0; i < 15; i++) {
		cout << *(testArray + i) << endl;
	}

	cout << endl;

	int counter = -1;
	for (int row = 0; row < MATRIXSIZE; row++) {
		for (int column = 0; column < MATRIXSIZE; column++) {
			if (row == 0 && column == 0) {
				puzzle->setElement(row, column, NULL);
			}
			else {
				puzzle->setElement(row, column, *(testArray + counter));
			}
			counter++;
		}
	}

	for (int row = 0; row < MATRIXSIZE; row++) {
		for (int column = 0; column < MATRIXSIZE; column++) {
			if (puzzle->getElement(row, column) == NULL) {
				cout << "NULL" << endl;
			}
			else {
				cout << puzzle->getElement(row, column) << endl;
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