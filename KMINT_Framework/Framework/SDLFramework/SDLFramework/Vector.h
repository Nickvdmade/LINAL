#pragma once

#include "FWApplication.h"

class Vector
{
public:
	Vector(const float x, const float y);
	~Vector();
	Vector scale(const float scalair);
	Vector operator+(Vector vector);
	Vector operator-(Vector vector);
	void show(FWApplication* application);
	void showPoint(FWApplication* application);
	void showLine(Vector vector, FWApplication* application);
	float* getVector();

private:
	float vector_[2];
};
