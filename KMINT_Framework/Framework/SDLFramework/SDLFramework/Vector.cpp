#include "Vector.h"

Vector::Vector()
{
	size_ = 2;
	vector_ = std::vector<float>(size_);
}

Vector::Vector(const int size)
	: size_(size)
{
	vector_ = std::vector<float>(size_);
}

Vector::~Vector()
{
}

void Vector::setItem(const int index, const float item)
{
	vector_[index] = item;
}

Vector Vector::scale(const float scalair)
{
	Vector vector(size_);
	for (int i = 0; i < size_; i++)
		vector.setItem(i, vector_[i] * scalair);
	return vector;
}

Vector Vector::operator+(Vector vector)
{
	std::vector<float> addVector = vector.getVector();
	if (size_ == addVector.size())
	{
		Vector newVector(size_);
		for (int i = 0; i < size_; i++)
			newVector.setItem(i, vector_[i] + addVector[i]);
		return newVector;
	}
	return *this;
}

Vector Vector::operator-(Vector vector)
{
	std::vector<float> subtractVector = vector.getVector();
	if (size_ == subtractVector.size())
	{
		Vector newVector(size_);
		for (int i = 0; i < size_; i++)
			newVector.setItem(i, vector_[i] - subtractVector[i]);
		return newVector;
	}
	return *this;
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
	std::vector<float> toVector = vector.getVector();
	application->DrawLine(vector_[0], vector_[1], toVector[0], toVector[1]);
}

std::vector<float> Vector::getVector() const
{
	return vector_;
}
