// Coursework One - User Input Handler Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include <string>
#include <vector>

using namespace std;

class UserInputHandler {
public:
	UserInputHandler();
	~UserInputHandler();
	unsigned int getUnsignedIntInput(string message);
	unsigned long long getUnsignedLongLongInput(string message);
	char getCharInput(string message);	
	string getFilenameInput(string message);
	vector<unsigned int> getSequenceInput(string message);
private:
	string getStringInput(string message);
};