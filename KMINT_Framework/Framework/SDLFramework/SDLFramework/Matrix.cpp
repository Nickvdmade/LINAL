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
		return *this * scale;
	}
	return *this;
}

Matrix Matrix::translate(Vector translate)
{
	std::vector<float> translateVector = translate.getVector();
	if (translateVector.size() == colSize_)
	{
		Matrix translateMatrix(colSize_ + 1, colSize_ + 1);
		for (int col = 0; col < colSize_ + 1; col++)
			for (int row = 0; row < colSize_ + 1; row++)
			{
				if (col == row)
					translateMatrix.setItem(col, row, 1);
				else if (row == colSize_)
					translateMatrix.setItem(col, row, translateVector[col]);
				else
					translateMatrix.setItem(col, row, 0);
			}

		Matrix thisMatrix(colSize_ + 1, rowSize_);
		for (int col = 0; col < colSize_ + 1; col++)
			for (int row = 0; row < rowSize_; row++)
			{
				if (col == colSize_)
					thisMatrix.setItem(col, row, 1);
				else
					thisMatrix.setItem(col, row, matrix_[col][row]);
			}

		Matrix tempMatrix = thisMatrix*translateMatrix;
		Matrix newMatrix(colSize_, rowSize_);
		for (int col = 0; col < colSize_; col++)
			for (int row = 0; row < rowSize_; row++)
				newMatrix.setItem(col, row, tempMatrix.getMatrix()[col][row]);
		return newMatrix;
	}
	return *this;
}

Matrix Matrix::operator*(Matrix matrix)
{
	int matrixColSize = matrix.getColSize();
	int matrixRowSize = matrix.getRowSize();
	Matrix newMatrix(matrixColSize, rowSize_);
	float** multiplyMatrix = matrix.getMatrix();
	for (int col = 0; col < matrixColSize; col++)
		for (int row = 0; row < rowSize_; row++)
		{
			float newItem = 0;
			for (int index = 0; index < colSize_; index++)
				newItem += matrix_[index][row] * multiplyMatrix[col][index];
			newMatrix.setItem(col, row, newItem);
		}
	return newMatrix;
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
