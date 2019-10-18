// Coursework One - Main
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "FileHandler.h"
#include "Puzzle.h"
#include "PuzzleCollection.h"
#include "PuzzleFactory.h"
#include "UserInputHandler.h"
#include <iostream>

using namespace std;

int main() {
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

		char answer = userInput.getCharInput("Continue (y/n): ");
		if (answer == 'n') {
			running = false;
		}
	}
}




/*
	const unsigned int matrixSize = 3;
	Matrix<unsigned int> threeByThree = Matrix<unsigned int>(matrixSize, matrixSize);
	vector<unsigned int> pattern = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };

	unsigned int counter = 0;
	for (unsigned int row = 0; row < matrixSize; row++) {
		for (unsigned int column = 0; column < matrixSize; column++) {
			threeByThree.setElement(row, column, pattern.at(counter));
			counter++;
		}
	}

	for (unsigned int row = 0; row < matrixSize; row++) {
		if (threeByThree.getElement(row, 0)) {

		}		
	}

	for (unsigned int column = 0; column < matrixSize; column++) {
		for (unsigned int row = 0; row < matrixSize; row++) {
			
		}
	}
*/