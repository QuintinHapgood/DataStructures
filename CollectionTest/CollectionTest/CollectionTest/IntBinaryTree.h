#pragma once
#include <functional>
#include <iostream>
#include <list>

template<typename T>
class IntBinaryTree
{
public:
	struct Node
	{
		int value;
		Node *left = nullptr;
		Node *right = nullptr;
	};

	bool Add(const T &value);
	bool Remove(const T &value);

	size_t Count();

	bool ContainsValue(const T &value);

	void ForEach(std::function<bool(const T &)> fn);

protected:

private:
	bool Add(Node *parent, Node *newNode);
	bool Add(Node *del);

	bool Remove(Node * parent, Node *newNode);
	void RecursiveDFS(Node *parent, std::function<bool(const T&)> fn);

	Node * root = nullptr;
};

template<typename T>
bool IntBinaryTree<T>::Add(const T &value)
{
	Node *del = new Node();
	del->value = value;

	if (root == nullptr)
		root = del;
	else
		Add(root, del);

	return false;
}

template<typename T>
bool IntBinaryTree<T>::Add(Node *del)
{
	if (root == nullptr)
	{
		root = del;
		return true;
	}
	else
	{
		return Add(root, del);
	}
}

template<typename T>
bool IntBinaryTree<T>::Remove(const T & value)
{

	Node *del = new Node();
	del->value = value;

	if (root->value == del->value)
	{
		Node *tempNodeLeft;
		Node *tempNodeRight;


		if (root->left != nullptr)
			tempNodeLeft = root->left;

		if (root->right != nullptr)
			tempNodeRight = root->right;

		root = nullptr;
		
		delete root;

		if (tempNodeLeft != nullptr)
			Add(tempNodeLeft);

		if (tempNodeRight != nullptr)
			Add(tempNodeRight);
	}
	else
		Remove(root, del);

	//move leftmost up

	//reaattached right side

	return false;
}

template<typename T>
bool IntBinaryTree<T>::Remove(Node * parent, Node *newNode)
{
	Node *tempNodeLeftLeft;
	Node *tempNodeLeftRight;
	Node *tempNodeRightLeft;
	Node *tempNodeRightRight;

	if (newNode->value < parent->value)
	{
		if (parent->left->value == newNode->value)
		{
			if (parent->left->left != nullptr)
				tempNodeLeftLeft = parent->left->left;

			if (parent->left->right != nullptr)
				tempNodeLeftRight = parent->left->right;

			parent->left = nullptr;
			delete parent->left;

			if (tempNodeLeftLeft != nullptr)
				Add(tempNodeLeftLeft);

			if (tempNodeLeftRight != nullptr)
				Add(tempNodeLeftRight);

		}
		else
		{
			return Remove(parent->left, newNode);
		}
	}
	else if (newNode->value > parent->value)
	{
		if (parent->right->value == newNode->value)
		{
			if (parent->right->left != nullptr)
				tempNodeRightLeft = parent->right->left;

			if (parent->right->right != nullptr)
				tempNodeRightRight = parent->right->right;

			parent->right = nullptr;
			delete parent->right;

			if (tempNodeRightLeft != nullptr)
				Add(tempNodeRightLeft);

			if (tempNodeRightRight != nullptr)
				Add(tempNodeRightRight);
		}
		else
		{
			return Remove(parent->right, newNode);
		}
	}
	else
	{
		delete newNode;
		return false;
	}
}

template<typename T>
size_t IntBinaryTree<T>::Count()
{
	int count = 0;
	ForEach([&](const int &value) {
		count += 1;
		return true;
	});

	return count;
}

template<typename T>
bool IntBinaryTree<T>::ContainsValue(const T & value)
{
	bool containsValue = false;
	ForEach([&](const int &nodeValue)
	{
		if (nodeValue == value)
		{
			containsValue = true;
			return false;
		}
		return true;
	});
	return containsValue;
}


template<typename T>
bool IntBinaryTree<T>::Add(Node *parent, Node *newNode)
{
	if (newNode->value < parent->value)
	{
		if (parent->left == nullptr)
			parent->left = newNode;
		else
			return Add(parent->left, newNode);

	}
	else if (newNode->value > parent->value)
	{
		if (parent->right == nullptr)
			parent->right = newNode;
		else
			return Add(parent->right, newNode);
	}
	else
	{
		delete newNode;
		return false;
	}
}

template<typename T>
void IntBinaryTree<T>::RecursiveDFS(Node * parent, std::function<bool(const T&)> fn)
{
	if (parent == nullptr)
		return;

	if (fn(parent->value))
	{
		RecursiveDFS(parent->left, fn);
		RecursiveDFS(parent->right, fn);
	}
}

template<typename T>
void IntBinaryTree<T>::ForEach(std::function<bool(const T&)> fn)
{
	RecursiveDFS(root, fn);
}
