#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int mas[] = { 30, 70, 59, 11, 67, 40, 23, 10, 19, 46, 61, 40, 20, 66, 17, 27, 31, 57, 42, 5, 59, 57, 31, 52, 49 };
			int expectedCount = 21;  // Очікувана кількість елементів
			int actualCount = 0;

			// Рахуємо кількість елементів, кратних 6 або індекси яких не кратні 5
			for (int i = 0; i < 25; i++) {
				if (mas[i] % 6 == 0 || i % 5 != 0) {
					actualCount++;
				}
			}

			Assert::AreEqual(expectedCount, actualCount);  // Перевірка кільк
		}
	};
}
