#include "pch.h"
#include "CppUnitTest.h"
#include "adt_exception.hpp"
#include "crt_check_memory.hpp"
#include "hash_map.hpp"
#include <string>

using std::string;
using std::to_string;
using namespace  data_structures;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_tests
{
	TEST_CLASS(HashMapTests)
	{
	public:
		TEST_METHOD(TraverseTest_IntTest)
		{
			const int kTableSize = 10;
			const auto hash_function = [&](int key) -> int
			{
				return key % kTableSize;
			};
			auto hash_map = HashMap<int, int>(kTableSize, hash_function);
			int data[] = {10, 20, 30, 40, 50, 5, 15, 25, 35, 45};

			for (auto& i : data)
				hash_map.Insert(i, i);


			vector<int> visited;
			const auto visit = [&visited](const int& key, const int& value) -> void
			{
				visited.push_back(value);
			};

			hash_map.Traverse(visit);

			for (auto i = 0; i < kTableSize; ++i)
			{
				Assert::AreEqual(data[i], visited[i]);
			}
		}

		TEST_METHOD(TraverseTest_StringTest)
		{
			const int kTableSize = 10;
			auto hash_function = [&](string key) ->int
			{
				auto sum = 0;
				for (auto &ch : key)
				{
					sum += ch;
				}
				return sum % kTableSize;
			};
			auto hash_map = HashMap<string, string>(10, hash_function);
			int data[] = { 40, 50, 15, 5, 25, 35, 45, 10, 20, 30 };

			for (auto& i : data)
				hash_map.Insert(to_string(i), to_string(i));


			vector<string> visited;
			const auto visit = [&visited](const string& key, const string& value) -> void
			{
				visited.push_back(value);
			};

			hash_map.Traverse(visit);

			for (auto i = 0; i < 10; ++i)
			{
				Assert::AreEqual(to_string(data[i]), visited[i]);
			}
		}

		TEST_METHOD(TraverseTest_IntTestWillHaveSameHashingValues)
		{
			const int kTableSize = 10;
			const auto hash_function = [&](int key) -> int
			{
				return key % kTableSize;
			};
			auto hash_map = HashMap<int, int>(kTableSize, hash_function);
			int data[] = { 10, 20, 30, 40, 50, 5, 15, 25, 35, 45 };

			for (auto& i : data)
				hash_map.Insert(i, i);


			vector<int> visited;
			const auto visit = [&visited](const int& key, const int& value) -> void
			{
				visited.push_back(value);
			};

			hash_map.Traverse(visit);

			for (auto i = 0; i < kTableSize; ++i)
			{
				Assert::AreEqual(data[i], visited[i]);
			}
			size_t current_size = 10;
			Assert::AreEqual(hash_map.Count(), current_size);
		}

		TEST_METHOD(HashMapTest_OperatorBracketsShouldWork)
		{
			const int kTableSize = 10;
			const auto hash_function = [&](int key) -> int
			{
				return key % kTableSize;
			};
			auto hash_map = HashMap<int, int>(kTableSize, hash_function);
			int data[] = { 10, 20, 30, 40, 50, 5, 15, 25, 35, 45 };

			for (auto& i : data)
				hash_map.Insert(i, i);

			Assert::AreEqual(hash_map[5], 5);
			Assert::AreEqual(hash_map[25], 25);
			Assert::AreEqual(hash_map[20], 20);

			const auto should_throw = [&]
			{
				hash_map[3];
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(HashMapTest_RemoveShouldWork)
		{
			const int kTableSize = 10;
			const auto hash_function = [&](int key) -> int
			{
				return key % kTableSize;
			};
			auto hash_map = HashMap<int, int>(kTableSize, hash_function);
			int data[] = { 10, 20, 30, 40, 50, 5, 15, 25, 35, 45 };

			for (auto& i : data)
				hash_map.Insert(i, i);

			Assert::AreEqual(hash_map[5], 5);

			hash_map.Remove(5);

			const auto should_throw = [&]
			{
				hash_map[5];
			};

			Assert::ExpectException<AdtException>(should_throw);
		}

		TEST_METHOD(HashMapTest_ContainsShouldWork)
		{
			const int kTableSize = 10;
			const auto hash_function = [&](int key) -> int
			{
				return key % kTableSize;
			};
			auto hash_map = HashMap<int, int>(kTableSize, hash_function);
			int data[] = { 10, 20, 30, 40, 50, 5, 15, 25, 35, 45 };

			for (auto& i : data)
				hash_map.Insert(i, i);

			Assert::AreEqual(hash_map[5], 5);
			Assert::IsTrue(hash_map.Contains(5));

			hash_map.Remove(5);

			const auto should_throw = [&]
			{
				hash_map[5];
			};

			Assert::ExpectException<AdtException>(should_throw);
			Assert::IsFalse(hash_map.Contains(5));
		}

		TEST_METHOD(TraverseTest_StringOperatorTest)
		{
			const int kTableSize = 5;
			auto hash_function = [&](string key) ->int
			{
				auto sum = 0;
				auto sum2 = 0;
				for (auto& ch : key)
				{
					sum2 += ch;
					sum = (sum2 << 4) ^ ch;
				}
				return sum % kTableSize;
			};
			auto hash_map = HashMap<string, string>(5, hash_function);

			hash_map.Insert("new", "data");
			hash_map.Insert("new", "hair");
			hash_map.Insert("new", "car");
			hash_map.Insert("new", "outlook");
			hash_map.Insert("new", "socks");
			hash_map.Insert("new", "comprehension");
			hash_map.Insert("old", "thing");
			hash_map.Insert("old", "man");
			hash_map.Insert("old", "stuff");
			hash_map.Insert("old", "pizza");
			hash_map.Insert("old", "clothes");
			hash_map.Insert("old", "cheese");
			hash_map.Insert("Derek", "I_haz_bucket");
			hash_map.Insert("Derek", "my_Bucket");
			hash_map.Insert("Graham", "I_want_bucket");

			Assert::IsTrue(hash_map.Contains("old"));

			const size_t current_size_check = 15; 
			Assert::AreEqual(hash_map.Count(), current_size_check);
		}

		TEST_METHOD(lyricsExample)
		{
			vector<pair<string, vector<int>>> lyrics;
			lyrics.push_back(pair<string, vector<int>>("Happy", {1, 5}));
			lyrics.push_back(pair<string, vector<int>>("Birthday", { 2, 6 }));
			lyrics.push_back(pair<string, vector<int>>("to", { 3, 7 }));
			lyrics.push_back(pair<string, vector<int>>("you", { -4, -8 }));

			auto hash_function = [&](string key) ->int
			{
				auto sum = 0;
				auto sum2 = 0;
				for (auto& ch : key)
				{
					sum2 += ch;
					sum = (sum2 << 1) ^ ch;
				}
				return sum % 5;
			};
			
			auto hash_map = HashMap<string, vector<int>>(5, hash_function);

			for (auto &lyric : lyrics)
			{
				for (auto &line_number : lyric.second)
				{
					if (!hash_map.Contains(lyric.first))
					{
						hash_map.Insert(lyric.first, {line_number} );
					}
					else
					{
						hash_map[lyric.first].push_back(line_number);
					}
				}
			}


		}
	};
} 