#pragma once

#include <vector>
#include "Vector.h"

class Matrix
{
public:
	Matrix(const int size);
	~Matrix();
	void setItem(const int index, const Vector item);
	Matrix scale(Matrix scale);
	void show(FWApplication* application);
	int getSize() const;
	std::vector<Vector> getMatrix() const;

private:
	int size_;
	std::vector<Vector> matrix_;
};

