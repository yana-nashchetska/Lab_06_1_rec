#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1.rec/Lab_06_1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61rec
{
	TEST_CLASS(UnitTest61rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int S = 0;
			int r[7] = { 4, -2, 6, 45, 5, 0, 2 };
			int t = Sum(r, 7, 0, 0);
			Assert::AreEqual(t, 58);
		}
	};
}
