#include "Vector.h"

Vector::Vector(const float xDirection, const float yDirection)
{
	xDirection_ = xDirection;
	yDirection_ = yDirection;
}

Vector::~Vector()
{
}

Vector Vector::Scale(const float scalair) const
{
	Vector vector(xDirection_ * scalair, yDirection_ * scalair);
	return vector;
}

Vector Vector::AddVector(const Vector vector) const
{
	Vector newVector(xDirection_ + vector.GetX(), yDirection_ + vector.GetY());
	return newVector;
}

Vector Vector::SubtractVector(const Vector vector) const
{
	Vector newVector(xDirection_ - vector.GetX(), yDirection_ - vector.GetY());
	return newVector;
}

void Vector::Show()
{
	
}

float Vector::GetX() const
{
	return xDirection_;
}

float Vector::GetY() const
{
	return yDirection_;
}
