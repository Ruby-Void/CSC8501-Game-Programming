// Coursework One - Main
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "FileHandler.h"
#include "Puzzle.h"
#include "PuzzleCollection.h"
#include "PuzzleFactory.h"
#include <iostream>

using namespace std;

int main() {
	FileHandler handler;
	PuzzleCollection collection;
	PuzzleFactory factory;

	collection.addPuzzle(factory.createUserPattern());
	collection.generateSolutions();
	cout << collection.printCollectionSolved();

	handler.writeFile("output.txt", collection.printCollectionSolved());
}