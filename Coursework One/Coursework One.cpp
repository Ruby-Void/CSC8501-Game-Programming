#include "FileHandler.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "PuzzleCollection.h"
#include <iostream>


using namespace std;

int main() {
	PuzzleCollection collection;
	PuzzleFactory factory;
	FileHandler handler;	
	handler.readFile("data.txt");	

	if (handler.getConfigurations() > 0) {
		for (auto puzzlePattern : handler.getInputPatterns()) {
			collection.addPuzzle(factory.createFilePattern(puzzlePattern));
		}

		for (auto puzzle : collection.getPuzzleSet()) {
			cout << puzzle.printPuzzle() << endl;
		}
	}
	else {
		cout << "No configurations..." << endl;
	}
}

/*
char getCharInput(string message) {
	string input;
	bool unclean = true;
	while (unclean) {
		cout << message;
		getline(cin, input);
		if (input.length() == 1) {
			return input[0];
		}
	}
	return ' ';
}
*/

/*
int getIntegerInput(string message) {
	string input;
	int numericalInput;
	bool unclean = true;
	while (unclean) {
		cout << message;
		getline(cin, input);
		stringstream numberStream(input);
		if (numberStream >> numericalInput) {
			return numericalInput;
		}
	}
	return 0;
}
*/