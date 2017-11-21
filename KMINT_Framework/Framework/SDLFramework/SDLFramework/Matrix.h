#pragma once

#include <vector>
#include "Vector.h"

class Matrix
{
public:
	Matrix();
	~Matrix();
	void addVector(const Vector vector);
	Matrix scale(Matrix matrix);
	Matrix translate(const Matrix translateMatrix);
	void show(FWApplication* application);
	std::vector<Vector> getVertices();

private:
	std::vector<Vector> vertices;
};

