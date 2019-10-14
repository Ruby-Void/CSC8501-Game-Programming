#include "Puzzle.h"
#include <iostream>

Puzzle::Puzzle() {
	puzzle = new Matrix<int>(matrixSize, matrixSize);
}

Puzzle::~Puzzle() {
	delete puzzle;
}

void Puzzle::printPuzzle() {
	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			if (puzzle->getElement(row, column) == NULL) {
				cout << "NULL" << endl;
			}
			else {
				cout << puzzle->getElement(row, column) << endl;
			}
		}
	}
}
