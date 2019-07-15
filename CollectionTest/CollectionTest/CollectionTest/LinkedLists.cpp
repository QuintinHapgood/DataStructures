#include "CppUnitTest.h"
#include "LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TemplatesAssesment
{
	TEST_CLASS(LinkedListTests)
	{
	public:

		TEST_METHOD(TestPushBack)
		{

			LinkedList<int> list;
			list.PushBack(10);
			list.PushBack(20);

			size_t expectedSize = 2;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 2 items");

		}

		TEST_METHOD(ListLooping)
		{
			int values[5] = { 10, 20, 30, 40, 50 };
			int *pValuesBegin = &values[0];
			int *pValuesEnd = &values[5];

			LinkedList<int> list;
			for (int *iter = pValuesBegin; iter != pValuesEnd; iter++)
			{
				list.PushBack(*iter);
				Assert::AreEqual(*iter, list.LastNode()->data, L"data value should be same");
			}
			int *valIter = pValuesBegin;
			auto nodeIter = list.FirstNode();

			while (nodeIter != nullptr)
			{
				Assert::AreEqual(*valIter, nodeIter->data, L"data value should be same");

				nodeIter = nodeIter->next;
				valIter++;
			}
		}

		TEST_METHOD(ListLoopingIterator)
		{
			int values[5] = { 10, 20, 30, 40, 50 };
			int *pValuesBegin = &values[0];
			int *pValuesEnd = &values[5];

			LinkedList<int> list;
			for (int *iter = pValuesBegin; iter != pValuesEnd; iter++)
			{
				list.PushBack(*iter);
				Assert::AreEqual(*iter, list.LastNode()->data, L"data value should be same");
			}

			int *valIter = pValuesBegin;
			for (auto iter = list.Begin(); iter != list.End(); iter++)
			{
				Assert::AreEqual(*valIter, *iter, L"data value should be the same");
				valIter++;
			}
		}
		TEST_METHOD(Pushfront)
		{

			LinkedList<int> list;
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 0 items");
			list.PushFront(10);

			list.PushFront(20);
			list.PushFront(30);
			list.PushFront(40);
			list.PushFront(50);
			list.PushFront(60);

			Assert::AreEqual(list.LastNode()->data, 10, L"Should be equal");

			Assert::AreEqual(list.FirstNode()->data, 60, L"Should be equal");

			expectedSize = 6;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 6 items");

		}
		TEST_METHOD(PopBack)
		{

			LinkedList<int> list;
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 0 items");
			list.PushFront(10);
			expectedSize = 1;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 1 items");
			list.PushFront(20);
			expectedSize = 2;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 2 items");
			list.PopBack();
			expectedSize = 1;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 1 items");

		}
		TEST_METHOD(PopFront)
		{

			LinkedList<int> list;
			size_t expectedSize = 0;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 0 items");
			list.PushFront(10);
			expectedSize = 1;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 1 items");
			list.PushFront(20);
			expectedSize = 2;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 2 items");
			list.PopFront();
			expectedSize = 1;
			Assert::AreEqual(expectedSize, list.Size(), L"List should have 1 items");

		}
	};

}
