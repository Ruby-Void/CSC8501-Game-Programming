#include "FilePuzzle.h"

FilePuzzle::FilePuzzle() {

}

FilePuzzle::~FilePuzzle() {

}

void FilePuzzle::populatePuzzle(vector<int> fileInput) {
	unsigned int counter = 0;
	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			puzzle->setElement(row, column, (row == 3 && column == 3) ? NULL : fileInput.at(counter));
			counter++;
		}
	}
}