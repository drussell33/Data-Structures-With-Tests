#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"

#include "array_queue.hpp"
#include <string>

using std::string;
using namespace data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(ArrayQueueTests)
	{
	public:

		ArrayQueue<string> GetArrayQueueString() const
		{
			auto array = ArrayQueue<string>(10);
			array.Enqueue("1");
			array.Enqueue("2");
			array.Enqueue("3");
			array.Enqueue("4");
			array.Enqueue("5");
			array.Enqueue("6");
			array.Enqueue("7");

			return array;
		}

		TEST_METHOD(ArrayStackConstructor)
		{
			CrtCheckMemory check;

			auto stack = ArrayQueue<string>(10);

			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayQueueParamConstructorValidSizeTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> array(5);
			Assert::IsTrue(true);

		}
		TEST_METHOD(ArrayQueueParamConstructorBadSizeTest_ShouldThrowException)
		{
			CrtCheckMemory check;

			const auto should_throw = [] { ArrayQueue<int> array(-15); };
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayQueueDefaultConstructorTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array;
			Assert::IsTrue(true);
		}

		TEST_METHOD(ArrayQueueSopyConstructorTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			auto array_copy(my_array);
			const int digit = array_copy.Dequeue();

			Assert::IsTrue(digit == 7);
		}

		TEST_METHOD(ArrayQueueAssignmentOperatorTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(9);
			my_array.Enqueue(2);
			auto array_copy = my_array;
			array_copy.Dequeue();
			const int digit = array_copy.Dequeue();

			Assert::IsTrue(digit == 9);
		}
		
		TEST_METHOD(ArrayQueueGetSizeOnEmptyQueue)
		{
			CrtCheckMemory check;
			ArrayQueue<string> my_array(10);
			Assert::IsTrue(my_array.Size() == 0);	
		}

		TEST_METHOD(ArrayQueueGetSizeOnOneSizeQueue)
		{
			CrtCheckMemory check;
			ArrayQueue<string> my_array(3);
			my_array.Enqueue("FirstData");
			Assert::IsTrue(my_array.Size() == 1);
		}

		TEST_METHOD(ArrayQueueEnQueueAndDequeueTests)
		{
			CrtCheckMemory check;

			auto my_array = GetArrayQueueString();
			my_array.Dequeue();
			my_array.Dequeue();

			Assert::IsTrue(my_array.Dequeue() == "3");
		}

		TEST_METHOD(ArrayQueueEnQueueAndDequeueMultipleTests)
		{
			CrtCheckMemory check;

			auto my_array = GetArrayQueueString();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Enqueue("8");
			my_array.Enqueue("9");
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();

			Assert::IsTrue(my_array.Dequeue() == "8");
		}

		TEST_METHOD(ArrayQueueEnQueueAndDequeueMultipleTestsForSize)
		{
			CrtCheckMemory check;

			auto my_array = GetArrayQueueString();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Enqueue("8");
			my_array.Enqueue("9");
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();

			Assert::IsTrue(my_array.Size() == 2);
		}
		TEST_METHOD(ArrayQueueThatWillThrowAnExceptionWhenTryingToDequeueOutEmpty)
		{
			CrtCheckMemory check;
			const auto should_throw = []
			{
				ArrayQueue<int> my_array(3);
				my_array.Enqueue(7);
				my_array.Enqueue(7);
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Dequeue();
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayQueueThatWillThrowAnExceptionWhenTryingToEnqueueInFull)
		{
			CrtCheckMemory check;
			const auto should_throw = []
			{
			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayQueueClearFunctionTest)
		{
			CrtCheckMemory check;

			auto array = GetArrayQueueString();
			array.Clear();
			array.Enqueue("9");

			Assert::IsTrue(array.Size() == 1);
		}

		TEST_METHOD(ArrayQueueClearBasicFunctionTest)
		{
			CrtCheckMemory check;

			auto array = GetArrayQueueString();
			array.Clear();

			Assert::IsTrue(array.Size() == 0);
		}

		TEST_METHOD(ArrayQueueFullBasicTest)
		{
			CrtCheckMemory check;

				ArrayQueue<int> my_array(3);
				my_array.Enqueue(7);
				my_array.Enqueue(7);
				my_array.Enqueue(7);

			
			Assert::IsTrue(my_array.Full() == true);
		}

		TEST_METHOD(ArrayQueueFullAfterBothDequeueAndEnqueueTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Dequeue();
			my_array.Enqueue(7);
			my_array.Dequeue();
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);


			Assert::IsTrue(my_array.Full() == true);
		}
		
		TEST_METHOD(ArrayQueueAfterDequeueRemovesFrontElements)
		{
			CrtCheckMemory check;

 			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Dequeue();
 			my_array.Dequeue();
			my_array.Enqueue(3);
			my_array.Enqueue(3);

			Assert::IsTrue(my_array.Front() == 7);
		}

		TEST_METHOD(ArrayQueueAfterDequeueRemovesAllElements)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Enqueue(3);
			my_array.Enqueue(3);

			Assert::IsTrue(my_array.Front() == 3);
		}

		TEST_METHOD(ArrayQueueSizeAfterDequeueRemovesAllElements)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Enqueue(3);
			my_array.Enqueue(3);

			Assert::IsTrue(my_array.Size() == 2);
		}

		TEST_METHOD(ArrayQueueThatWillThrowAnExceptionWhenTryingToEnqueueInFullAfterDequeues)
		{
			CrtCheckMemory check;
			const auto should_throw = []
			{
				ArrayQueue<int> my_array(3);
				my_array.Enqueue(7);
				my_array.Enqueue(7);
				my_array.Enqueue(7);
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Enqueue(3);
				my_array.Enqueue(3);
				my_array.Enqueue(3);
				my_array.Enqueue(3);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArrayClearAndEnqueuetoFullSizeTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Clear();
			my_array.Enqueue(3);
			my_array.Enqueue(3);
			my_array.Enqueue(3);

			Assert::IsTrue(my_array.Full() == true);
		}

		TEST_METHOD(ArrayClearAndEnqueuetoFullAndDequeueToEmptyTest)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Enqueue(7);
			my_array.Clear();
			my_array.Enqueue(3);
			my_array.Enqueue(3);
			my_array.Enqueue(3);
			my_array.Dequeue();
			my_array.Dequeue();
			my_array.Dequeue();

			Assert::IsTrue(my_array.Empty() == true);
		}

		TEST_METHOD(ArrayQueueThatWillThrowAnExceptionWhenTryingToDequeueOnEMpty)
		{
			CrtCheckMemory check;
			const auto should_throw = []
			{
				ArrayQueue<int> my_array(3);
				my_array.Enqueue(7);
				my_array.Enqueue(7);
				my_array.Enqueue(7);
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Enqueue(3);
				my_array.Enqueue(3);
				my_array.Enqueue(3);
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Dequeue();
				my_array.Dequeue();
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(ArratQueueStressTestCyclcingOneByOneUntilEmpty)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Dequeue();
			my_array.Enqueue(6);
			my_array.Dequeue();
			my_array.Enqueue(5);
			my_array.Dequeue();
			my_array.Enqueue(4);
			my_array.Dequeue();

			Assert::IsTrue(my_array.Empty() == true);
		}

		TEST_METHOD(ArratQueueStressTestCyclcingOneByOneUntilReturnLastDequeue)
		{
			CrtCheckMemory check;

			ArrayQueue<int> my_array(3);
			my_array.Enqueue(7);
			my_array.Dequeue();
			my_array.Enqueue(6);
			my_array.Dequeue();
			my_array.Enqueue(5);
			my_array.Dequeue();
			my_array.Enqueue(4);
			

			Assert::IsTrue(my_array.Dequeue() == 4);
		}
	};

}