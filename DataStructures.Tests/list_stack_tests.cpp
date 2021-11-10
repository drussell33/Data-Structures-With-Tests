#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "list_stack.hpp"
#include <string> 

using std::string;
using namespace  data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(ListStackTests)
	{
	public:

		TEST_METHOD(DesctructorTest)
		{
			const CrtCheckMemory check;

			ListStack<size_t> list;
		}

		TEST_METHOD(ListStackPush_ShouldWork)
		{
			const CrtCheckMemory check;

			ListStack<size_t> list;
			list.Push(1);
			list.Push(2);
			list.Push(3);
			list.Push(4);
			list.Push(5);

			for(size_t i = 5; i > 0; i--)
			{
				Assert::AreEqual(i, list.Pop());
			}
			Assert::IsTrue(list.Empty());
		}

		TEST_METHOD(ListStackPop_EmptyListShouldThrowException)
		{
			const CrtCheckMemory check;

			ListStack<size_t> list;

			const auto should_throw = [&]
			{
				list.Pop();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ListStackPop_EmptyListShouldThrowExceptionAfterPushTHenPop)
		{
			const CrtCheckMemory check;

			ListStack<size_t> list;
			list.Push(7);
			list.Pop();

			const auto should_throw = [&]
			{
				list.Pop();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ListStackPeek_ShouldWork)
		{
			const CrtCheckMemory check;

			ListStack<size_t> list;
			list.Push(7);
			list.Push(3);
			list.Push(1);

			size_t answer = 1;
			Assert::AreEqual(answer, list.Peek());

			list.Pop();
			answer = 3;
			Assert::AreEqual(answer, list.Peek());

			list.Pop();
			answer = 7;
			Assert::AreEqual(answer, list.Peek());

			list.Pop();
			
			const auto should_throw = [&]
			{
				list.Peek();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ListStackAssignmentOperator_ShouldWOrkWithPops)
		{
			const CrtCheckMemory check;

			ListStack<size_t> list;
			list.Push(7);
			list.Push(3);
			list.Push(1);


			auto list_2 = list;
			Assert::AreEqual(list_2.Peek(), list.Peek());

			list.Pop();
			list_2.Pop();

			Assert::AreEqual(list_2.Peek(), list.Peek());
			Assert::AreEqual(list_2.Size(), list.Size());
		}

		TEST_METHOD(ListStackCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<size_t> aList;
				aList.Push(5);

				ListStack<size_t>  bList(aList);

				Assert::IsFalse(bList.Empty());
				const size_t answer = 5;
				Assert::AreEqual(answer, bList.Peek());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(ListStackPopAndAssignment_SHouldWork)
		{
			CrtCheckMemory check;
			try
			{
				ListStack<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Push(values[i]);
				}
				auto bList = aList;
				Assert::AreEqual(45, bList.Pop());
				Assert::AreEqual(45, aList.Pop());
				
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListEmpty_BoolEmptySholdBeTrue)
		{
			CrtCheckMemory check;
			
				ListStack<int>  list;

				Assert::IsTrue(list.Empty());
				Assert::IsTrue(list.Size() == 0);

				list.Push(6);
				list.Push(6);
				list.Push(6);

				Assert::IsTrue(list.Size() == 3);
				Assert::IsFalse(list.Empty());
		}

		TEST_METHOD(LinkedListClear_shouldWork)
		{
			CrtCheckMemory check;

			ListStack<int>  list;

			Assert::IsTrue(list.Empty());
			Assert::IsTrue(list.Size() == 0);

			list.Push(6);
			list.Push(6);
			list.Push(45);

			Assert::IsTrue(list.Size() == 3);
			Assert::IsFalse(list.Empty());
			Assert::AreEqual(45, list.Pop());

			list.Clear();

			Assert::IsTrue(list.Empty());
			Assert::IsTrue(list.Size() == 0);

			list.Push(6);

			Assert::IsTrue(list.Size() == 1);
			Assert::IsFalse(list.Empty());
			Assert::AreEqual(6, list.Pop());
		}
		
	};
}