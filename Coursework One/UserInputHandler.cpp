// Coursework One - User Input Handler Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "UserInputHandler.h"
#include <iostream>
#include <sstream>

UserInputHandler::UserInputHandler() {

}

UserInputHandler::~UserInputHandler() {

}

unsigned int UserInputHandler::getUnsignedIntInput(string message) {
	string input;
	unsigned int numerical;
	bool breaker = true;
	while (breaker) {
		cout << message;
		getline(cin, input);
		breaker = (stringstream(input) >> numerical) ? ((numerical > 0) ? false : true) : true;
	}
	return numerical;
}

unsigned long long UserInputHandler::getUnsignedLongLongInput(string message) {
	string input;
	unsigned long long numerical;
	bool breaker = true;
	while (breaker) {
		cout << message;
		getline(cin, input);
		breaker = (stringstream(input) >> numerical) ? ((numerical > 0) ? false : true) : true;
	}
	return numerical;
}

char UserInputHandler::getCharInput(string message) {
	string input;
	char character;
	bool breaker = true;
	while (breaker) {
		cout << message;
		getline(cin, input);
		breaker = (stringstream(input) >> character) ? false : true;
	}
	return character;
}

string UserInputHandler::getFilenameInput(string message) {
	string input;
	const int invalidCharSize = 9;
	string invalidChars[9] = { "<", ">", ":", "\"", "/", "\\", "|", "?", "*" };
	bool found = false;
	int counter = 0;
	do  {
		input = getStringInput(message);	
		while (counter < invalidCharSize && !found) {
			if (input.find(invalidChars[counter]) != string::npos) {
				found = true;
			}
			counter++;
		}
	} while (counter < invalidCharSize);
	return input;
}


vector<unsigned int> UserInputHandler::getSequenceInput(string message) {
	vector<unsigned int> returnVector;
	char spaceDelimiter = ' ';
	string field;
	unsigned int value;
	stringstream sequence = stringstream(getStringInput(message));
	while (getline(sequence, field, spaceDelimiter)) {
		if (stringstream(field) >> value) {
			if (value > 1 && value < 5) {
				if (find(returnVector.begin(), returnVector.end(), value) == returnVector.end()) {
					returnVector.push_back(value);
				}
			}			
		}
	}
	return returnVector;
}

string UserInputHandler::getStringInput(string message) {
	string input;
	cout << message;
	getline(cin, input);
	return input;
}