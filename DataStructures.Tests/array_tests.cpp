#include "pch.h"
#include "CppUnitTest.h"
#include "crtdbg.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "array.hpp"
#include <string>
#include <vector>

using std::string;
using namespace data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests


{
	TEST_CLASS(ArrayTests)
	{
	public:
		Array<string> GetArrayString() const
		{
			auto array = Array<string>(10);
			for (auto i = 0u; i < 10; ++i)
			{
				array[i] = std::to_string(i);
			}
			return array;
		}

		//TEST_METHOD(ArrayStringConstructor)
		//{
		//	data_structures_tests::CrtCheckMemory check_memory;

		//	auto array_main = GetArrayString();

		//	auto array = Array<string>(10);
		//	for (auto i = 0u; i < 10; ++i)
		//	{
		//		array[i] = std::to_string(i);
		//	}

		//	for (auto i = 0u; i < 10; ++i)
		//	{
		//		Assert::AreEqual(array_main[i], array[i]);
		//	}
	
		//}
		
		TEST_METHOD(ArrayConstructor)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			auto array_length_10 = Array<string>(10);

			for (auto i = 0u; i < 10; ++i)
			{
				array_length_10[i] = std::to_string(i);
			}


			for (auto i = 0u; i < 10; ++i)
			{
				Assert::AreEqual(array_length_10[i], std::to_string(i));
			}
		}

		TEST_METHOD(ArrayCopyCtor)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			auto array = Array<string>(10, 0);
			for (auto i = 0u; i < 10; ++i)
			{
				array[i] = std::to_string(i);
			}

			auto array_copy = Array<string>(array);

			for (auto i = 0u; i < array.Length(); ++i)
			{
				Assert::AreEqual(array_copy[i], array[i]);
			}
			
		}

		TEST_METHOD(ArrayAssignmentOp)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			Array<string> array_of_strings(10);

			for (auto i = 0u; i < array_of_strings.Length(); ++i)
			{
				array_of_strings[i] = std::to_string(i);
			}

			auto array_of_strings_copy = array_of_strings;

			for (size_t i = 0; i < array_of_strings_copy.Length(); ++i)
			{
				Assert::AreEqual(array_of_strings[i], array_of_strings_copy[i]);
			}
		}
		
		TEST_METHOD(ArrayMoveCtor)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			auto array = Array<string>(10);
			for (auto i = 0u; i < 10; ++i)
			{
				array[i] = std::to_string(i);
			}

			auto array_test = Array<string>(10);
			for (auto i = 0u; i < 10; ++i)
			{
				array_test[i] = std::to_string(i);
			}
			
			auto array2(array);

			for (auto i = 0u; i < 10; ++i)
			{
				Assert::AreEqual(array2[i], array_test[i]);
			}
		}

		TEST_METHOD(ArrayMoveAssignmentOp)
		{
			data_structures_tests::CrtCheckMemory check_memory;
		}
		TEST_METHOD(ArrayIndexTest)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			Array<size_t> array(10, 0);

			for (size_t i = 0u; i < array.Length(); ++i)
			{
				array[i] = i;
			}

			for (size_t i = 0u; i < array.Length(); ++i)
			{
				Assert::AreEqual(i, array[i]);
			}

		}

		TEST_METHOD(BoolTest)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			Array<size_t> array(10, 0);
			
			auto check = false;

			if (array)
			{
				check = true;
			}

			else
				check = false;

			Assert::IsTrue(check);

		}

		TEST_METHOD(BoolOperatorTest)
		{
			auto array_main = Array<string>(10);
			for (auto i = 0u; i < 10; ++i)
			{
				array_main[i] = std::to_string(i);
			}

			auto array_rhs = Array<string>(10);
			for (auto i = 0u; i < 10; ++i)
			{
				array_rhs[i] = std::to_string(i);
			}

			auto check = false;

			if (array_main == array_rhs)
			{
				check = true;
			}

			else
				check = false;

			Assert::IsTrue(check);
		}
		
		TEST_METHOD(SetLength)
		{
			data_structures_tests::CrtCheckMemory check_memory;

			auto array_length_10 = Array<string>(10,0);

			array_length_10.Length(20);

			auto array_tester = Array<string>(20, 0);

			Assert::AreEqual(array_length_10.Length(), array_tester.Length());

			
		}

		// this is where I copied all of the starter array tests

		static Array<size_t> ArrayFactory()
		{
			Array<size_t> array(10, 0);
			return array;
		}

		//TEST_METHOD_INITIALIZE(TestInit)
		//{
		//	freopen("UNIT_TEST_LOG.txt", "a+", stdout);
		//}

		TEST_METHOD(ArrayParamConstructorValidLengthTest)
		{
			CrtCheckMemory check;

			Array<int> array(5, 0);
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayParamConstructorBadLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = [] { Array<int> array(-15, 0); };
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArraySetLengthBadLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array<int> array(5, 0);
				array.Length(-15);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayDefaultConstructorTest)
		{
			CrtCheckMemory check;

			Array<int> my_array;
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayNeutralStartIndexTest)
		{
			CrtCheckMemory check;

			Array<int> my_array(5, 0);
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayPositiveStartIndexTest)
		{
			CrtCheckMemory check;

			Array<int> positive_array(5, 5);
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayNegativeStartIndexTest)
		{
			CrtCheckMemory check;

			Array<int> negative_array(5, -3);
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayCopyConstructorTest)
		{
			CrtCheckMemory check;

			Array<int> my_array(2, 0);
			for (int i = 0; i < 2; i++)
				my_array[i] = i;

			Array<int> copy_array(my_array);
			Assert::IsTrue(my_array[0] == copy_array[0] && my_array[1] == copy_array[1]);
		}

		TEST_METHOD(ArrayNegativeLengthConstructorTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = [] {Array<int> negative_length_array(-12, 0); };
			Assert::ExpectException<AdtException>(should_throw);

		}

		TEST_METHOD(ArrayOutOfBoundsNegativeTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array<int> my_array(5, 0);
				my_array[-2] = 1;
			};

			Assert::ExpectException<AdtException>(should_throw);

		}

		TEST_METHOD(ArrayOutOfBoundsPositiveTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array<int> my_array(5, 0);
				my_array[10] = 1;

			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayAssignmentOperatorTest)
		{
			CrtCheckMemory check;

			bool passed = true;
			Array<int> my_array(10, 0);
			for (int i = 0; i < 10; i++)
				my_array[i] = i;
			Array<int> copy_array;
			copy_array = my_array;
			for (int i = 0; i < 10; i++)
			{
				if (copy_array[i] != my_array[i])
					passed = false;
			}
			Assert::IsTrue(passed);
		}

		TEST_METHOD(ArraySubscriptOperatorTest)
		{
			CrtCheckMemory check;
			Array<int> my_array(3, 0);
			for (int i = 0; i < 3; i++)
				my_array[i] = 1;

			Assert::IsTrue(my_array[0] && my_array[1] && my_array[2]);
		}

		TEST_METHOD(ArrayGetLengthTest)
		{
			CrtCheckMemory check;
			Array<int> my_array(1, 0);
			Assert::IsTrue(my_array.Length());
		}

		TEST_METHOD(ArrayMoveTest)
		{
			CrtCheckMemory check;
			{
				Array<int> my_array(1, 0);
				Array<int> my_array2(std::move(my_array));
			}
		}

		TEST_METHOD(ArrayMoveAssignmentTest)
		{
			CrtCheckMemory check;
			{
				Array<size_t> my_array(10, 0);
				my_array = ArrayFactory();
			}
		}

		TEST_METHOD(ArrayGetStartIndexTest)
		{
			CrtCheckMemory check;

			Array<int> my_array(1, 1);
			Assert::AreEqual(1, my_array.StartIndex());
		}

		TEST_METHOD(ArraySetLengthTest)
		{
			CrtCheckMemory check;

			Array<int> my_array(10, 0);
			for (int i = 0; i < 10; i++)
				my_array[i] = i;
			// Will lose value_
			my_array.Length(5);
			Assert::AreEqual(static_cast<size_t>(5), my_array.Length());
		}

		TEST_METHOD(ArrayGrowLengthTest)
		{
			CrtCheckMemory check;

			Array<int> array(5, 0);
			array.Length(10);
			Assert::AreEqual(static_cast<size_t>(10), array.Length());
		}

		TEST_METHOD(StringArrayDefaultCtorTest)
		{
			CrtCheckMemory check;

			Array<string> default_constructor;
			Assert::IsTrue(true);
		}

		TEST_METHOD(StringArrayNeutralIndexTest)
		{
			CrtCheckMemory check;

			Array<string> neutral_index(1, 0);
			Assert::IsTrue(true);
		}

		TEST_METHOD(StringArrayPositiveIndexTest)
		{
			CrtCheckMemory check;

			Array<string> string_array_positive_index(5, 5);
			Assert::IsTrue(true);
		}

		TEST_METHOD(StringArrayNegativeIndexTest)
		{
			CrtCheckMemory check;

			Array<string> negative_index(1, -1);
			Assert::IsTrue(true);
		}

		TEST_METHOD(StringArrayNegativeLengthCtorTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = [] { Array<string> bad_string_array(-5, 0); };
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(StringArrayNegativeSetLengthTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				Array<string> string_array(10, 0);
				string_array[-5] = "Bad String";
			};
			Assert::ExpectException<AdtException>(should_throw);
		}


		TEST_METHOD(StringArrayReduceLengthTest)
		{
			CrtCheckMemory check;

			Array<string> my_string_array;
			bool pass = true;
			my_string_array.Length(10);
			for (int i = 0; i < 10; i++)
				my_string_array[i] = ("Test String " + i);

			my_string_array.Length(5);
			for (int i = 0; i < 5; i++)
			{
				if (my_string_array[i] != "Test String " + i)
					pass = false;
			}
			Assert::IsTrue(pass);
		}


		
	};
}
