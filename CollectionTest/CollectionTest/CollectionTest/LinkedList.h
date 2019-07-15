#pragma once
template<typename T>
class LinkedList
{
public:

	class Iterator;

	Iterator Begin();
	Iterator End();


	struct Node;

	Node *FirstNode();
	Node *LastNode();


	LinkedList();
	~LinkedList();


	void PushBack(T value);
	void PushFront(T value);
	void PopBack();
	void PopFront();

	size_t Size();
	void clear();

protected:

	Node * _first;
	Node * _last;

private:

};

template <typename T>
class LinkedList<T>::Iterator
{
public:

	Iterator();
	Iterator(Node *pos);

	Iterator &operator ++ ();		 //prefix ++
	Iterator &operator ++ (int);	 // postfix ++

	Iterator &operator -- ();		 //prefix --
	Iterator &operator -- (int);	 // postfix --

	int & operator * ();			 // dereference operator

	bool operator == (const Iterator &rhs)const;
	bool operator != (const Iterator &rhs) const;


protected:
private:

	Node * node;
};

template <typename T>
struct LinkedList<T>::Node
{
	int data;
	Node *next;
	Node *prev;

	Node();
	Node(int d, Node *n, Node *p);
	~Node();
};

#pragma region Iterators
//template<Iterator::Iterator() : node(nullptr)>
LinkedList<int>::Iterator::Iterator() : node(nullptr)
{

}

//template<Iterator(LinkedList::Node *pos) : node(pos)>
LinkedList<int>::Iterator::Iterator(LinkedList::Node *pos) : node(pos)
{

}

//template<Iterator::operator ++ ()>
LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator ++ ()
{
	node = node->next;
	return *this;

}

//template<Iterator::operator ++ (int)>
LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator ++ (int)
{
	node = node->next;
	return *this;
}

//template<Iterator::operator -- ()>
LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator -- ()
{
	node = node->prev;
	return *this;

}

//template<Iterator::operator -- (int)>
LinkedList<int>::Iterator &LinkedList<int>::Iterator::operator -- (int)
{
	node = node->prev;
	return *this;

}

//template<Iterator::operator * ()>
int & LinkedList<int>::Iterator::operator * ()
{
	return node->data;
}

//template<Iterator::operator == (const Iterator &rhs)const>
bool LinkedList<int>::Iterator::operator == (const Iterator &rhs)const
{
	return node == rhs.node;
}

//template<Iterator::operator != (const Iterator &rhs) const>
bool LinkedList<int>::Iterator::operator != (const Iterator &rhs) const
{
	return node != rhs.node;
}

//template<LinkedList::Begin()>
LinkedList<int>::Iterator LinkedList<int>::Begin()
{
	return Iterator(_first);

}

//template<LinkedList::End()>
LinkedList<int>::Iterator LinkedList<int>::End()
{
	return Iterator(nullptr);
}

//template<LinkedList<int>::PopFront()>
void LinkedList<int>::PopFront()
{
	if (_last != _first)
	{
		Node *it = _first;
		_first = _first->next;
		delete it;
	}
	else
	{
		_last = nullptr;
		_first = nullptr;
	}
}


//template<LinkedList::PopBack()>
void LinkedList<int>::PopBack()
{
	if (_last != _first)
	{
		Node *it = _first;
		while (it->next->next != nullptr)
		{
			it = it->next;
		}
		_last = it;
		delete _last->next;
		_last->next = nullptr;
	}
	else
	{
		_last = nullptr;
		_first = nullptr;
	}
}
#pragma endregion

#pragma region Nodes
//template<LinkedList::FirstNode()>
//template<typename BiTree>
LinkedList<int>::Node *LinkedList<int>::FirstNode()
{
	return _first;
}

//template<LinkedList::LastNode()>
//template<typename BiTree>
LinkedList<int>::Node *LinkedList<int>::LastNode()
{
	return _last;
}

//template<Node::Node() : next(nullptr), prev(nullptr)>
template<typename T>
LinkedList<T>::Node::Node() : next(nullptr), prev(nullptr)
{

}

//template<Node::Node(int d, Node *n, Node *p) : data(d), next(n), prev(p)>
template<typename T>
LinkedList<T>::Node::Node(int d, Node *n, Node *p) : data(d), next(n), prev(p)
{

}

//template<Node::~Node()>
template<typename T>
LinkedList<T>::Node::~Node()
{

}
#pragma endregion

#pragma region LinkedList

//template <LinkedList::LinkedList>
template<typename T>
LinkedList<T>::LinkedList() : _first(nullptr), _last(nullptr)
{

}

//template <LinkedList::~LinkedList>
LinkedList<int>::~LinkedList()
{
	clear();
}

template<typename T>
void LinkedList<T>::PushBack(T value)
{
	Node *n = new Node();
	n->data = value;

	if (_last == nullptr)
	{
		_first = n;
		_last = n;
	}
	else
	{
		_last->next = n;
		n->prev = _last;
		_last = n;
	}
}

template<typename T>
void LinkedList<T>::PushFront(T value)
{
	Node *n = new Node();
	n->data = value;

	if (_first == nullptr)
	{
		_first = n;
		_last = n;
	}
	else
	{
		n->next = _first;
		_first = n;
	}
}

//template<LinkedList::Size>
size_t LinkedList<int>::Size()
{

	if (_first == nullptr)
		return 0;

	int count = 0;
	Node *current = _first;
	while (current != nullptr)
	{
		count += 1;
		current = current->next;
	}

	return count;

}

//template<LinkedList::clear>
template <typename T>
void LinkedList<T>::clear()
{
	Node *current = _first;
	while (current != nullptr)
	{
		Node *n = current;
		current = current->next;
		delete n;
	}

	_first = nullptr;
	_last = nullptr;
}
#pragma endregion
