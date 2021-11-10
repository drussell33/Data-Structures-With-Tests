#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "list_queue.hpp"
#include <string> 
#include "list_stack.hpp"

using std::string;
using namespace  data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(ListQueueTests)
	{
	public:

		TEST_METHOD(DesctructorTest)
		{
			const CrtCheckMemory check;
		}

		TEST_METHOD(ListQueue_EnqueueAndDequeueShouldWork)
		{
			const CrtCheckMemory check;

			ListQueue<size_t> list;
			list.Enqueue(1);
			list.Enqueue(2);
			list.Enqueue(3);
			list.Enqueue(4);
			list.Enqueue(5);

			for (size_t i = 1; i < 6; ++i)
			{
				Assert::AreEqual(i, list.Dequeue());
			}
			Assert::IsTrue(list.Empty());
		}

		TEST_METHOD(ListQueue_ShouldThrowExceptiononEmptyListDequeue)
		{
			const CrtCheckMemory check;

			ListQueue<size_t> list;

			const auto should_throw = [&]
			{
				list.Dequeue();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ListQueueDequeue_EmptyListShouldThrowExceptionAfterEnqueueAndDequeue)
		{
			const CrtCheckMemory check;

			ListQueue<size_t> list;
			list.Enqueue(7);
			list.Dequeue();

			const auto should_throw = [&]
			{
				list.Dequeue();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ListQueueFront_ShouldWorkThenTHrowExceptionWhenEmpty)
		{
			const CrtCheckMemory check;

			ListQueue<size_t> list;
			list.Enqueue(7);
			list.Enqueue(3);
			list.Enqueue(1);

			size_t answer = 7;
			Assert::AreEqual(answer, list.Front());

			list.Dequeue();
			answer = 3;
			Assert::AreEqual(answer, list.Front());

			list.Dequeue();
			answer = 1;
			Assert::AreEqual(answer, list.Front());

			list.Dequeue();

			const auto should_throw = [&]
			{
				list.Dequeue();
			};

			Assert::ExpectException<AdtException>(should_throw);

			const auto should_throw_again = [&]
			{
				list.Front();
			};

			Assert::ExpectException<AdtException>(should_throw_again);
		}

		TEST_METHOD(ListQueueAssignmentOperator_ShouldWOrkWithDequeues)
		{
			const CrtCheckMemory check;

			ListQueue<size_t> list;
			list.Enqueue(7);
			list.Enqueue(3);
			list.Enqueue(1);


			auto list_2 = list;
			Assert::AreEqual(list_2.Front(), list.Front());

			list.Dequeue();
			list_2.Dequeue();

			Assert::AreEqual(list_2.Front(), list.Front());
			Assert::AreEqual(list_2.Size(), list.Size());
		}

		TEST_METHOD(ListQueueCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				ListQueue<size_t> aList;
				aList.Enqueue(5);

				ListQueue<size_t> bList(aList);

				Assert::IsFalse(bList.Empty());

				const size_t answer = 5;
				Assert::AreEqual(answer, bList.Front());

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
				ListQueue<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Enqueue(values[i]);
				}
				auto bList = aList;
				Assert::AreEqual(5, bList.Dequeue());
				Assert::AreEqual(5, aList.Dequeue());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(ListQueueEmpty_BoolEmptySholdBeTrue)
		{
			CrtCheckMemory check;

			ListQueue<int>  list;

			Assert::IsTrue(list.Empty());
			Assert::IsTrue(list.Size() == 0);

			list.Enqueue(6);
			list.Enqueue(6);
			list.Enqueue(6);

			Assert::IsTrue(list.Size() == 3);
			Assert::IsFalse(list.Empty());
		}

		TEST_METHOD(LinkedListClear_shouldWork)
		{
			CrtCheckMemory check;

			ListQueue<int>  list;

			Assert::IsTrue(list.Empty());
			Assert::IsTrue(list.Size() == 0);

			list.Enqueue(3);
			list.Enqueue(6);
			list.Enqueue(45);

			Assert::IsTrue(list.Size() == 3);
			Assert::IsFalse(list.Empty());
			Assert::AreEqual(3, list.Front());

			list.Clear();

			Assert::IsTrue(list.Empty());
			Assert::IsTrue(list.Size() == 0);

			list.Enqueue(6);

			Assert::IsTrue(list.Size() == 1);
			Assert::IsFalse(list.Empty());
			Assert::AreEqual(6, list.Front());
		}
	};
}