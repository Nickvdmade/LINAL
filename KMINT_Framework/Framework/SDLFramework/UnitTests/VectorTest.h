#pragma once
#include <vector>

class VectorTest
{
public:
	VectorTest();
	VectorTest(const int size);
	~VectorTest();
	void setItem(const int index, const float item);
	VectorTest scale(const float scalair);
	VectorTest operator+(VectorTest vector);
	VectorTest operator-(VectorTest vector);
	float dotProduct(VectorTest vector);
	VectorTest crossProduct(VectorTest vector);
	std::vector<float> getVector() const;

private:
	int size_;
	std::vector<float> vector_;
};

