#pragma once

#include "FWApplication.h"

class Vector
{
public:
	Vector();
	Vector(const int size);
	~Vector();
	void setItem(const int index, const float item);
	Vector scale(const float scalair);
	Vector operator+(Vector vector);
	Vector operator-(Vector vector);
	float dotProduct(Vector vector);
	Vector crossProduct(Vector vector);
	void normalize();
	void normalize3d();
	void absolute();
	void show(FWApplication* application);
	void showPoint(FWApplication* application);
	void showLine(Vector vector, FWApplication* application);
	std::vector<float> getVector() const;

private:
	int size_;
	std::vector<float> vector_;
};
