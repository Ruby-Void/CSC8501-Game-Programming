// Coursework One - Main
// Author: Ciaran Halliburton
// Student ID: 190595298
// Date: 17-10-2019
#include "MatrixTemplate.h"
#include <iostream>

using namespace std;

int main() {
	const unsigned int matrixSize = 2;
	Matrix<unsigned int> testMatrix = Matrix<unsigned int>(matrixSize, matrixSize);
	testMatrix.setElement(0, 0, 1);
	testMatrix.setElement(0, 1, 2);
	testMatrix.setElement(1, 0, 3);
	testMatrix.setElement(1, 1, 4);

	if (testMatrix.getElement(0, 0) + 1 == testMatrix.getElement(0, 1)) {
		cout << "ROW" << endl;
	}
}