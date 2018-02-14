#include "Matrix.h"
#include <ostream>
#include <iostream>
#include <SDL_stdinc.h>

Matrix::Matrix()
{
}

Matrix::Matrix(const int rowSize, const int colSize)
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

Matrix::~Matrix()
{
}

void Matrix::setItem(const int rowIndex, const int colIndex, const float item)
{
	matrix_[rowIndex][colIndex] = item;
}

void Matrix::setItem(const int colIndex, const Vector vector)
{
	std::vector<float> itemVector = vector.getVector();
	int vectorLength = itemVector.size();
	if (vectorLength == rowSize_)
		for (int i = 0; i < rowSize_; i++)
			matrix_[i][colIndex] = itemVector[i];
}

Matrix Matrix::operator*(Matrix matrix)
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
	Matrix newMatrix(rowSize, colSize_);
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

void Matrix::show2d(FWApplication * application)
{
	for (int i = 0; i < colSize_; i++)
		application->DrawLine(matrix_[0][i], matrix_[1][i], matrix_[0][((i + 1)) % colSize_], matrix_[1][((i + 1)) % colSize_ ]);
}

void Matrix::show3d(FWApplication* application, Vector eye, Vector lookAt)
{
	Vector up(4);
	up.setItem(1, 1);
	up.setItem(3, 1);
	Vector z = eye - lookAt;
	z.normalize();
	Vector y = up;
	y.normalize();
	Vector x = y.crossProduct(z);
	x.normalize();
	y = z.crossProduct(x);
	y.normalize();
	Matrix cameraMatrix = createCameraMatrix(x, y, z, eye);
	Matrix projectionMatrix = createProjectionMatrix(100, 1000, 90);
	Matrix showVectors = *this * cameraMatrix * projectionMatrix;
	float** matrix = showVectors.getMatrix();
	int rowSize = showVectors.getRowSize();
	int colSize = showVectors.getColSize();
	for (int i = 0; i < colSize; i++)
	{
		Vector vector(rowSize);
		for (int j = 0; j < rowSize; j++)
			vector.setItem(j, matrix[j][i]);
		showVectors.setItem(i, afterCalculation(vector));
	}

	matrix = showVectors.getMatrix();
	for (int i = 0; i < colSize; i++)
	{
		if (matrix[3][i] > 0 && matrix[3][(i + 1) % colSize] > 0)
			application->DrawLine(matrix[0][i], matrix[1][i], matrix[0][(i + 1) % colSize], matrix[1][(i + 1) % colSize]);
	}
}

int Matrix::getRowSize() const
{
	return rowSize_;
}

int Matrix::getColSize() const
{
	return colSize_;
}

float** Matrix::getMatrix() const
{
	return matrix_;
}

void Matrix::print()
{
	for (int i = 0; i < rowSize_; i++)
	{
		for (int j = 0; j < colSize_; j++)
			std::cout << matrix_[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix Matrix::addExtra()
{
	Matrix matrix(rowSize_ + 1, colSize_);
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

Matrix Matrix::createCameraMatrix(Vector x, Vector y, Vector z, Vector eye)
{
	Matrix matrix(4, 4);
	std::vector<float> xVector = x.getVector();
	std::vector<float> yVector = y.getVector();
	std::vector<float> zVector = z.getVector();
	matrix.setItem(0, 0, xVector[0]);
	matrix.setItem(0, 1, xVector[1]);
	matrix.setItem(0, 2, xVector[2]);
	matrix.setItem(0, 3, -x.dotProduct(eye));
	matrix.setItem(1, 0, yVector[0]);
	matrix.setItem(1, 1, yVector[1]);
	matrix.setItem(1, 2, yVector[2]);
	matrix.setItem(1, 3, -y.dotProduct(eye));
	matrix.setItem(2, 0, zVector[0]);
	matrix.setItem(2, 1, zVector[1]);
	matrix.setItem(2, 2, zVector[2]);
	matrix.setItem(2, 3, -z.dotProduct(eye));
	matrix.setItem(3, 3, 1);
	return matrix;
}

Matrix Matrix::createProjectionMatrix(float near, float far, float fieldOfView)
{
	if (far == near)
		throw "PROJECTIONMATRIX: divide by 0";
	float radian = fieldOfView * M_PI / 180;
	float scale = near * tan(radian * 0.5);
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, scale);
	matrix.setItem(1, 1, scale);
	matrix.setItem(2, 2, -far / (far - near));
	matrix.setItem(2, 3, -1);
	matrix.setItem(3, 2, -far*near / (far - near));
	return matrix;
}

Vector Matrix::afterCalculation(Vector vector)
{
	int screenSize = 1200;
	std::vector<float> calculationVector = vector.getVector();
	Vector afterCalculationVector(calculationVector.size());
	float x = calculationVector[0];
	float y = calculationVector[1];
	float w = calculationVector[3];
	if (w == 0)
		return vector;// throw "AFTERCALCULATION: divide by 0";
	afterCalculationVector.setItem(0, screenSize / 2 + (x + 1) / w*screenSize*0.5);
	afterCalculationVector.setItem(1, screenSize / 2 + (y + 1) / w*screenSize*0.5);
	afterCalculationVector.setItem(2, -calculationVector[2]);
	afterCalculationVector.setItem(3, w);
	return afterCalculationVector;
}
