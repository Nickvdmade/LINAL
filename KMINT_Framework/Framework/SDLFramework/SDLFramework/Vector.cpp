#include "Vector.h"

Vector::Vector(const float xDirection, const float yDirection)
{
	xDirection_ = xDirection;
	yDirection_ = yDirection;
}

Vector::~Vector()
{
}

Vector Vector::scale(const float scalair) const
{
	Vector vector(xDirection_ * scalair, yDirection_ * scalair);
	return vector;
}

Vector Vector::addVector(const Vector vector) const
{
	Vector newVector(xDirection_ + vector.getX(), yDirection_ + vector.getY());
	return newVector;
}

Vector Vector::subtractVector(const Vector vector) const
{
	Vector newVector(xDirection_ - vector.getX(), yDirection_ - vector.getY());
	return newVector;
}

void Vector::show(FWApplication* application)
{
	application->DrawLine(0, 0, xDirection_, yDirection_);
	application->DrawRect(xDirection_, yDirection_, 5, 5, true);
}

void Vector::showPoint(FWApplication * application)
{
	application->DrawRect(xDirection_, yDirection_, 5, 5, true);
}

void Vector::showLine(Vector vector, FWApplication * application)
{
	application->DrawLine(xDirection_, yDirection_, vector.getX(), vector.getY());
}

float Vector::getX() const
{
	return xDirection_;
}

float Vector::getY() const
{
	return yDirection_;
}
