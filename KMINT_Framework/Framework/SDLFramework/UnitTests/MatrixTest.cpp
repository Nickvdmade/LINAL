#include "stdafx.h"
#include "MatrixTest.h"


MatrixTest::MatrixTest()
{
}

MatrixTest::MatrixTest(const int rowSize, const int colSize)
	: rowSize_(rowSize)
	, colSize_(colSize)
{
	matrix_ = new float*[rowSize_];
	for (int i = 0; i < rowSize_; i++)
	{
		matrix_[i] = new float[colSize_];
		for (int j = 0; j < colSize_; j++)
			matrix_[i][j] = 0;
	}
}


MatrixTest::~MatrixTest()
{
}

void MatrixTest::setItem(const int rowIndex, const int colIndex, const float item)
{
	matrix_[rowIndex][colIndex] = item;
}

void MatrixTest::setItem(const int colIndex, const VectorTest vector)
{
	std::vector<float> itemVector = vector.getVector();
	int vectorLength = itemVector.size();
	if (vectorLength == rowSize_)
		for (int i = 0; i < rowSize_; i++)
			matrix_[i][colIndex] = itemVector[i];
}

MatrixTest MatrixTest::operator*(MatrixTest matrix)
{
	int matrixrowSize = matrix.getRowSize();
	int matrixcolSize = matrix.getColSize();
	int rowSize = rowSize_;
	float** tempMatrix = matrix_;
	if (rowSize_ != matrixcolSize)
	{
		tempMatrix = addExtra().getMatrix();
		rowSize++;
	}
	MatrixTest newMatrix(rowSize, colSize_);
	float** multiplyMatrix = matrix.getMatrix();

	for (int row = 0; row < matrixrowSize; row++)
	{
		for (int col = 0; col < colSize_; col++)
		{
			float newItem = 0;
			for (int index = 0; index < rowSize; index++)
				newItem += tempMatrix[index][col] * multiplyMatrix[row][index];
			newMatrix.setItem(row, col, newItem);
		}
	}
	return newMatrix;
}

int MatrixTest::getRowSize() const
{
	return rowSize_;
}

int MatrixTest::getColSize() const
{
	return colSize_;
}

float** MatrixTest::getMatrix() const
{
	return matrix_;
}

MatrixTest MatrixTest::addExtra()
{
	MatrixTest matrix(rowSize_ + 1, colSize_);
	for (int i = 0; i < rowSize_; i++)
	{
		for (int j = 0; j < colSize_; j++)
			matrix.setItem(i, j, matrix_[i][j]);
	}
	for (int i = 0; i < colSize_; i++)
	{
		matrix.setItem(rowSize_, i, 1);
	}
	return matrix;
}
