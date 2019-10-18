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