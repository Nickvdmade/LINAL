#include "stdafx.h"
#include "MFTest.h"

MatrixTest MFTest::scale3d(float x, float y, float z)
{
	MatrixTest matrix(4, 4);
	matrix.setItem(0, 0, x);
	matrix.setItem(1, 1, y);
	matrix.setItem(2, 2, z);
	matrix.setItem(3, 3, 1);
	return matrix;
}

MatrixTest MFTest::translate3d(float x, float y, float z)
{
	MatrixTest matrix(4, 4);
	matrix.setItem(0, 0, 1);
	matrix.setItem(1, 1, 1);
	matrix.setItem(2, 2, 1);
	matrix.setItem(3, 3, 1);
	matrix.setItem(0, 3, x);
	matrix.setItem(1, 3, y);
	matrix.setItem(2, 3, z);
	return matrix;
}