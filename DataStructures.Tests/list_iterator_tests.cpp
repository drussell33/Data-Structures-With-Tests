#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "linked_list.hpp"
#include "list_iterator.hpp"
#include <string>

using std::string;
using namespace  data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(ListIteratorTests)
	{
	public:
		TEST_METHOD(ForwardIteratorBegin_ShouldTHrowExceptionOnEmptyList)
		{
			const CrtCheckMemory check;
			LinkedList<size_t> list;

			const auto should_throw = [&]
			{
				auto forward_iterator_1 = list.ForwardBegin();
			};
			
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ForwardIteratorEnd_ShouldTHrowExceptionOnEmptyList)
		{
			const CrtCheckMemory check;
			LinkedList<size_t> list;

			const auto should_throw = [&]
			{
				auto forward_iterator_1 = list.ForwardEnd();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(BackwardIteratorBegin_ShouldTHrowExceptionOnEmptyList)
		{
			const CrtCheckMemory check;
			LinkedList<size_t> list;

			const auto should_throw = [&]
			{
				auto forward_iterator_1 = list.BackwardBegin();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(BackwardIteratorEnd_ShouldTHrowExceptionOnEmptyList)
		{
			const CrtCheckMemory check;
			LinkedList<size_t> list;

			const auto should_throw = [&]
			{
				auto forward_iterator_1 = list.BackwardEnd();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ForwardIteratorBegin_ShouldBeSameAsEndOnListWithOneNode)
		{
			const CrtCheckMemory check;
			LinkedList<size_t> list;
			list.Append(6);

			const auto forward_iterator = list.ForwardBegin();
			const auto forward_iterator2 = list.ForwardEnd();

			Assert::IsTrue(*forward_iterator == *forward_iterator2);
		}

		TEST_METHOD(BackwardIteratorBegin_ShouldBeSameAsEndOnListWithOneNode)
		{
			const CrtCheckMemory check;
			LinkedList<size_t> list;
			list.Append(6);

			const auto forward_iterator = list.BackwardBegin();
			const auto forward_iterator2 = list.BackwardEnd();

			Assert::IsTrue(*forward_iterator == *forward_iterator2);
		}

		TEST_METHOD(ForwardIteratorAssignmentOperator_ShouldAssign)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			auto forward_iterator_1 = list.ForwardBegin();
			auto forward_iterator_2 = ForwardIterator<size_t>();
			forward_iterator_2 = forward_iterator_1;

			Assert::IsTrue(*forward_iterator_2 == *forward_iterator_1);
		}

		TEST_METHOD(ForwardIteratorBeginTest_FirstShoulEqualOperatorStar)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto forward_iterator = list.ForwardBegin();

			Assert::AreEqual(list.First(), *forward_iterator);
		}

		TEST_METHOD(BackwardIteratorBeginTest_LastShouldEqualOperatorStar)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto backward_iterator = list.BackwardBegin();

			Assert::AreEqual(list.Last(), *backward_iterator);
		}

		TEST_METHOD(ForwardIteratorEndTest_ForwardIteratorShouldBeDone)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto forward_iterator = list.ForwardEnd();

			Assert::IsTrue(forward_iterator.Done());
		}

 		TEST_METHOD(BackwardIteratorEndTest_BackwardIteratorShouldBeDone)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}
			 
			auto backward_iterator = list.BackwardEnd();

			Assert::IsTrue(backward_iterator.Done());
		}

		TEST_METHOD(ForwardIteratorBeginNextTest_ValuesShouldEqualIteratedValues)
		{
			CrtCheckMemory check;
			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
			size_t i = 0;

			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			for (auto forward_iterator = list.ForwardBegin(); forward_iterator != list.ForwardEnd(); ++forward_iterator)
				Assert::AreEqual(values[i++], *forward_iterator);

		}

		TEST_METHOD(BackwardIteratorBeginNextTest_ValuesShouldEqualIteratedValues)
		{
			CrtCheckMemory check;
			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
			size_t i = 6;

			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			for (auto backward_iterator = list.BackwardBegin(); backward_iterator != list.BackwardEnd(); ++backward_iterator)
				Assert::AreEqual(values[i--], *backward_iterator);
		}

		TEST_METHOD(ForwardIteratorAssignment_ForwardBeginShouldReturnFirst)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i * 5);
			}

			const auto forward_iterator = list.ForwardBegin();

			Assert::AreEqual(list.First(), *forward_iterator);
		}

		TEST_METHOD(BackwardIteratorAssignment_BackwardBeginShouldReturnLast)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;

			for (size_t i = 0; i < 5; ++i)
			{
				list.Append(i);
			}

			const auto backward_iterator = list.BackwardBegin();

			Assert::AreEqual(list.Last(), *backward_iterator);
		}

		TEST_METHOD(ForwardIteratorReset)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto forward_iterator = list.ForwardBegin();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					++forward_iterator;
				}

				forward_iterator.Reset();
			}
			//forward_iterator.Reset();

			Assert::AreEqual(list.First(), *forward_iterator);
		}

		TEST_METHOD(BackwardIteratorReset_ShouldReset)
		{
			CrtCheckMemory check;
			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto backward_iterator = list.BackwardBegin();


			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					++backward_iterator;
				}

				backward_iterator.Reset();
			}

			Assert::AreEqual(list.Last(), *backward_iterator);
		}

		TEST_METHOD(ForwardIteratorMoveNext_ShouldMoveNext)
		{
			CrtCheckMemory check;
			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
			size_t i = 0;

			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto forward_iterator = list.ForwardBegin();

			while (!forward_iterator.Done())
			{
				Assert::AreEqual(values[i++], *forward_iterator++);
			}
		}

		TEST_METHOD(ForwardIteratorBeginMoveNext_ShouldStaySameWithOneNodeList)
		{
			CrtCheckMemory check;

			LinkedList<size_t> list;
			list.Append(1);

			auto forward_iterator = list.ForwardBegin();

			forward_iterator.MoveNext();

			Assert::IsTrue(*forward_iterator == 1);

		}

		TEST_METHOD(ForwardIteratorEndMoveNext_ShouldStaySameWithOneNodeList)
		{
			CrtCheckMemory check;

			LinkedList<size_t> list;
			list.Append(1);

			auto forward_iterator = list.ForwardEnd();

			forward_iterator.MoveNext();

			Assert::IsTrue(*forward_iterator == 1);

		}

		TEST_METHOD(BackwardIteratorBeginMoveNext_ShouldStaySameWithOneNodeList)
		{
			CrtCheckMemory check;

			LinkedList<size_t> list;
			list.Append(1);

			auto backward_iterator = list.BackwardBegin();

			backward_iterator.MoveNext();

			Assert::IsTrue(*backward_iterator == 1);

		}

		TEST_METHOD(BackwardIteratorEndMoveNext_ShouldStaySameWithOneNodeList)
		{
			CrtCheckMemory check;

			LinkedList<size_t> list;
			list.Append(1);

			auto backward_iterator = list.BackwardEnd();

			backward_iterator.MoveNext();

			Assert::IsTrue(*backward_iterator == 1);

		}

		TEST_METHOD(BackwardIteratorMoveNext_ShouldMoveNext)
		{
			CrtCheckMemory check;
			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };
			auto i = 6;

			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);
			list.Append(6);
			list.Append(7);

			auto backward_iterator = list.BackwardBegin();

			while (backward_iterator != list.BackwardEnd())
			{
				Assert::AreEqual(values[i--], *backward_iterator++);
			}
		}

		TEST_METHOD(PreAndPostFixOperations_ShouldIncrementPreAndPost)
		{
			CrtCheckMemory check;
			size_t values[] = { 1, 2, 3, 4, 5, 6, 7 };

			LinkedList<size_t> list;
			list.Append(1);
			list.Append(2);
			list.Append(3);
			list.Append(4);
			list.Append(5);

			auto forward_iterator = list.ForwardBegin();

			const auto current_value = *forward_iterator;
			Assert::AreEqual(static_cast<size_t>(1), current_value);

			const auto value_with_post_increment = *forward_iterator++;
			Assert::AreEqual(static_cast<size_t>(1), value_with_post_increment);

			const auto value_after_post_increment = *forward_iterator;
			Assert::AreEqual(static_cast<size_t>(2), value_after_post_increment);

			const auto value_with_pre_increment = *++forward_iterator;
			Assert::AreEqual(static_cast<size_t>(3), value_with_pre_increment);

			const auto value_after_pre_increment = *forward_iterator;
			Assert::AreEqual(static_cast<size_t>(3), value_after_pre_increment);
		}

		
	};
}