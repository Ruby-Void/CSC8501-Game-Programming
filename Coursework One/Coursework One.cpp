// Coursework One - Main
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "MatrixTemplate.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

}

/*
#include "FileHandler.h"
#include "Puzzle.h"
#include "PuzzleCollection.h"
#include "PuzzleFactory.h"
#include "UserInputHandler.h"

FileHandler handler;
PuzzleCollection collection;
PuzzleFactory factory;
UserInputHandler userInput;
bool running = true;

while (running) {
	collection.addPuzzle(factory.createGeneratedPattern());
	collection.generateSolutions();

	handler.writeFile(userInput.getStringInput("File Name: "), collection.printCollectionSolved());

	cout << collection.printCollectionSolved();

	if (userInput.getCharInput("Continue (y/n): ") == 'n') {
		running = false;
	}
}
*/

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