#include <iostream>

using namespace std;

template <typename T>
class Matrix {
public:
	Matrix(unsigned int x = defaultX, unsigned int y = defaultY);
	Matrix(const Matrix<T>& sourceMatrix);
	~Matrix();
	Matrix<T>& operator=(const Matrix<T>& sourceMatrix);
	int getSizeX() const { return sizeX; }
	int getSizeY() const { return sizeY; }
	T getElement(unsigned int x, unsigned int y) const;
	void setElement(unsigned int x, unsigned int y, T elem);
	static const int defaultX = 3;
	static const int defaultY = 3;
protected:
	T** cells;
	int sizeX;
	int sizeY;
};

template <typename T>
Matrix<T>::Matrix(unsigned int x, unsigned int y) :
	sizeX(x), sizeY(y) {
	cells = new T * [sizeX];
	for (int i = 0; i < sizeX; ++i) {
		cells[i] = new T[sizeY];
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& sourceMatrix) {
	*this = sourceMatrix;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& sourceMatrix) {
	sizeX = sourceMatrix.sizeX;
	sizeY = sourceMatrix.sizeY;
	cells = new T * [sizeX];
	for (int i = 0; i < sizeX; ++i) {
		cells[i] = new T[sizeY];
		for (int j = 0; j < sizeY; j++) {
			cells[i][j] = sourceMatrix.cells[i][j];
		}
	}
	return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < sizeX; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

template <typename T>
T Matrix<T>::getElement(unsigned int x, unsigned int y) const {
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::setElement(unsigned int x, unsigned int y, T elem) {
	cells[x][y] = elem;
}