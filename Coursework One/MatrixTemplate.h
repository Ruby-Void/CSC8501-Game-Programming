#include <iostream>

using namespace std;

template <typename T>
class Matrix {
public:
	Matrix(int x = defaultX, int y = defaultY);
	~Matrix();
	int getSizeX() const { return sizeX; }
	int getSizeY() const { return sizeY; }
	T getElement(int x, int y) const;
	void setElement(int x, int y, T elem);
	static const int defaultX = 3;
	static const int defaultY = 3;
protected:
	T** cells;
	int sizeX;
	int sizeY;
};

template <typename T>
Matrix<T>::Matrix(int x, int y) :
	sizeX(x), sizeY(y) {
	cells = new T * [sizeX];
	for (int i = 0; i < sizeX; ++i) {
		cells[i] = new T[sizeY];
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < sizeX; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}

template <typename T>
T Matrix<T>::getElement(int x, int y) const {
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::setElement(int x, int y, T elem) {
	cells[x][y] = elem;
}