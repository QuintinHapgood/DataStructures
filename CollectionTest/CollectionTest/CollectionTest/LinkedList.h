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

	Node *_first;
	Node *_last;

private:

};

template <typename T>
class LinkedList<T>::Iterator
{
public:

	Iterator();
	Iterator(Node *pos);

	Iterator &operator ++ ();		 //prefix ++
	Iterator &operator ++ (T);		 // postfix ++

	Iterator &operator -- ();		 //prefix --
	Iterator &operator -- (T);		 // postfix --

	int &operator *();			 // dereference operator

	bool operator == (const Iterator &rhs)const;
	bool operator != (const Iterator &rhs) const;


protected:
private:

	Node *node;
};

template <typename T>
struct LinkedList<T>::Node
{
	T data;
	Node *next;
	Node *prev;

	Node();
	Node(T d, Node *n, Node *p);
	~Node();
};

#pragma region Iterators
template <typename T>
LinkedList<T>::Iterator::Iterator() : node(nullptr)
{

}

template <typename T>
LinkedList<T>::Iterator::Iterator(LinkedList::Node *pos) : node(pos)
{

}

template <typename T>
LinkedList<T>::Iterator &LinkedList<T>::Iterator::operator ++ ()
{
	node = node->next;
	return *this;

}

template <typename T>
LinkedList<T>::Iterator &LinkedList<T>::Iterator::operator ++ (T)
{
	node = node->next;
	return *this;
}

template <typename T>
LinkedList<T>::Iterator &LinkedList<T>::Iterator::operator -- ()
{
	node = node->prev;
	return *this;

}

template <typename T>
LinkedList<T>::Iterator &LinkedList<T>::Iterator::operator -- (T)
{
	node = node->prev;
	return *this;

}

template <typename T>
int &LinkedList<T>::Iterator::operator *()
{
	return node->data;
}

template <typename T>
bool LinkedList<T>::Iterator::operator == (const Iterator &rhs)const
{
	return node == rhs.node;
}

template <typename T>
bool LinkedList<T>::Iterator::operator != (const Iterator &rhs) const
{
	return node != rhs.node;
}

template <typename T>
LinkedList<T>::Iterator LinkedList<T>::Begin()
{
	return Iterator(_first);

}

template <typename T>
LinkedList<T>::Iterator LinkedList<T>::End()
{
	return Iterator(nullptr);
}

template <typename T>
void LinkedList<T>::PopFront()
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


template <typename T>
void LinkedList<T>::PopBack()
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
template <typename T>
LinkedList<T>::Node *LinkedList<T>::FirstNode()
{
	return _first;
}

template <typename T>
LinkedList<T>::Node *LinkedList<T>::LastNode()
{
	return _last;
}

template<typename T>
LinkedList<T>::Node::Node() : next(nullptr), prev(nullptr)
{

}

template<typename T>
LinkedList<T>::Node::Node(T d, Node *n, Node *p) : data(d), next(n), prev(p)
{

}


template<typename T>
LinkedList<T>::Node::~Node()
{

}
#pragma endregion

#pragma region LinkedList

template<typename T>
LinkedList<T>::LinkedList() : _first(nullptr), _last(nullptr)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
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

template <typename T>
size_t LinkedList<T>::Size()
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
