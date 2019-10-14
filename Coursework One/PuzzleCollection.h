#pragma once
#include "Puzzle.h"
#include <vector>

using namespace std;

class PuzzleCollection {
public:
	PuzzleCollection();
	~PuzzleCollection();
	vector<Puzzle*> getPuzzleSet() const { return puzzle; }
	void addPuzzle(Puzzle* puzzle);
private:
	vector<Puzzle*> puzzleSet;
};