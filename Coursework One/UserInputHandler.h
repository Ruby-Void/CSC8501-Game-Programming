// Coursework One - User Input Handler Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include <string>

using namespace std;

class UserInputHandler {
public:
	UserInputHandler();
	~UserInputHandler();
	unsigned int getUnsignedIntInput(string message);
	char getCharInput(string message);
	string getStringInput(string message);
};