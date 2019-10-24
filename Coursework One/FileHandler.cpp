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
	vector<vector<unsigned int>> returnVector;
	const char nDelimiter = '\n';
	const char spaceDelimiter = ' ';

	try {
		openInputFile(name);
		if (!inputFile.is_open()) {
			throw invalid_argument("file not open");
		}

		string config;
		int configurations;
		getline(inputFile, config, nDelimiter);
		if (stringstream(config) >> configurations) {
			if (configurations > 0) {
				int counter = 0;
				vector<unsigned int> tempVector;
				string row = "";
				while (counter < configurations) {					
					getline(inputFile, row);
					if (row != "") {
						string field;
						unsigned int value;
						stringstream rowContainer = stringstream(row);
						while (getline(rowContainer, field, spaceDelimiter)) {
							if (stringstream(field) >> value) {
								tempVector.push_back(value);
							}								
						}
						row = "";
					}
					else {
						returnVector.push_back(tempVector);
						tempVector.clear();
						counter++;
					}
				}					
			}
		}
	}
	catch (const invalid_argument & iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		returnVector.clear();
		return returnVector;
	}
	closeFile();
	return returnVector;
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
		cout << "Unable to open file: " << iae.what() << "\n";
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
		cout << "Unable to open file: " << iae.what() << "\n";
	}
}

void FileHandler::closeFile() {
	inputFile.close();
	outputFile.close();
}