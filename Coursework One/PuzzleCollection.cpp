// Coursework One - Puzzle Collection Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "PuzzleCollection.h"

PuzzleCollection::PuzzleCollection() {
}

PuzzleCollection::~PuzzleCollection() {
	
}

void PuzzleCollection::addPuzzle(Puzzle puzzle) {
	puzzleSet.push_back(puzzle);
}

void PuzzleCollection::generateSolutions() {
	for (Puzzle& puzzle : puzzleSet) {
		puzzle.createSolutions();
	}
}

string PuzzleCollection::printCollectionUnsolved() {
	string puzzleCollectionFormat;
	puzzleCollectionFormat.append(to_string(puzzleSet.size()) + "\n");
	for (auto puzzle : puzzleSet) {
		puzzleCollectionFormat.append(puzzle.printPuzzle() + "\n");
	}
	return puzzleCollectionFormat;
}

string PuzzleCollection::printCollectionSolved() {
	string puzzleCollectionFormat;
	for (auto puzzle : puzzleSet) {
		puzzleCollectionFormat.append(puzzle.printPuzzleSolution() + "\n");
	}
	return puzzleCollectionFormat;
}