#include "Matrix.h"

Matrix::Matrix(const int colSize, const int rowSize)
	: colSize_(colSize)
	, rowSize_(rowSize)
{
	matrix_ = new float*[colSize_];
	for (int i = 0; i < colSize_; i++)
		matrix_[i] = new float[rowSize_];
}

Matrix::~Matrix()
{
	/*for (int i = 0; i < colSize_; i++)
		delete matrix_[i];
	delete matrix_;*/
}

void Matrix::setItem(const int colIndex, const int rowIndex, const float item)
{
	matrix_[colIndex][rowIndex] = item;
}

void Matrix::setItem(const int colIndex, const Vector vector)
{
	std::vector<float> itemVector = vector.getVector();
	int vectorLength = itemVector.size();
	if (vectorLength == colSize_)
		for (int i = 0; i < colSize_; i++)
			matrix_[i][colIndex] = itemVector[i];
}

Matrix Matrix::scale(Matrix scale)
{
	if (colSize_ == scale.getRowSize())
	{
		int scaleColSize = scale.getColSize();
		int scaleRowSize = scale.getRowSize();
		Matrix newMatrix(scaleColSize, rowSize_);
		float** scaleMatrix = scale.getMatrix();
		for (int col = 0; col < scaleColSize; col++)
			for (int row = 0; row < rowSize_; row++)
			{
				float newItem = 0;
				for (int index = 0; index < colSize_; index++)
					newItem += matrix_[index][row] * scaleMatrix[col][index];
				newMatrix.setItem(col, row, newItem);
			}
		return newMatrix;
	}
	return *this;
}

void Matrix::show(FWApplication * application)
{
	for (int i = 0; i < rowSize_; i++)
		application->DrawLine(matrix_[0][i], matrix_[1][i], matrix_[0][((i + 1)) % rowSize_], matrix_[1][((i + 1)) % rowSize_ ]);
}

int Matrix::getColSize() const
{
	return colSize_;
}

int Matrix::getRowSize() const
{
	return rowSize_;
}

float** Matrix::getMatrix() const
{
	return matrix_;
}
