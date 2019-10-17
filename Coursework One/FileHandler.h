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
	vector<vector<unsigned int>> readFile(string name);
	void writeFile(string name, string outputs);
private:
	string filename;
	ifstream inputFile;
	ofstream outputFile;
	void openInputFile(string name);
	void openOutputFile(string name);
	void closeFile();
};