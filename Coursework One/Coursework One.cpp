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
	
	char running = 'y';
	while (running == 'y' || running == 'Y') {
		collection.clearCollection();
		char generationPuzzleSet = 'y';
		while (generationPuzzleSet == 'y' || generationPuzzleSet == 'Y') {
			char puzzleType = ' ';
			while (puzzleType != 'G' && puzzleType != 'I' && puzzleType != 'F' &&
				puzzleType != 'g' && puzzleType != 'i' && puzzleType != 'f') {
				puzzleType = userInput.getCharInput("Select which mode to create puzzle patterns with.\nGenereated Puzzles = g/G\nUser Input Puzzle = i/I\nFile Input Puzzles = f/F\nCreation Type : ");
			}
			if (puzzleType == 'G' || puzzleType == 'g') {
				unsigned int itterations = userInput.getUnsignedIntInput("Please specify how many generations: ");
				unsigned int grid = userInput.getUnsignedIntInput("Please specify size of gird: ");
				for (int i = 0; i < itterations; i++) {
					collection.addPuzzle(factory.createGeneratedPattern(grid));
				}
			}
			else if (puzzleType == 'I' || puzzleType == 'i') {
				collection.addPuzzle(factory.createUserPattern(userInput.getUnsignedIntInput("Please specify puzzle size (e.g. 4x4 = 4): ")));
			}
			else {
				for (auto puzzle : handler.readFile(userInput.getFilenameInput("Please specify file name: "))) {
					collection.addPuzzle(factory.createFilePattern(puzzle));
				}
			}
			do {
				generationPuzzleSet = userInput.getCharInput("Create new puzzle pattern? (y/Y/n/N): ");
			} while (generationPuzzleSet != 'y' && generationPuzzleSet != 'Y' && generationPuzzleSet != 'n' && generationPuzzleSet != 'N');
		}		

		char outputType = ' ';
		do {
			outputType = userInput.getCharInput("Select which output type.\nNo Solutions = n/N\nSolutions = s/S\nOutput Type: ");
		} while (outputType != 's' && outputType != 'S' && outputType != 'n' && outputType != 'N');

		if (outputType == 'n' || outputType == 'N') {
			char printToConsole = ' ';
			do {
				printToConsole = userInput.getCharInput("Print to console? (y/Y/n/N): ");
			} while (printToConsole != 'y' && printToConsole != 'Y' && printToConsole != 'n' && printToConsole != 'N');

			if (printToConsole == 'y' || printToConsole == 'Y') {
				cout << "\nOutput:\n\n" << collection.printCollectionUnsolved();
			}
			handler.writeFile(userInput.getFilenameInput("Please specify output file name: "), collection.printCollectionUnsolved());
		}
		else {
			vector<unsigned int> sequence = userInput.getSequenceInput("Please input partial pattern(s) (2, 3, 4) you wish to solve (use spaces to define different numbers) : ");
			for (auto value : sequence) {
				collection.generateSolutions(value);
			}

			char printToConsole = ' ';
			do {
				printToConsole = userInput.getCharInput("Print to console? (y/Y/n/N): ");
			} while (printToConsole != 'y' && printToConsole != 'Y' && printToConsole != 'n' && printToConsole != 'N');

			if (printToConsole == 'y' || printToConsole == 'Y') {
				cout << "\nOutput:\n\n" << collection.printCollectionSolved(sequence);
			}

			handler.writeFile(userInput.getFilenameInput("Please specify output file name: "), collection.printCollectionSolved(sequence));						
		}

		do {
			running = userInput.getCharInput("Continue? (y/Y/n/N): ");
		} while (running != 'y' && running != 'Y' && running != 'n' && running != 'N');
	}	
}