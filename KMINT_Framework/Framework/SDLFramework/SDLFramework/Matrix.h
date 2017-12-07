#pragma once

#include <vector>
#include "Vector.h"

class Matrix
{
public:
	Matrix(const int colSize, const int rowSize);
	~Matrix();
	void setItem(const int colIndex, const int rowIndex, const float item);
	void setItem(const int colIndex, const Vector vector);
	Matrix scale(Matrix scale);
	Matrix translate(Vector translate);
	Matrix operator * (Matrix matrix);
	void show(FWApplication* application);
	int getColSize() const;
	int getRowSize() const;
	float** getMatrix() const;

private:
	int colSize_;
	int rowSize_;
	float** matrix_;
};

