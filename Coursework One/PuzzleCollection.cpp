// Coursework One - Puzzle Collection Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Last Edited: 17-10-2019
#include "PuzzleCollection.h"

PuzzleCollection::PuzzleCollection() {
}

PuzzleCollection::~PuzzleCollection() {
	
}

void PuzzleCollection::addPuzzle(Puzzle puzzle) {
	puzzleSet.push_back(puzzle);
}

void PuzzleCollection::clearCollection() {
	puzzleSet.clear();
}

void PuzzleCollection::generateSolutions(unsigned int partial) {
	for (Puzzle& puzzle : puzzleSet) {
		if (partial <= puzzle.getMatrixSize()) {
			puzzle.setStateSolutions(partial, puzzle.createStateSolution(partial));
			puzzle.setSolutions(partial, puzzle.createSolution(partial));
		}		
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

string PuzzleCollection::printCollectionSolved(vector<unsigned int> sequence) {
	string puzzleCollectionFormat;
	for (auto puzzle : puzzleSet) {
		puzzleCollectionFormat.append(puzzle.printPuzzleSolution(sequence) + "\n");
	}
	return puzzleCollectionFormat;
}