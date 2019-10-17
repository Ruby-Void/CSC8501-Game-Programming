// Coursework One - Puzzle Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "Puzzle.h"
#include <string>

Puzzle::Puzzle() {
	matrix = Matrix<int>(matrixSize, matrixSize);
}

Puzzle::~Puzzle() {
	
}

void Puzzle::createSolutions() {

}

string Puzzle::printPuzzle() {
	string puzzleFormat = "";
	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			if (!(row == 3 && column == 3)) {
				if (matrix.getElement(row, column) < 10) {
					puzzleFormat.append(to_string(matrix.getElement(row, column)));
					puzzleFormat.append("  ");
				}
				else {
					puzzleFormat.append(to_string(matrix.getElement(row, column)));
					puzzleFormat.append(" ");
				}				
			}						
		}
		puzzleFormat.append("\n");
	}
	return puzzleFormat;
}

string Puzzle::printPuzzleSolution() {
	string puzzleFormat = printPuzzle();
	puzzleFormat.append(("Row = " + to_string(0) + "\n"));
	puzzleFormat.append(("Column = " + to_string(0) + "\n"));
	puzzleFormat.append(("Reverse Row = " + to_string(0) + "\n"));
	puzzleFormat.append(("Reverse Column = " + to_string(0) + "\n"));
	return puzzleFormat;
}
