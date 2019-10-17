// Coursework One - Puzzle Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "Puzzle.h"
#include <string>

Puzzle::Puzzle() {
	matrix = Matrix<unsigned int>(matrixSize, matrixSize);
}

Puzzle::~Puzzle() {
	
}

void Puzzle::createSolutions() {
	for (unsigned int row = 0; row < matrixSize; row++) {
		if ((matrix.getElement(row, 0) < matrix.getElement(row, 1))) {// && (matrix.getElement(row, 1) < matrix.getElement(row, 2)) && (matrix.getElement(row, 2) < matrix.getElement(row, 3))) {
			rowSolutions++;
		}
	}	
}

string Puzzle::printPuzzle() {
	string puzzleFormat = "";
	for (unsigned int row = 0; row < matrixSize; row++) {
		for (unsigned int column = 0; column < matrixSize; column++) {
			puzzleFormat.append(((matrix.getElement(row, column) != 0) ? to_string(matrix.getElement(row, column)) : " ") + ((matrix.getElement(row, column) < 10) ? "  " : " "));					
		}
		puzzleFormat.append("\n");
	}
	return puzzleFormat;
}

string Puzzle::printPuzzleSolution() {
	return printPuzzle() + "Row = " + to_string(rowSolutions) + "\nColumn = " + to_string(columnSolutions) + "\nReverse Row = " + to_string(reverseRowSolutions) + "\nReverse Column = " + to_string(reverseColumnSolutions) + "\n";
}