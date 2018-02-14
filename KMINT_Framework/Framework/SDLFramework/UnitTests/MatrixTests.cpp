#include "stdafx.h"
#include "CppUnitTest.h"
#include "VectorTest.h"
#include "MatrixTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(MatrixSetMatrixItem)
		{
			MatrixTest matrix(3, 3);
			matrix.setItem(0, 0, 1);
			matrix.setItem(1, 1, 1);
			matrix.setItem(2, 2, 1);
			int rowSize = matrix.getRowSize();
			int colSize = matrix.getColSize();
			float** result = matrix.getMatrix();
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < colSize; j++)
				{
					if (i == j)
						Assert::AreEqual(static_cast<float>(1), result[i][j]);
					else
						Assert::AreEqual(static_cast<float>(0), result[i][j]);
				}
			}
		}

		TEST_METHOD(MatrixSetMatrixVector)
		{
			MatrixTest matrix(3, 3);
			VectorTest vector(3);
			vector.setItem(0, 1);
			matrix.setItem(0, vector);
			vector = VectorTest(3);
			vector.setItem(1, 1);
			matrix.setItem(1, vector);
			vector = VectorTest(3);
			vector.setItem(2, 1);
			matrix.setItem(2, vector);
			int rowSize = matrix.getRowSize();
			int colSize = matrix.getColSize();
			float** result = matrix.getMatrix();
			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < colSize; j++)
				{
					if (i == j)
						Assert::AreEqual(static_cast<float>(1), result[i][j]);
					else
						Assert::AreEqual(static_cast<float>(0), result[i][j]);
				}
			}
		}

		TEST_METHOD(MatrixMultiplicationUnitMatrix)
		{
			MatrixTest unitMatrix(3, 3);
			unitMatrix.setItem(0, 0, 1);
			unitMatrix.setItem(1, 1, 1);
			unitMatrix.setItem(2, 2, 1);
			MatrixTest matrix(3, 3);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					matrix.setItem(i, j, i + j);
			float** expectedMatrix = matrix.getMatrix();
			MatrixTest matrixResult = matrix * unitMatrix;
			float** result = matrixResult.getMatrix();
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(expectedMatrix[i][j], result[i][j]);
		}

		TEST_METHOD(MatrixMultiplicationWith2)
		{
			MatrixTest unitMatrix(3, 3);
			unitMatrix.setItem(0, 0, 2);
			unitMatrix.setItem(1, 1, 2);
			unitMatrix.setItem(2, 2, 2);
			MatrixTest matrix(3, 3);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					matrix.setItem(i, j, i + j);
			float** expectedMatrix = matrix.getMatrix();
			MatrixTest matrixResult = matrix * unitMatrix;
			float** result = matrixResult.getMatrix();
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(expectedMatrix[i][j] * 2, result[i][j]);
		}
	};
}