#include "Vector.h"

Vector::Vector()
{
	size_ = 2;
	vector_ = std::vector<float>(size_);
	for (int i = 0; i < size_; i++)
		vector_[i] = 0;
}

Vector::Vector(const int size)
	: size_(size)
{
	vector_ = std::vector<float>(size_);
	for (int i = 0; i < size_; i++)
		vector_[i] = 0;
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
	if (vector_.size() != addVector.size())
		throw "VECTOR ADDITION: Vector sizes are not equal";
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
	if (vector_.size() != subtractVector.size())
		throw "VECTOR SUBTRACTION: Vector sizes are not equal";
	if (size_ == subtractVector.size())
	{
		Vector newVector(size_);
		for (int i = 0; i < size_; i++)
			newVector.setItem(i, vector_[i] - subtractVector[i]);
		return newVector;
	}
	return *this;
}

float Vector::dotProduct(Vector vector)
{
	std::vector<float> productVector = vector.getVector();
	if (vector_.size() != productVector.size())
		throw "DOT PRODUCT: Vector sizes are not equal";
	float result = 0;
	for (int i = 0; i < vector_.size(); i++)
		result += vector_[i] * productVector[i];
	return result;
}

Vector Vector::crossProduct(Vector vector)
{
	std::vector<float> productVector = vector.getVector();
	int size = vector_.size(); 
	if (size != productVector.size())
		throw "CROSS PRODUCT: Vector sizes are not equal";
	Vector result(size);
	for (int i = 0; i < size; i++)
	{
		result.setItem(i, vector_[(i + 1) % size] * productVector[(i + 2) % size] - vector_[(i + 2) % size] * productVector[(i + 1) % size]);
	}
	return result;
}

void Vector::normalize()
{
	float length = dotProduct(*this);
	for (int i = 0; i < size_; i++)
		vector_[i] = vector_[i] / length;

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
