#include "PuzzleCollection.h"

PuzzleCollection::PuzzleCollection() {
}

PuzzleCollection::~PuzzleCollection() {
	
}

void PuzzleCollection::addPuzzle(Puzzle puzzle) {
	puzzleSet.push_back(puzzle);
}
