#include "CppUnitTest.h"
#include "DIntArr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CollectionTest
{
	TEST_CLASS(DIntArrTest)
	{
	public:

		TEST_METHOD(CheckSizeAddValueAdding)
		{

			int firstValue = 10;
			int secondValue = 20;


			DIntArr arr;
			arr.PushBack(firstValue);
			arr.PushBack(secondValue);

			size_t expectedSize = 2;
			Assert::AreEqual(expectedSize, arr.Size(), L"Should be 2 items in collection");

			Assert::AreEqual(firstValue, arr[0], L"First item should be 10");
			Assert::AreEqual(secondValue, arr[1], L"second itme should be 20");

		}


		TEST_METHOD(CheckSizeAndCapacityGrowCorrectly)
		{
			//try
			//{
			const int NUM_VALUES = 4;
			int values[NUM_VALUES] = { 1, 2, 3, 4 };




			DIntArr arr;
			for (int i = 0; i < NUM_VALUES; i++)
			{
				arr.PushBack(values[i]);
				Assert::IsTrue(arr.Capacity() >= arr.Size());
			}

			size_t expectedSize = NUM_VALUES;
			Assert::AreEqual(expectedSize, arr.Size(), L"Should be 2 items in collection");

			for (int i = 0; i < NUM_VALUES; i++)
				Assert::AreEqual(values[i], arr[i], L"First item should be 10");




		}
		/*
		catch(std::exception &e)
		{
			std::wstring s(&e.what()[0], &e.what()[strlen(e.what())]);
			Assert::Fail(s.c_str());
		}
		*/
		TEST_METHOD(CheckmodifyingValuesInCollection)
		{
			const int NUM_VALUES = 4;
			int values[NUM_VALUES] = { 1, 2, 3, 4 };




			DIntArr arr;
			for (int i = 0; i < NUM_VALUES; i++)
				arr.PushBack(values[i]);
				
			

			for (int i = 0; i < NUM_VALUES; i++)
			{
			int newValue = i * 10;
			arr[i] = newValue;
			Assert::AreEqual(newValue, arr[i], L"Values should match");
			}

		}

		TEST_METHOD(CheckSizeAndPushFront)
		{
			const int NUM_VALUES = 4;
			int values[NUM_VALUES] = { 1, 2, 3, 4 };




			DIntArr arr;
			for (int i = 0; i < NUM_VALUES; i++)
			{
				arr.PushFront(values[i]);
				//Assert::AreEqual(newValue, arr[i], L"Values should match");
			}

		}

		TEST_METHOD(CheckIteratorsIterate)
		{
			const int NUM_VALUES = 4;
			int values[NUM_VALUES] = { 1, 2, 3, 4 };

		
			DIntArr arr;
				for (int i = 0; i < NUM_VALUES; i++)
				{
					arr.PushBack(values[i]);
				}
	
			Assert::AreEqual(values[0], *arr.Begin(), L"Value should be same");
			Assert::AreEqual(values[3], *(arr.End()--), L"Value should be same");

			int i = 0;
			for (auto iter = arr.Begin(); iter != arr.End(); iter++)
			{
				Assert::AreEqual(values[i], *iter, L"Value should be same");
				i++;
			}
		}
	};

	

}