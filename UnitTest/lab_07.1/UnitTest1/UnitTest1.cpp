#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.1/lab_07.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForMatrix
{
	TEST_CLASS(UnitTestForMatrix)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			// ��������� �������
			const int rowCount = 7;
			const int colCount = 6;
			const int Low = 7;
			const int High = 62;

			// �������� ���'��� ��� �������
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// ��������� �������
			Create(a, rowCount, colCount, Low, High);

			// ����������, �� ����� ������� ������� � ����� [Low, High]
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High, L"������� �� ������ ��������");
				}
			}

			// ��������� ���'��
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
