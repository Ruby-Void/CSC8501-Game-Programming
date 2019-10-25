// Coursework One - Puzzle Collection Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Last Edited: 17-10-2019
#pragma once
#include "Puzzle.h"
#include <vector>
#include <string>

using namespace std;

class PuzzleCollection {
public:
	PuzzleCollection();
	~PuzzleCollection();
	vector<Puzzle> getPuzzleSet() const { return puzzleSet; }
	void addPuzzle(Puzzle puzzle);
	void clearCollection();
	void generateSolutions(unsigned int partial);
	string printCollectionUnsolved();
	string printCollectionSolved(vector<unsigned int> sequence);
private:
	vector<Puzzle> puzzleSet;
};