#include "MF.h"
#include <complex>

Matrix MF::scale2d(int x, int y)
{
	Matrix matrix(3, 3);
	matrix.setItem(0, 0, x);
	matrix.setItem(1, 1, y);
	matrix.setItem(2, 2, 1);
	return matrix;
}

Matrix MF::translate2d(int x, int y)
{
	Matrix matrix(3, 3);
	matrix.setItem(0, 0, 1);
	matrix.setItem(1, 1, 1);
	matrix.setItem(2, 2, 1);
	matrix.setItem(0, 2, x);
	matrix.setItem(1, 2, y);
	return matrix;
}

Matrix MF::rotate2d(int degree)
{
	float radian = degree * M_PI / 180;
	Matrix matrix(3, 3);
	matrix.setItem(0, 0, std::cos(radian));
	matrix.setItem(0, 1, -std::sin(radian));
	matrix.setItem(1, 0, std::sin(radian));
	matrix.setItem(1, 1, std::cos(radian));
	matrix.setItem(2, 2, 1);
	return matrix;
}

Matrix MF::scale3d(int x, int y, int z)
{
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, x);
	matrix.setItem(1, 1, y);
	matrix.setItem(2, 2, z);
	matrix.setItem(3, 3, 1);
	return matrix;
}

Matrix MF::translate3d(int x, int y, int z)
{
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

Matrix MF::rotate3d(int degree, Vector point, Vector axis)
{
	std::vector<float> pointVector = point.getVector();
	std::vector<float> axisVector = axis.getVector();
	Matrix toOrigin = translate3d(-pointVector[0], -pointVector[1], -pointVector[2]);
	Matrix toXy = rotateY(atan2(axisVector[2], axisVector[0]));
	Matrix toX = rotateZ(atan2(axisVector[1], sqrt(pow(axisVector[0], 2) + pow(axisVector[2], 2))));
	Matrix rotate = rotateX(degree);
	Matrix backXy = rotateZ(-atan2(axisVector[1], sqrt(pow(axisVector[0], 2) + pow(axisVector[2], 2))));
	Matrix backXyz = rotateY(-atan2(axisVector[2], axisVector[0]));
	Matrix toPoint = translate3d(pointVector[0], pointVector[1], pointVector[2]);
	Matrix matrix = toOrigin * toXy * toX * rotate * backXy * backXyz * toPoint;
	return matrix;
}

Matrix MF::rotateX(float degree)
{
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

Matrix MF::rotateY(float degree)
{
	float radian = degree * M_PI / 180;
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, std::cos(radian));
	matrix.setItem(0, 2, -std::sin(radian));
	matrix.setItem(1, 1, 1);
	matrix.setItem(2, 0, std::sin(radian));
	matrix.setItem(2, 2, std::cos(radian));
	matrix.setItem(3, 3, 1);
	return matrix;
}

Matrix MF::rotateZ(float degree)
{
	float radian = degree * M_PI / 180;
	Matrix matrix(4, 4);
	matrix.setItem(0, 0, std::cos(radian));
	matrix.setItem(0, 1, -std::sin(radian));
	matrix.setItem(1, 0, std::sin(radian));
	matrix.setItem(1, 1, std::cos(radian));
	matrix.setItem(2, 2, 1);
	matrix.setItem(3, 3, 1);
	return matrix;
}
