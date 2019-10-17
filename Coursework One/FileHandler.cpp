// Coursework One - File Handler Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "FileHandler.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

FileHandler::FileHandler() {
}

FileHandler::~FileHandler() {

}

vector<vector<unsigned int>> FileHandler::readFile(string name) throw (invalid_argument) {
	const unsigned int puzzleSize = 15;
	unsigned int configurations;
	vector<vector<unsigned int>> inputPatterns;
	string line;
	char nDelimiter = '\n';
	char spaceDelimiter = ' ';
	try {
		openInputFile(name);
		if (!inputFile.is_open()) {
			throw invalid_argument("file not open");
		}
		else {
			getline(inputFile, line, nDelimiter);
			if (stringstream(line) >> configurations) {
				if (configurations > 0) {
					for (int i = 0; i < configurations; i++) {
						int counter = 0;
						unsigned int tempInt;
						vector<unsigned int> tempVector;
						while (counter < puzzleSize) {
							getline(inputFile, line, spaceDelimiter);
							if (stringstream(line) >> tempInt) {
								tempVector.push_back(tempInt);
								counter++;
							}	
							else {
								throw invalid_argument("file format incorrect");
							}
						}
						inputPatterns.push_back(tempVector);
					}
				}
			}					
		}
	}
	catch (const invalid_argument & iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}
	closeFile();
	return inputPatterns;
}

void FileHandler::writeFile(string name, string outputs) throw (invalid_argument) {
	openOutputFile(name);

	if (outputFile.is_open()) {
		outputFile << outputs << endl;
	}
	
	closeFile();
}

void FileHandler::openInputFile(string name) throw (invalid_argument) {
	try {
		filename = name;
		inputFile.open(filename);
		if (inputFile.fail()) {
			throw invalid_argument("no file exists " + filename);
		}
	}
	catch (const invalid_argument & iae) {
		cout << "unable to open file: " << iae.what() << "\n";
		exit(1);
	}
}

void FileHandler::openOutputFile(string name) throw (invalid_argument) {
	try {
		filename = name;
		outputFile.open(filename);
		if (outputFile.fail()) {
			throw invalid_argument("no file exists " + filename);
		}
	}
	catch (const invalid_argument & iae) {
		cout << "unable to open file: " << iae.what() << "\n";
		exit(1);
	}
}

void FileHandler::closeFile() {
	inputFile.close();
	outputFile.close();
}