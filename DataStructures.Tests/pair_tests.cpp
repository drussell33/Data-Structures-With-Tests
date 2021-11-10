 #include "pch.h"
#include "CppUnitTest.h"
#include "pair.hpp"
#include <string>
#include "crt_check_memory.hpp"

using std::string;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace data_structures;

namespace data_structures_tests
{
	TEST_CLASS(PairTests)
	{
	public:
		Pair<string, string> GetPair()
		{
			Pair < string, string > the_pair("1", "2");

			return the_pair;
		}

		TEST_METHOD(ParameterizedCtorTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");
		}

		TEST_METHOD(GetFirstTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");

			Assert::AreEqual(std::string("key"), pair1.First());
		}

		TEST_METHOD(GetSecondTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");

			Assert::AreEqual(std::string("value"), pair1.Second());

		}

		TEST_METHOD(SetFirstTest) 
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");

			pair1.First("new");

			Assert::AreEqual(std::string("new"), pair1.First());

		}

		TEST_METHOD(SetSecondTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");

			pair1.Second("new");

			Assert::AreEqual(std::string("new"), pair1.Second());

		}

		TEST_METHOD(CopyConstructorTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");

		}

		TEST_METHOD(AssignmentOperatorTest)
		{
			CrtCheckMemory check_memory;
			Pair<string, string> pair1("key", "value");
			
			Pair<string, string> pair2 = GetPair();

			pair1 = pair2;

			Assert::AreEqual(std::string("1"), pair1.First());
		}

		TEST_METHOD(MoveConstructorTest)
		{
			CrtCheckMemory check_memory;

			Pair<string, string> pair1 = GetPair();

			Assert::AreEqual(std::string("1"), pair1.First());

		}
	};
}
