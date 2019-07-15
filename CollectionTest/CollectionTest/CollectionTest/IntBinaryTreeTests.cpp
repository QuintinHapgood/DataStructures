#include "stdafx.h"
#include "CppUnitTest.h"
#include "IntBinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace Collections1
{
	TEST_CLASS(IntBinaryTreeTests)
	{
	public:
		TEST_METHOD(IntBinaryTreeTest)
		{
			IntBinaryTree<int> tree;
			tree.Add(20);
			tree.Add(10);
			tree.Add(30);

			Assert::IsTrue(tree.ContainsValue(10), L"Should contain value");
			Assert::IsTrue(tree.ContainsValue(20), L"Should contain value");
			Assert::IsTrue(tree.ContainsValue(30), L"Should contain value");
			size_t wantedSize = 3u;
			Assert::AreEqual(3u, tree.Count(), L"should have 3 items");

			tree.Remove(20);
			wantedSize = 2u;
			Assert::AreEqual(2u, tree.Count(), L"Should have 2 items");
			Assert::IsFalse(tree.ContainsValue(20), L"Should not contain value");
		}


	};
}
