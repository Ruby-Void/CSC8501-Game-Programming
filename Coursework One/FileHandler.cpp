/*
#include "FileHandler.h"
#include "Puzzle.h"
#include <iostream>

FileHandler::FileHandler(string name) :
	filename(name) {

}

FileHandler::~FileHandler() {

}

void FileHandler::openFile() throw (invalid_argument) {
	try {
		dataFile.open(filename.c_str);
		if (dataFile.fail()) {
			throw invalid_argument("no file exists " + filename);
		}
	}
	catch (const invalid_argument & iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}
	
}

void FileHandler::readFile() {

}

void FileHandler::closeFile() {
	dataFile.close();
}
*/