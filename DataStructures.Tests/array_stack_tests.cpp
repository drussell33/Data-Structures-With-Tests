#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "array_stack.hpp"
#include <string>

using std::string;
using namespace data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(ArrayStackTests)
	{
	public:

		ArrayStack<string> GetArrayStackString() const
		{
			auto array = ArrayStack<string>(10);
			array.Push("1");
			array.Push("2");
			array.Push("3");
			array.Push("4");
			array.Push("5");
			array.Push("6");
			array.Push("7");
			array.Push("8");

			return array;
		}
		
		TEST_METHOD(ArrayStackConstructor)
		{
			CrtCheckMemory check;

			auto stack = ArrayStack<string>(10);

			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayStackCopyCtor)
		{
			CrtCheckMemory check;
			
			auto array = GetArrayStackString();

			auto array_2(array);

			Assert::AreEqual(array.Pop() , array_2.Pop());
		}

		TEST_METHOD(ArrayStackAssignmentOperator)
		{
			CrtCheckMemory check;

			auto array = GetArrayStackString();

			auto array_2(array);

			Assert::AreEqual(array.Pop(), array_2.Pop());
		}

		TEST_METHOD(ArrayStackConstructorValidSizeTest)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				ArrayStack<int> array(-3);
			};
			Assert::ExpectException<AdtException>(should_throw);

		}

		TEST_METHOD(ArrayStackZeroSizeConstructorTest)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<string>(0);

			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayStackEmptyFunctionTest)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<string>(0);

			Assert::AreEqual(array.Empty(), true);
		}

		TEST_METHOD(ArrayStackSize6EmptyFunctionTest)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<string>(6);

			Assert::AreEqual(array.Empty(), true);
		}

		TEST_METHOD(ArrayStackEmptyFunctionWhenNotActuallyEmptyTest)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<string>(5);
			array.Push("1");

			Assert::AreEqual(array.Empty(), false);
		}

		TEST_METHOD(ArrayStackPushFunctionTestonEmptyArray)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<string>(5);
			array.Push("1");
			array.Push("2");
			array.Push("3");

			size_t actual_size = 3;

			Assert::AreEqual(array.Size(), actual_size);
		}

		TEST_METHOD(ArrayStackPushFunctionTestonFullArray)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				auto array = ArrayStack<string>(1);
				array.Push("1");
				array.Push("2");
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayStackPopFunctionWithEmptyArray)
		{
			CrtCheckMemory check;

			const auto should_throw = []
			{
				auto array = ArrayStack<string>(1);
				array.Push("1");
				array.Pop();
				array.Pop();
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayStackPopFunction)
		{
			CrtCheckMemory check;

				auto array = ArrayStack<int>(1);
				array.Push(5);
				auto result = array.Pop();
				Assert::AreEqual(result, 5);	
		}

		TEST_METHOD(ArrayStackPopMultipleTimesFunctionTest)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<int>(4);
			array.Push(5);
			array.Push(6);
			array.Push(7);
			array.Pop();
			array.Pop();
			auto result = array.Pop();
			Assert::AreEqual(result, 5);
		}

		TEST_METHOD(ArrayStackMoveTest)
		{
			CrtCheckMemory check;

			ArrayStack<string> stack(4);
			ArrayStack<string> stack_2(std::move(stack));
			
		}

		TEST_METHOD(ArrayStackClearFunctionTest)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<int>(4);
			array.Push(5);
			array.Push(6);
			array.Push(7);
			array.Clear();
			const size_t empty = 0;
			Assert::AreEqual(array.Size(), empty);
		}

		TEST_METHOD(ArrayStackPeekAndEnsureSize)
		{
			CrtCheckMemory check;

			auto array = GetArrayStackString();
			auto look_at_me = array.Peek();
			
			const size_t full = 8;
			Assert::AreEqual(array.Size(), full);
		}

		TEST_METHOD(ArrayStackPeakFromIntConstructor)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<int>(5);
			array.Push(9);
			auto look_at_me = array.Peek();

			const size_t full = 10;
			Assert::AreEqual(look_at_me, 9);
		}

		TEST_METHOD(ArrayStackPushAndPopStreeTestOnSize)
		{
			CrtCheckMemory check;

			auto array = ArrayStack<int>(9);
			array.Push(9);
			array.Push(3);
			array.Push(1);
			array.Push(2);
			array.Push(5);
			array.Pop();
			array.Pop();
			const size_t full = 3;

			Assert::AreEqual(array.Size(), full);
			
		}
	};

}