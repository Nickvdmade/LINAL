#include "MF.h"
#include <complex>
#include <iostream>

Matrix MF::scale2d(float x, float y)
{
	// create scaling matrix
	Matrix matrix(3, 3);
	matrix.setItem(0, 0, x);
	matrix.setItem(1, 1, y);
	matrix.setItem(2, 2, 1);
	return matrix;
}

Matrix MF::translate2d(float x, float y)
{
	// create translation matrix
	Matrix matrix(3, 3);
	matrix.setItem(0, 0, 1);
	matrix.setItem(1, 1, 1);
	matrix.setItem(2, 2, 1);
	matrix.setItem(0, 2, x);
	matrix.setItem(1, 2, y);
	return matrix;
}

Matrix MF::rotate2d(float degree)
{
	// craete rotation matrix
	float radian = degree * M_PI / 180;
	Matrix matrix(3, 3);
	matrix.setItem(0, 0, std::cos(radian));
	matrix.setItem(0, 1, -std::sin(radian));
	matrix.setItem(1, 0, std::sin(radian));
	matrix.setItem(1, 1, std::cos(radian));
	matrix.setItem(2, 2, 1);
	return matrix;
}

Matrix MF::scale3d(float x, float y, float z)
{
	// create scaling matrix
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, x);
	matrix.setItem(1, 1, y);
	matrix.setItem(2, 2, z);
	matrix.setItem(3, 3, 1);
	return matrix;
}

Matrix MF::translate3d(float x, float y, float z)
{
	// create translation matrix
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, 1);
	matrix.setItem(1, 1, 1);
	matrix.setItem(2, 2, 1);
	matrix.setItem(3, 3, 1);
	matrix.setItem(0, 3, x);
	matrix.setItem(1, 3, y);
	matrix.setItem(2, 3, z);
	return matrix;
}

Matrix MF::rotate3d(float degree, Vector point, Vector axis)
{
	// craete rotation matrix
	std::vector<float> pointVector = point.getVector();
	std::vector<float> axisVector = axis.getVector();
	Matrix toOrigin = translate3d(-pointVector[0], -pointVector[1], -pointVector[2]); // translation matrix to origin
	Matrix toXy = rotateY(atan2(axisVector[2], axisVector[0])); // rotation matrix to xy plane
	Matrix toX = rotateZ(atan2(axisVector[1], sqrt(pow(axisVector[0], 2) + pow(axisVector[2], 2)))); // rotation matrix to x axis
	Matrix rotate = rotateX(degree); // rotation matrix around x axis
	Matrix backXy = rotateZ(-atan2(axisVector[1], sqrt(pow(axisVector[0], 2) + pow(axisVector[2], 2)))); // rotation matrix back to xy plane
	Matrix backXyz = rotateY(-atan2(axisVector[2], axisVector[0])); // rotation matrix back to xyz space
	Matrix toPoint = translate3d(pointVector[0], pointVector[1], pointVector[2]); // translation matrix back to original point
	Matrix matrix = toOrigin * toXy * toX * rotate * backXy * backXyz * toPoint; // complete rotation matrix
	return matrix;
}

Matrix MF::rotateX(float degree)
{
	// rotate around x axis
	float radian = degree * M_PI / 180;
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, 1);
	matrix.setItem(1, 1, std::cos(radian));
	matrix.setItem(1, 2, -std::sin(radian));
	matrix.setItem(2, 1, std::sin(radian));
	matrix.setItem(2, 2, std::cos(radian));
	matrix.setItem(3, 3, 1);
	return matrix;
}

Matrix MF::rotateY(float radian)
{
	// rotate around y axis
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, std::cos(radian));
	matrix.setItem(0, 2, std::sin(radian));
	matrix.setItem(1, 1, 1);
	matrix.setItem(2, 0, -std::sin(radian));
	matrix.setItem(2, 2, std::cos(radian));
	matrix.setItem(3, 3, 1);
	return matrix;
}

Matrix MF::rotateZ(float radian)
{
	// rotate around z axis
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, std::cos(radian));
	matrix.setItem(0, 1, std::sin(radian));
	matrix.setItem(1, 0, -std::sin(radian));
	matrix.setItem(1, 1, std::cos(radian));
	matrix.setItem(2, 2, 1);
	matrix.setItem(3, 3, 1);
	return matrix;
}
