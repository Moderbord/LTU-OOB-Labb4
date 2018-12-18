#pragma once

template <typename T>		// Forward declaration due to friend class
class LinkedList;

template <typename T>
class Node
{
	friend class LinkedList<T>;

private:
	T data;
	Node* next;

public:
	Node()
	{
		next = nullptr;
	};

	T getData()
	{
		return this->data;
	};

	void setData(T data)
	{
		this->data = data;
	};

	Node* getNext()
	{
		return this->next;
	};

	void setNext(Node* next)
	{
		this->next = next;
	};
};