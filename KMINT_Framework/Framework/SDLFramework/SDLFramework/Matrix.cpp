#include "Matrix.h"

Matrix::Matrix(const int size)
	: size_(size)
{
	matrix_[0] = new float[size];
	matrix_[1] = new float[size];
}

Matrix::~Matrix()
{
	delete matrix_[0];
	delete matrix_[1];
}

void Matrix::setPoint(const int index, const float x, const float y) const
{
	matrix_[0][index] = x;
	matrix_[1][index] = y;
}

void Matrix::show(FWApplication* application) const
{
	for (int i = 0; i < size_; i++)
		application->DrawLine(matrix_[0][i], matrix_[1][i], matrix_[0][(i + 1) % size_], matrix_[1][(i + 1) % size_]);
}

int Matrix::getsize() const
{
	return size_;
}

float** Matrix::getMatrix()
{
	return matrix_;
}
