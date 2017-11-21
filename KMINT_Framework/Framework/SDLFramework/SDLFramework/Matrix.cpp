#include "Matrix.h"

Matrix::Matrix()
{

}

Matrix::~Matrix()
{
}

void Matrix::addVector(const Vector vector)
{
	vertices.push_back(vector);
}

Matrix Matrix::scale(Matrix matrix)
{
	std::vector<Vector> dotVertices = matrix.getVertices();
	Matrix newMatrix;
	for (int i = 0; i < vertices.size(); i++)
		for (int j = 0; j < dotVertices.size(); j++)
		{

		}
}

void Matrix::show(FWApplication * application)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i].showPoint(application);
		vertices[i].showLine(vertices[(i + 1) % vertices.size()], application);
	}
}

std::vector<Vector> Matrix::getVertices()
{
	return vertices;
}
