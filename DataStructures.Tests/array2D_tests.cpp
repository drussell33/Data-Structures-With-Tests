#include "pch.h"
#include "CppUnitTest.h"
#include "crtdbg.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "array2d.hpp"
#include <string>
#include <vector>

using std::string;
using namespace data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(Array2DTests)
	{
	public:

		Array2D<string> GetArray2DString() const
		{
			auto array = Array2D<string>(3, 4);

			for (auto i = 0u; i < 3; ++i)
			{
				for(auto j = 0u; j<4; ++j)
				{
					array[i][j] = std::to_string(i * j);
				}
			}
			return array; 
		}


		TEST_METHOD(Array2dCopyCtor)
		{
			CrtCheckMemory check_memory;

			auto array = GetArray2DString();

			auto array_2(array);

			for (auto i = 0u; i < 3; ++i)
			{
				for (auto j = 0u; j < 4; ++j)
				{
					Assert::AreEqual(array_2[i][j], std::to_string(i * j));	
				}
			}	
		}

		TEST_METHOD(Array2dAssignmentOp)
		{
			CrtCheckMemory check_memory;

			auto array = GetArray2DString();

			auto array_2 = array;

			for (auto i = 0u; i < 3; ++i)
			{
				for (auto j = 0u; j < 4; ++j)
				{
					Assert::AreEqual(array_2[i][j], std::to_string(i * j));
				}
			}
		}

		TEST_METHOD(Array2DParamConstructorValidLengthTest)
		{
			CrtCheckMemory check;

			Array2D<int> array(5, 5);
			Assert::IsTrue(true);
		}

		TEST_METHOD(Array2DSetRowsBadLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array2D<int> array(5, 3);
				array.Rows(-15);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(Array2DSetColumnsBadLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array2D<int> array(5, 3);
				array.Columns(-15);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayDefaultConstructorTest)
		{
			CrtCheckMemory check;

			Array2D<int> my_array;
			Assert::IsTrue(true);
		}

		TEST_METHOD(Array2DNeutralColumnsTest)
		{
			CrtCheckMemory check;

			Array2D<int> my_array(5, 0);
			Assert::IsTrue(true);
		}

		TEST_METHOD(Array2DNeutralRowsTest)
		{
			CrtCheckMemory check;

			Array2D<int> my_array(0, 5);
			Assert::IsTrue(true);
		}


		TEST_METHOD(Array2DNegativeRowsConstructorTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = [] {Array2D<int> negative_row_array(-12, 2); };
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayOutOfBoundsNegativeTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array2D<int> my_array(5, 0);
				my_array[-2][0] = 1;
			};

			Assert::ExpectException<AdtException>(should_throw);

		}

		TEST_METHOD(Array2DOutOfBoundsPositiveTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array2D<int> my_array(5, 2);
				my_array[10][15] = 1;

			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(Array2DGetRowsTest)
		{
			CrtCheckMemory check;
			Array2D<int> my_array(1, 0);
			Assert::IsTrue(my_array.Rows());
		}

		TEST_METHOD(Array2DGetColumnsTest)
		{
			CrtCheckMemory check;
			Array2D<int> my_array(0, 1);
			Assert::IsTrue(my_array.Columns());
		}

		TEST_METHOD(Array2DMoveTest)
		{
			CrtCheckMemory check;
			{
				Array2D<int> my_array(3, 2);
				Array2D<int> my_array2(std::move(my_array));
			}
		}

		TEST_METHOD(Array2DMoveAssignmentTest)
		{
			CrtCheckMemory check;
			{
				Array2D<string> my_array(10, 5);
				my_array = GetArray2DString();
			}
		}


			TEST_METHOD(Array2DSetRowDataLossTest)
		{
			CrtCheckMemory check;
			Array2D<int> myArray(3, 3);
			int index = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					myArray[i][j] = index++;
			// 0 1 2
			// 3 4 5
			// 6 7 8
			myArray.Rows(2);
			// 0 1 2
			// 3 4 5
			// +
			//--------
			// 15
			int total = 0;
			for (int i = 0; i < myArray.Rows(); i++)
				for (int j = 0; j < myArray.Columns(); j++)
					total += myArray[i][j];
			Assert::IsTrue(total == 15);
		}
		TEST_METHOD(Array2DSetColumnDataLossTest)
		{
			CrtCheckMemory check;
			Array2D<int> myArray(3, 3);
			int index = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					myArray[i][j] = index++;
			// 0 1 2
			// 3 4 5
			// 6 7 8
			myArray.Columns(2);
			// 0 1
			// 3 4
			// 6 7
			// +
			//------
			// 21
			int total = 0;
			for (int i = 0; i < myArray.Rows(); i++)
				for (int j = 0; j < myArray.Columns(); j++)
					total += myArray[i][j];
			Assert::IsTrue(total == 21);
		}

		TEST_METHOD(Array2DSetColumnDataLossTestLargerArray)
		{
			CrtCheckMemory check;
			Array2D<int> myArray(4, 4);
			int index = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					myArray[i][j] = index++;
			// 0 1 2 3
			// 4 5 6 7
			// 8 9 10 11
			// 12 13 14 15
			myArray.Columns(3);
			// 0 1 2
			// 4 5 6
			// 8 9 10
			// 12 13 14 
			// +
			//------
			// 21
			int total = 0;
			for (int i = 0; i < myArray.Rows(); i++)
				for (int j = 0; j < myArray.Columns(); j++)
					total += myArray[i][j];
			Assert::IsTrue(total == 84);
		}

		TEST_METHOD(Array2DSelectOfFourByFourArrya)
		{
			CrtCheckMemory check;
			Array2D<int> myArray(4, 4);
			int index = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					myArray[i][j] = index++;
			// 0 1 2 3
			// 4 5 6 7
			// 8 9 10 11
			// 12 13 14 15

			int check_select = myArray.Select(3, 3);
			Assert::IsTrue(check_select == 15);
		}

		TEST_METHOD(Array2DSelectOfThreeByFiveArray)
		{
			CrtCheckMemory check;
			Array2D<int> myArray(3, 5);
			int index = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					myArray[i][j] = index++;
			// 0 1 2 3 4
			// 5 6 7 8 9
			// 10 11 12 13 14

			int check_select = myArray.Select(2, 3);
			Assert::IsTrue(check_select == 13);
		}
	};
}