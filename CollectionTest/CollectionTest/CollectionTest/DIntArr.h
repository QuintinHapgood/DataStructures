#pragma once

class DIntArr
{
public:

	DIntArr();
	~DIntArr();

	bool TryResize(size_t newSize);
	void PushBack(int value);
	void PushFront(int value);


	size_t Capacity();
	size_t Size();

	int & operator [] (size_t index);

	class Iterator
	{
	public:
		Iterator();
		Iterator(int *pos);

		Iterator &operator ++ ();		//Prefix
		Iterator &operator ++ (int);	//Postfix

		Iterator &operator -- ();		//Prefix
		Iterator &operator -- (int);	//Postfix

		int & operator * (); //deference operator

		bool operator == (const Iterator &rhs) const;
		bool operator != (const Iterator &rhs) const;



	protected:
	private:
		int *current;

	};

	Iterator Begin();
	Iterator End();


protected:
private:

	size_t m_capacity;
	size_t m_size;

	int *m_data;

};



DIntArr::DIntArr()
{
	m_size = 0;
	m_capacity = 2;
	m_data = new int[m_capacity];

};

DIntArr::~DIntArr()
{
	delete[] m_data;
	m_data = nullptr;

	m_size = 0;
	m_capacity = 0;

};

bool DIntArr::TryResize(size_t newSize)
{
	if (m_size >= m_capacity)
	{
		int newCapacity = m_capacity * 2;
		int *newData = new int[newCapacity];

		for (int i = 0; i < m_size; i++)
			newData[i] = m_data[i];

		delete[] m_data;
		m_data = newData;

		m_capacity = newCapacity;
		return true;
	}

	return false;
}

void DIntArr::PushBack(int value)
{
	TryResize(m_capacity * 2);


	m_data[m_size] = value;
	m_size += 1;

};

void DIntArr::PushFront(int value)
{
	TryResize(m_capacity * 2);

	m_data[0] = value;
	m_size += 1;

}

size_t DIntArr::Capacity()
{
	return m_capacity;
};

size_t DIntArr::Size()
{
	return m_size;
};

int & DIntArr::operator [] (size_t index)
{
	return m_data[index];
};
DIntArr::Iterator::Iterator()
{
	current = nullptr;
}
DIntArr::Iterator::Iterator(int *pos)
{
	current = pos;
}
DIntArr::Iterator & DIntArr::Iterator::operator ++ ()
{
	++current;
	return *this;
}
DIntArr::Iterator & DIntArr::Iterator::operator ++ (int)
{
	current++;
	return*this;
}
DIntArr::Iterator & DIntArr::Iterator::operator --()
{
	--current;
	return *this;
}
DIntArr::Iterator & DIntArr::Iterator::operator -- (int)
{
	current--;
	return *this;
}

int & DIntArr::Iterator::operator * ()
{
	return *current;
}

bool DIntArr::Iterator::operator == (const Iterator &rhs) const
{
	return current == rhs.current;
}
bool DIntArr::Iterator::operator != (const Iterator &rhs) const
{
	return current != rhs.current;
}

DIntArr::Iterator DIntArr::Begin()
{
	return Iterator(&m_data[0]);
}


DIntArr::Iterator DIntArr::End()
{
	return Iterator(&m_data[m_size]);
}