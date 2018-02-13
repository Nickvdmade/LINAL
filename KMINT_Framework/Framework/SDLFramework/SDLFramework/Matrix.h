#pragma once

#include "Vector.h"

class Matrix
{
public:
	Matrix();
	Matrix(const int rowSize, const int colSize);
	~Matrix();
	void setItem(const int rowIndex, const int colIndex, const float item);
	void setItem(const int colIndex, const Vector vector);
	Matrix operator * (Matrix matrix);
	void show2d(FWApplication* application);
	void show3d(FWApplication* application, Vector eye, Vector lookAt);
	int getRowSize() const;
	int getColSize() const;
	float** getMatrix() const;

	void print();

private:
	int rowSize_;
	int colSize_;
	float** matrix_;

	Matrix addExtra();
	Matrix removeExtra();
	Matrix createCameraMatrix(Vector x, Vector y, Vector z, Vector eye);
	Matrix createProjectionMatrix(float near, float far, float fieldOfView);
	Vector afterCalculation(Vector vector);
};
