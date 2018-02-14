#pragma once
#include "VectorTest.h"

class MatrixTest
{
public:
	MatrixTest();
	MatrixTest(const int rowSize, const int colSize);
	~MatrixTest();
	void setItem(const int rowIndex, const int colIndex, const float item);
	void setItem(const int colIndex, const VectorTest vector);
	MatrixTest operator * (MatrixTest matrix);
	int getRowSize() const;
	int getColSize() const;
	float** getMatrix() const;

private:
	int rowSize_;
	int colSize_;
	float** matrix_;

	MatrixTest addExtra();
};

