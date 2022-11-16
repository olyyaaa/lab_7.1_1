#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.1_1/lab_7.1_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreateFunction)
		{
			double expected = -0.42976727906624879;

			double res = Create(int** b, const int rowCount, const int colCount, const int Low, const int High);

			Assert::AreEqual(res, expected);
		}
	};
}
