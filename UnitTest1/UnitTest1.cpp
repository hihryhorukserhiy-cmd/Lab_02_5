#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_2_5/Data.h"
#include "../lab_2_5/Data.cpp"
#include "../lab_2_5/Triad.h"
#include "../lab_2_5/Triad.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(Data::isLeapYear(2024));
			Assert::IsFalse(Data::isLeapYear(2023));

			Assert::AreEqual(29, Data::DaysInMonth(2024, 2));
			Assert::AreEqual(28, Data::DaysInMonth(2023, 2));
			Assert::AreEqual(31, Data::DaysInMonth(2025, 1));
		}
	};
}
