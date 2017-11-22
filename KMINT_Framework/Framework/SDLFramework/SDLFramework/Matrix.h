#pragma once

#include <vector>
#include "Vector.h"

class Matrix
{
public:
	Matrix(const int size);
	~Matrix();
	void setPoint(const int index, const float x, const float y) const;
	Matrix scale(Matrix scale);
	void show(FWApplication* application) const;
	int getsize() const;
	float** getMatrix();

private:
	int size_;
	float* matrix_[2];
};

