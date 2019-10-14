#pragma once
#include "Puzzle.h"
#include "FileHandler.h";
#include <string>
#include <vector>

using namespace std;

class FilePuzzle : public Puzzle {
public:
	FilePuzzle();
	~FilePuzzle();
	void populatePuzzle(vector<int> fileInput);
};
