// Coursework One - Puzzle Collection Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include "Puzzle.h"
#include <vector>

using namespace std;

class PuzzleCollection {
public:
	PuzzleCollection();
	~PuzzleCollection();
	vector<Puzzle> getPuzzleSet() const { return puzzleSet; }
	void addPuzzle(Puzzle puzzle);
private:
	vector<Puzzle> puzzleSet;
};