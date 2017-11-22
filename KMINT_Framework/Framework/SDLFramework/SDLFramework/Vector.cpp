#include "Vector.h"

Vector::Vector(const float x, const float y)
{
	vector_[0] = x;
	vector_[1] = y;
}

Vector::~Vector()
{
}

Vector Vector::scale(const float scalair)
{
	Vector vector(vector_[0] * scalair, vector_[1] * scalair);
	return vector;
}

Vector Vector::operator+(Vector vector)
{
	float* addVector = vector.getVector();
	Vector newVector(vector_[0] + addVector[0], vector_[1] + addVector[1]);
	return newVector;
}

Vector Vector::operator-(Vector vector)
{
	float* subtractVector = vector.getVector();
	Vector newVector(vector_[0] - subtractVector[0], vector_[1] - subtractVector[1]);
	return newVector;
}

void Vector::show(FWApplication* application)
{
	application->DrawLine(0, 0, vector_[0], vector_[1]);
}

void Vector::showPoint(FWApplication* application)
{
	application->DrawRect(vector_[0] - 2, vector_[1] - 2, 4, 4, true);
}

void Vector::showLine(Vector vector, FWApplication* application)
{
	float* toVector = vector.getVector();
	application->DrawLine(vector_[0], vector_[1], toVector[0], toVector[1]);
}

float* Vector::getVector()
{
	return vector_;
}
