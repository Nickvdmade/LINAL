#include "stdafx.h"
#include "VectorTest.h"


VectorTest::VectorTest()
{
	size_ = 2;
	vector_ = std::vector<float>(size_);
	for (int i = 0; i < size_; i++)
		vector_[i] = 0;
}

VectorTest::VectorTest(const int size)
	: size_(size)
{
	vector_ = std::vector<float>(size_);
	for (int i = 0; i < size_; i++)
		vector_[i] = 0;
}

VectorTest::~VectorTest()
{
}

void VectorTest::setItem(const int index, const float item)
{
	vector_[index] = item;
}

VectorTest VectorTest::scale(const float scalair)
{
	VectorTest vector(size_);
	for (int i = 0; i < size_; i++)
		vector.setItem(i, vector_[i] * scalair);
	return vector;
}

VectorTest VectorTest::operator+(VectorTest vector)
{
	std::vector<float> addVector = vector.getVector();
	if (vector_.size() != addVector.size())
		throw "VECTOR ADDITION: Vector sizes are not equal";
	if (size_ == addVector.size())
	{
		VectorTest newVector(size_);
		for (int i = 0; i < size_; i++)
			newVector.setItem(i, vector_[i] + addVector[i]);
		return newVector;
	}
	return *this;
}

VectorTest VectorTest::operator-(VectorTest vector)
{
	std::vector<float> subtractVector = vector.getVector();
	if (vector_.size() != subtractVector.size())
		throw "VECTOR SUBTRACTION: Vector sizes are not equal";
	if (size_ == subtractVector.size())
	{
		VectorTest newVector(size_);
		for (int i = 0; i < size_; i++)
			newVector.setItem(i, vector_[i] - subtractVector[i]);
		return newVector;
	}
	return *this;
}

float VectorTest::dotProduct(VectorTest vector)
{
	std::vector<float> productVector = vector.getVector();
	if (vector_.size() != productVector.size())
		throw "DOT PRODUCT: Vector sizes are not equal";
	float result = 0;
	for (int i = 0; i < vector_.size(); i++)
		result += vector_[i] * productVector[i];
	return result;
}

VectorTest VectorTest::crossProduct(VectorTest vector)
{
	std::vector<float> productVector = vector.getVector();
	int size = vector_.size();
	if (size != productVector.size())
		throw "CROSS PRODUCT: Vector sizes are not equal";
	VectorTest result(size);
	size = 3;
	for (int i = 0; i < size; i++)
	{
		result.setItem(i, vector_[(i + 1) % size] * productVector[(i + 2) % size] - vector_[(i + 2) % size] * productVector[(i + 1) % size]);
	}
	return result;
}

std::vector<float> VectorTest::getVector() const
{
	return vector_;
}
