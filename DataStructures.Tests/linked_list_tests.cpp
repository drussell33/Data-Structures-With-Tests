#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "linked_list.hpp"
#include <string> 

using std::string;
using namespace  data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(LinkedListTests)
	{
	public:

		static LinkedList<size_t> GetList()
		{
			LinkedList<size_t> list1;

			for (auto i = 0u; i < 10; ++i)
				list1.Append(i);

			return list1;
		}

		static LinkedList<size_t> GetList3()
		{
			LinkedList<size_t> list1;

			for (auto i = 0u; i < 3; ++i)
				list1.Append(i);

			return list1;
		}

		TEST_METHOD(DesctructorTest)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list;

		/*	for (auto i = 0u; i < 10; ++i)
				list.Append(i);*/
		}

		TEST_METHOD(DestructorwithAppendTest)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list;

				for (auto i = 0u; i < 10; ++i)
					list.Append(i);
		}

		TEST_METHOD(AppendTest_shouldFillListWithValues)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0u; i < 10; ++i)
				list.Append(i);

			size_t counter = 0u;
			for (auto node = list.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(CopyConstructorTest_SHouldCopy)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			for (auto i = 0u; i < 10; ++i)
				list1.Append(i);

			LinkedList<size_t> list2(list1);
			Assert::AreEqual(static_cast<size_t>(10), list2.Size());
			size_t counter = 0;
			for (auto node = list2.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(AssignmentOperator_SHouldCopy)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			for (auto i = 0u; i < 10; ++i)
				list1.Append(i);

			LinkedList<size_t> list2;
			list2 = list1;
			
			Assert::AreEqual(static_cast<size_t>(10), list2.Size());
			size_t counter = 0;
			for (auto node = list2.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(MoveConstructorTest_ShouldMove)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list(std::move(GetList()));
			
			size_t counter = 0;
			for (auto node = list.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(BoolOperatorTest_ShouldPass)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			if (!list1) Assert::IsTrue(true);
			else Assert::Fail();
		}

		TEST_METHOD(Last_ShouldThrwoException)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			const auto should_throw = [&]
			{
				list1.Last();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(Last_SHouldReturn5)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(5);

			Assert::AreEqual(static_cast<size_t>(5), list1.Last());
		}

		TEST_METHOD(PrependTest_shouldFillListWithValues)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list;

			for (size_t i = 0u; i < 10; ++i)
				list.Prepend(i);

			size_t counter = 9u;
			Assert::AreEqual(static_cast<size_t>(10), list.Size());
			for (auto node = list.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter--, node->Value());
		}

		TEST_METHOD(First_ShouldThrwoException)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			const auto should_throw = [&]
			{
				list1.First();
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(First_SHouldReturn5)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(5);

			Assert::AreEqual(static_cast<size_t>(5), list1.First());
		}
		
		TEST_METHOD(InsertBefore_ShouldInsert8before1)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1 = GetList3();

			list1.InsertBefore(8u, 1u);

			Assert::AreEqual(static_cast<size_t>(4u), list1.Size());
			size_t counter = 2u;
				Assert::AreEqual(counter, list1.Last());
		}

		TEST_METHOD(InsertBefore_ShouldInsert8before2)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1 = GetList3();

			list1.InsertBefore(8u, 2u);

			Assert::AreEqual(static_cast<size_t>(4u), list1.Size());
			size_t counter = 2u;
			Assert::AreEqual(counter, list1.Last());
		}

		TEST_METHOD(InsertAfter_ShouldInsert8after2)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1 = GetList3();

			list1.InsertAfter(8u, 2u);

			Assert::AreEqual(static_cast<size_t>(4u), list1.Size());
			size_t counter = 8u;
			Assert::AreEqual(counter, list1.Last());
		}

		TEST_METHOD(InsertAfter_ShouldInsert8after1)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1 = GetList3();

			list1.InsertAfter(8u, 1u);

			Assert::AreEqual(static_cast<size_t>(4u), list1.Size());
			size_t counter = 2u;
			Assert::AreEqual(counter, list1.Last());
		}

		TEST_METHOD(InsertAfterAndInsertBeforeStressTest_ShouldWorkWHenAdedInOrder)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(1u);
			list1.Append(3u);
			list1.InsertBefore(2u, 3u);
			list1.Append(4);
			list1.InsertAfter(5u, 4u);

			size_t counter = 0u;
			Assert::AreEqual(static_cast<size_t>(6), list1.Size());
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(InsertBefore_ShouldThrowExceptionForEmptyList)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			const auto should_throw = [&]
			{
				list1.InsertBefore(2u, 3u);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(InsertAfter_ShouldThrowExceptionForEmptyList)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			const auto should_throw = [&]
			{
				list1.InsertAfter(2u, 3u);
			};
			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(InsertAfter_WIthOneNodeShouldWOrk)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);

			list1.InsertAfter(1u, 0u);

			size_t counter = 0u;
			Assert::AreEqual(static_cast<size_t>(2), list1.Size());
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

 		TEST_METHOD(InsertBefore_WIthOneNodeShouldWOrk)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(1u);

			list1.InsertBefore(0u, 1u);

			size_t counter = 0u;
			Assert::AreEqual(static_cast<size_t>(2), list1.Size());
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(InsertAfter_WIthTwoNodesAtTheEndShouldWork)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(1u);

			list1.InsertAfter(2u, 1u);

			size_t counter = 0u;
			Assert::AreEqual(static_cast<size_t>(3), list1.Size());
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(InsertBefore_WIthTwoNodesAtTheEndShouldWork)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(2u);

			list1.InsertBefore(1u, 2u);

			size_t counter = 0u;
			Assert::AreEqual(static_cast<size_t>(3), list1.Size());
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(RemoveLast_ShouldRemoveTheLastNodeit1ForTheLastt)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(1u);
			list1.Append(2u);
			
			list1.RemoveLast();
			Assert::AreEqual(static_cast<size_t>(2), list1.Size());

			Assert::AreEqual(static_cast<size_t>(1), list1.Last());
		}

		TEST_METHOD(RemoveLast_SHouldRemoveOneNodeAndWork)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.RemoveLast();
			Assert::AreEqual(static_cast<size_t>(0), list1.Size());

		}

		TEST_METHOD(RemoveLast_SHouldTHrowExceptiongOneEmptyList)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			const auto should_throw = [&]
			{
				list1.RemoveLast();
			};

			Assert::ExpectException<AdtException>(should_throw);
			Assert::AreEqual(static_cast<size_t>(0), list1.Size());

		}

		TEST_METHOD(RemoveLastAndAppend_SHouldAndAddALotToStressTestSHouldWOrk)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.RemoveLast();
			list1.Append(0u);
			list1.Append(1u);
			list1.Append(2u);
			list1.Append(3u);
			list1.RemoveLast();
			list1.RemoveLast();
			Assert::AreEqual(static_cast<size_t>(2), list1.Size());

			size_t counter = 0u;
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(RemoveFirst_ShouldRemoveTheLastNodeit1ForTheLast)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(1u);
			list1.Append(2u);

			list1.RemoveFirst();
			
			Assert::AreEqual(static_cast<size_t>(2), list1.Size());

			Assert::AreEqual(static_cast<size_t>(1), list1.First());
		}

		TEST_METHOD(RemoveFirst_SHouldRemoveOneNodeAndWork)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.RemoveFirst();
			Assert::AreEqual(static_cast<size_t>(0), list1.Size());

		}

		TEST_METHOD(RemoveFirst_SHouldTHrowExceptiongOneEmptyList)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			const auto should_throw = [&]
			{
				list1.RemoveFirst();
			};

			Assert::ExpectException<AdtException>(should_throw);
			Assert::AreEqual(static_cast<size_t>(0), list1.Size());

		}

		TEST_METHOD(RemoveFirstAndAppend_SHouldAndAddALotToStressTestSHouldWOrk)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.RemoveFirst();
			list1.Append(0u);
			list1.Append(1u);
			list1.Append(2u);
			list1.Append(3u);
			list1.RemoveFirst();
			list1.RemoveFirst();
			Assert::AreEqual(static_cast<size_t>(2), list1.Size());

			size_t counter = 2u;
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(Extract_ShouldRemoveTheMiddleOfThree)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(6u);
			list1.Append(1u);

			list1.Extract(6u);

			Assert::AreEqual(static_cast<size_t>(2), list1.Size());

			size_t counter = 0u;
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(Extract_ShouldRemove3CopiesOfData6)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(6u);
			list1.Append(1u);
			list1.Append(2u);
			list1.Append(3u);
			list1.Append(4u);

			list1.Extract(6u);

			Assert::AreEqual(static_cast<size_t>(5), list1.Size());

			size_t counter = 0u;
			for (auto node = list1.Head(); node != nullptr; node = node->Next())
				Assert::AreEqual(counter++, node->Value());
		}

		TEST_METHOD(Extract_ShouldRemoveBackNodeOfTwo)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(0u);
			list1.Append(6u);

			list1.Extract(6u);

			Assert::AreEqual(static_cast<size_t>(1), list1.Size());

			size_t counter = 0u;

			Assert::AreEqual(counter, list1.Last());
			Assert::AreEqual(counter, list1.First());
		}

		TEST_METHOD(Extract_ShouldRemoveFrontNodeOfTwo)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;
			list1.Append(6u);
			list1.Append(0u);

			list1.Extract(6u);

			Assert::AreEqual(static_cast<size_t>(1), list1.Size());

			size_t counter = 0u;

				Assert::AreEqual(counter, list1.Last());
				Assert::AreEqual(counter, list1.First());
		}

		TEST_METHOD(LastAndFrist_ShouldShowSameElementWithOneNode)
		{
			const CrtCheckMemory check;

			LinkedList<size_t> list1;

			list1.Append(0u);

			Assert::AreEqual(static_cast<size_t>(1), list1.Size());

			size_t counter = 0u;

			Assert::AreEqual(counter, list1.Last());
			Assert::AreEqual(counter, list1.First());
		}

		TEST_METHOD(LinkedListDefaultConstructor)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> list;

				Assert::IsTrue(list.Empty());
				Assert::IsNull(list.Head());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;
				aList.Append(5);

				LinkedList<int> bList(aList);

				Assert::IsFalse(bList.Empty());
				Assert::AreEqual(5, bList.First());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListAssignmentOperator)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;
				LinkedList<size_t> bList;

				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };

				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				bList = aList;

				i = 0;
				for (ListNode<size_t>* list_node = bList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListAccessors)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.Head()->Value());
				Assert::AreEqual(45, aList.Tail()->Value());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListAppend)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				i = 0;
				for (ListNode<size_t>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListFirstAndLast)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.First());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListPrepend)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Prepend(values[i]);
				}

				i = 5;
				for (ListNode<size_t>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[--i], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListPurge)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<size_t> aList;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (size_t i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				aList.Clear();

				Assert::IsNull(aList.Head());
				Assert::IsNull(aList.Tail());
				Assert::IsTrue(aList.Empty());

			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListBefore)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[4]);
				for (i = 3; i >= 0; --i)
				{
					aList.InsertBefore(values[i], values[i + 1]);
				}

				i = 0;
				for (ListNode<int>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListInsertAfter)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[0]);
				for (i = 1; i < 5; ++i)
				{
					aList.InsertAfter(values[i], values[i - 1]);
				}

				i = 0;
				for (ListNode<int>* list_node = aList.Head(); list_node != nullptr; list_node = list_node->Next())
				{
					Assert::AreEqual(values[i++], list_node->Value());
				}
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(LinkedListExtract)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> list;

				list.Append(5);
				list.Extract(5);

				Assert::IsTrue(list.Empty());
				Assert::IsNull(list.Head());

				list.Append(5);
				list.Append(10);
				list.Append(15);

				list.Extract(10);

				Assert::AreEqual(5, list.First());
				Assert::AreEqual(15, list.Last());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(Extract_StressTestShouldWork)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> list;

				list.Append(5);
				list.Extract(5);

				Assert::IsTrue(list.Empty());
				Assert::IsNull(list.Head());

				list.Append(5);
				list.Append(10);
				list.Append(15);

				list.Extract(10);

				Assert::AreEqual(5, list.First());
				Assert::AreEqual(15, list.Last());

				list.Prepend(8);
				list.Append(9);

	
				Assert::AreEqual(8, list.First());
				Assert::AreEqual(9, list.Last());

				list.Extract(15);

				Assert::AreEqual(8, list.First());
				Assert::AreEqual(9, list.Last());

				list.Extract(8);

				Assert::AreEqual(5, list.First());
				Assert::AreEqual(9, list.Last());
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}

		TEST_METHOD(BoolOperatorEqualTest_ShouldPass)
		{
			CrtCheckMemory check;

			LinkedList<int> aList;
			LinkedList<int> bList;

			int values[] = { 5, 15, 25, 35, 45 };
			for (int i = 0; i < 5; ++i)
			{
				aList.Append(values[i]);
				bList.Append(values[i]);
			}


			Assert::IsTrue(aList == bList);
		}

		TEST_METHOD(BoolOperatorEqualTest_ShouldFailWithDIfferentData)
		{
			CrtCheckMemory check;

			LinkedList<int> aList;
			LinkedList<int> bList;

			int values[] = { 5, 15, 25, 35, 45 };
			for (int i = 0; i < 5; ++i)
			{
				aList.Append(values[i]);
				bList.Append(values[1 + i]);
			}

			Assert::IsFalse(aList == bList);
			
		}

		TEST_METHOD(BoolOperatorEqualTest_ShouldFailWithDIfferentsizes)
		{
			CrtCheckMemory check;

			LinkedList<int> aList;
			LinkedList<int> bList;

			int values[] = { 5, 15, 25, 35, 45 };
			for (int i = 0; i < 5; ++i)
			{
				aList.Append(values[i]);
			}

			for (int i = 0; i < 4; ++i)
			{
				bList.Append(values[i]);
			}

			Assert::IsFalse(aList == bList);

		}

		TEST_METHOD(BoolOperatorEqualTest_ShouldPassBoolWithDifferntConstructionMEthods)
		{
			CrtCheckMemory check;
			try
			{
				LinkedList<int> aList;
				LinkedList<int> bList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				bList.Append(5);
				bList.Append(15);
				bList.Append(25);
				bList.Append(35);
				bList.Append(45);


				Assert::AreEqual(5, aList.First());
				Assert::AreEqual(5, bList.First());

				Assert::AreEqual(45, aList.Last());
				Assert::AreEqual(45, bList.Last());

				Assert::IsTrue(aList == bList);
			}
			catch (AdtException AdtException)
			{
				Assert::Fail(AdtException.Message());
			}
		}
	};
}
