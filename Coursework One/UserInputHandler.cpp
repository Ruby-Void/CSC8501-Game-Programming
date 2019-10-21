// Coursework One - User Input Handler Class
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "UserInputHandler.h"
#include <sstream>
#include <iostream>

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

string UserInputHandler::getStringInput(string message) {
	string input;
	cout << message;
	getline(cin, input);
	return input;
}