// Coursework One - File Handler Header
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#pragma once
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileHandler {
public:
	FileHandler();
	~FileHandler();	
	unsigned int getConfigurations() const { return configurations; }
	vector<vector<unsigned int>> getInputPatterns() const { return inputPatterns; }
	void readFile(string name);	
private:
	int configurations;
	const static unsigned int puzzleSize = 15;
	vector<vector<unsigned int>> inputPatterns;
	string filename;
	ifstream dataFile;
	void openFile(string name);
	void closeFile();
};