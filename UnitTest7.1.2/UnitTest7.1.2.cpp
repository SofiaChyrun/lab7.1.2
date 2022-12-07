#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab7.1.2/ChyrunSofialab7.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest712
{
	TEST_CLASS(UnitTest712)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int l = 2, n = 3;
			int S = 0, k = 0;
			int** a = new int* [l];
			for (int i = 0; i < l; i++)
				a[i] = new int[n];
			for (int i = 0; i < l; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = i + j + 1;
			t = Calc(a, l, n, k, 0, 0);
			Assert::AreEqual(t, 11);
		}
	};
}
