#include "Matrix.h"

Matrix::Matrix(const int size)
	: size_(size)
{
	matrix_ = std::vector<Vector>(size_);
}

Matrix::~Matrix()
{
}

void Matrix::setItem(const int index, const Vector item)
{
	matrix_[index] = item;
}

void Matrix::show(FWApplication* application)
{
	for (int i = 0; i < size_; i++)
		matrix_[i].showLine(matrix_[(i + 1) % size_], application);
}

int Matrix::getSize() const
{
	return size_;
}

std::vector<Vector> Matrix::getMatrix() const
{
	return matrix_;
}
