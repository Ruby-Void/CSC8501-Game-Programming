#include "FileHandler.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

FileHandler::FileHandler() :
	configurations(0) {
}

FileHandler::~FileHandler() {

}

void FileHandler::readFile(string name) throw (invalid_argument) {
	string line;
	char nDelimiter = '\n';
	char spaceDelimiter = ' ';
	openFile(name);
	try {
		if (!dataFile.is_open()) {
			throw invalid_argument("file not open");
		}
		else {
			getline(dataFile, line, nDelimiter);
			if (stringstream(line) >> configurations) {
				if (configurations > 0) {
					for (int i = 0; i < configurations; i++) {
						int counter = 0;
						unsigned int tempInt;
						vector<unsigned int> tempVector;
						while (counter < puzzleSize) {
							getline(dataFile, line, spaceDelimiter);
							if (stringstream(line) >> tempInt) {
								tempVector.push_back(tempInt);
								counter++;
							}	
							else {
								throw invalid_argument("file format not recognised");
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
}

void FileHandler::openFile(string name) throw (invalid_argument) {
	try {
		filename = name;
		dataFile.open(filename);
		if (dataFile.fail()) {
			throw invalid_argument("no file exists " + filename);
		}
	}
	catch (const invalid_argument & iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}	
}

void FileHandler::closeFile() {
	dataFile.close();
}