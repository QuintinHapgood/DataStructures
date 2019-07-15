#pragma once

class LinkedList
{
public:

	struct Node;
	Node *FirstNode();
	Node *LastNode();

	class Iterator;
	Iterator Begin();
	Iterator End();

	void PushBack(int value);
	void PushFront(int value);

	int Size();

	void Clear();



	LinkedList();
	~LinkedList();


protected:

	Node * _first;
	Node *_last;

private:
};

struct LinkedList::Node
{
public:

	Iterator();
	Iterator(Node *pos);

	Iterator &operator ++();
	Iterator &operator ++(int);

	Iterator &operator --();
	Iterator &operator --(int);

	int &operator * ();

	bool operator == (const Iterator &rhs)const;
	bool operator != (const Iterator &rhs)const;

protected:
private:

	Node * node;
};

#pragma region Iterator
	
LinkedList<int>::Iterator::Iterator() : node(nullptr)
{

}


LinkedList<int>::Iterator::Iterator(LinkedList::Node *pos) : node(pos)
{

}

LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator ++ ()
{
	node = node->next;
	return *this;

}

LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator ++ (int)
{
	node = node->next;
	return *this;
}

LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator -- ()
{
	node = node->prev;
	return *this;

}

LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator -- (int)
{
	node = node->prev;
	return *this;
}

bool LinkedList<int>::Iterator::operator == (const Iterator &rhs)const
{
	return node == rhs.node;
}

bool LinkedList<int>::Iterator::operator != (const Iterator &rhs) const
{
	return node != rhs.node;
}

#pragma endregion

#pragma region Node
LinkedList<int>::Node::Node() : next(nullptr), prev(nullptr)
{

}

LinkedList<int>::Node::Node(int d, Node *n, Node *p) : data(d), next(n), prev(p)
{

}

LinkedList<int>::Node::~Node()
{

}

#pragma endregion

#pragma region Method

LinkedList<int>::LinkedList() : m_first(nullptr), m_last(nullptr)
{

}

LinkedList<int>::~LinkedList()
{
	clear();
}
void LinkedList<int>::PushBack(int value)
{
	Node *n = new Node();
	n->data = value;

	if (m_last == nullptr)
	{
		m_first = n;
		m_last = n;
	}
	else
	{
		m_last->next = n;
		n->prev = m_last;
		m_last = n;
	}
}
void LinkedList<int>::PushFront(int value)
{
	Node *n = new Node();
	n->data = value;

	if (m_first == nullptr)
	{
		m_first = n;
		m_last = n;
	}
	else
	{
		n->next = m_first;
		m_first = n;
	}
}

size_t LinkedList<int>::Size()
{

	if (m_first == nullptr)
		return 0;

	size_t count = 0;
	Node *current = m_first;
	while (current != nullptr)
	{
		count += 1;
		current = current->next;
	}

	return count;

}


LinkedList<int>::Node *LinkedList<int>::FirstNode()
{
	return m_first;
}
LinkedList<int>::Node *LinkedList<int>::LastNode()
{
	return m_last;
}

LinkedList<int>::Iterator LinkedList<int>::Begin()
{
	return Iterator(m_first);

}
LinkedList<int>::Iterator LinkedList<int>::End()
{
	return Iterator(nullptr);
}

template<typename TValue>
void LinkedList<TValue>::clear()
{
	Node *current = m_first;
	while (current != nullptr)
	{
		Node *n = current;
		current = current->next;
		delete n;
	}

	m_first = nullptr;
	m_last = nullptr;
}


#pragma endregion

