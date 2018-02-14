#include "stdafx.h"
#include "CppUnitTest.h"
#include "VectorTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(VectorSetVector)
		{
			VectorTest vector(3);
			for (int i = 0; i < 3; i++)
				vector.setItem(i, i);
			std::vector<float> result = vector.getVector();
			for (float i = 0; i < 3; i++)
				Assert::AreEqual(i, result[i]);
		}

		TEST_METHOD(VectorScale)
		{
			VectorTest vector(3);
			for (int i = 0; i < 3; i++)
				vector.setItem(i, i);
			VectorTest vectorResult = vector.scale(2);
			std::vector<float> result = vectorResult.getVector();
			std::vector<float> expectedResult = { 0,2,4 };
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(expectedResult[i], result[i]);
		}

		TEST_METHOD(VectorAddition)
		{
			VectorTest vector1(3);
			VectorTest vector2(3);
			for (int i = 0; i < 3; i++)
			{
				vector1.setItem(i, i);
				vector2.setItem(i, 10 - i);
			}
			VectorTest vectorResult = vector1 + vector2;
			std::vector<float> result = vectorResult.getVector();
			std::vector<float> expectedResult = { 10,10,10 };
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(expectedResult[i], result[i]);
		}

		TEST_METHOD(VectorSubtraction)
		{
			VectorTest vector1(3);
			VectorTest vector2(3);
			for (int i = 0; i < 3; i++)
			{
				vector1.setItem(i, i);
				vector2.setItem(i, 10 - i);
			}
			VectorTest vectorResult = vector1 - vector2;
			std::vector<float> result = vectorResult.getVector();
			std::vector<float> expectedResult = { -10,-8,-6 };
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(expectedResult[i], result[i]);
		}

		TEST_METHOD(VectorDotProduct)
		{
			VectorTest vector(3);
			for (int i = 0; i < 3; i++)
				vector.setItem(i, i);
			float result = vector.dotProduct(vector);
			float expectedResult = 5;
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(VectorCrossProduct)
		{
			VectorTest vector1(3);
			vector1.setItem(0, 1);
			VectorTest vector2(3);
			vector2.setItem(1, 1);
			VectorTest vectorResult = vector1.crossProduct(vector2);
			std::vector<float> result = vectorResult.getVector();
			std::vector<float> expectedResult = { 0,0,1 };
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(expectedResult[i], result[i]);
			
			vectorResult = vector2.crossProduct(vector1);
			result = vectorResult.getVector();
			expectedResult = { 0,0,-1 };
			for (int i = 0; i < 3; i++)
				Assert::AreEqual(expectedResult[i], result[i]);
		}
	};
}