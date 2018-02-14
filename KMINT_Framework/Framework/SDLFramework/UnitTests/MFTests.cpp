#include "stdafx.h"
#include "CppUnitTest.h"
#include "MFTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(MFScale3d)
		{
			MatrixTest matrixResult = MFTest::scale3d(2, 3, 4);
			float** result = matrixResult.getMatrix();
			Assert::AreEqual(static_cast<float>(2), result[0][0]);
			Assert::AreEqual(static_cast<float>(3), result[1][1]);
			Assert::AreEqual(static_cast<float>(4), result[2][2]);

			Assert::AreEqual(static_cast<float>(1), result[3][3]);

			Assert::AreEqual(static_cast<float>(0), result[0][1]);
			Assert::AreEqual(static_cast<float>(0), result[0][2]);
			Assert::AreEqual(static_cast<float>(0), result[0][3]);
			Assert::AreEqual(static_cast<float>(0), result[1][0]);
			Assert::AreEqual(static_cast<float>(0), result[1][2]);
			Assert::AreEqual(static_cast<float>(0), result[1][3]);
			Assert::AreEqual(static_cast<float>(0), result[2][0]);
			Assert::AreEqual(static_cast<float>(0), result[2][1]);
			Assert::AreEqual(static_cast<float>(0), result[2][3]);
			Assert::AreEqual(static_cast<float>(0), result[3][0]);
			Assert::AreEqual(static_cast<float>(0), result[3][1]);
			Assert::AreEqual(static_cast<float>(0), result[3][2]);
		}

		TEST_METHOD(MFTranslate3d)
		{
			MatrixTest matrixResult = MFTest::translate3d(2, 3, 4);
			float** result = matrixResult.getMatrix();
			Assert::AreEqual(static_cast<float>(1), result[0][0]);
			Assert::AreEqual(static_cast<float>(1), result[1][1]);
			Assert::AreEqual(static_cast<float>(1), result[2][2]);
			Assert::AreEqual(static_cast<float>(1), result[3][3]);

			Assert::AreEqual(static_cast<float>(2), result[0][3]);
			Assert::AreEqual(static_cast<float>(3), result[1][3]);
			Assert::AreEqual(static_cast<float>(4), result[2][3]);

			Assert::AreEqual(static_cast<float>(0), result[0][1]);
			Assert::AreEqual(static_cast<float>(0), result[0][2]);
			Assert::AreEqual(static_cast<float>(0), result[1][0]);
			Assert::AreEqual(static_cast<float>(0), result[1][2]);
			Assert::AreEqual(static_cast<float>(0), result[2][0]);
			Assert::AreEqual(static_cast<float>(0), result[2][1]);
			Assert::AreEqual(static_cast<float>(0), result[3][0]);
			Assert::AreEqual(static_cast<float>(0), result[3][1]);
			Assert::AreEqual(static_cast<float>(0), result[3][2]);
		}
	};
}