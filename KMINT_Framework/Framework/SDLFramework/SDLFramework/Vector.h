#pragma once

#include "FWApplication.h"

class Vector
{
public:
	Vector(const float xDirection, const float yDirection);
	~Vector();
	Vector scale(const float scalair) const;
	Vector addVector(const Vector vector) const;
	Vector subtractVector(const Vector vector) const;
	void show(FWApplication* application);
	void showPoint(FWApplication* application);
	void showLine(Vector vector, FWApplication* application);
	float getX() const;
	float getY() const;

private:
	float xDirection_;
	float yDirection_;
};
