//nodearray.h
#pragma once

#include <assert.h>
#include "stack.h"
#include "listnode.h"

template <typename T>

class NodeArray : public Stack<T>
{
public:
	NodeArray(const T&);
	NodeArray();
	NodeArray(const NodeArray<T>&);
	NodeArray(const NodeArray<T>&&);
	virtual ~NodeArray();

public:
	virtual void push(const T&);
	virtual void pop();
	virtual void clear();
	virtual T top()const;
	virtual bool empty()const;
	NodeArray<T>& operator=(const NodeArray&);
	NodeArray<T> operator+(const NodeArray&)const;
private:
	ListNode<T>* m_top;
};

template <typename T>

NodeArray<T>::NodeArray()
	: m_top(nullptr)
{}

template <typename T>

NodeArray<T>::NodeArray(const T& node)
{
	ListNode<T> obj(node);
	m_top = &obj;
}

template <typename T>

NodeArray<T>::NodeArray(const NodeArray& obj)
{
	NodeArray<T> cpy;
	ListNode<T>* ptr = obj.m_top;
	while (ptr != nullptr)
	{
		cpy.push(ptr->value);
		ptr = ptr->next;
	}
	ptr = cpy.m_top;
	while (ptr != nullptr)
	{
		this->push(ptr->value);
		ptr = ptr->next;
	}
}

template <typename T>

NodeArray<T>::NodeArray(const NodeArray&& r_v)
{
	m_top = r_v.m_top;
	r_v.m_top = nullptr;
}

template <typename T>

NodeArray<T>::~NodeArray()
{
	clear();
	std::cout << "NodeArray destructor" << std::endl;
}

template <typename T>

void NodeArray<T>::push(const T& node)
{
	ListNode<T>* ptr = new ListNode<T>;
	ptr -> value = node;
	ptr->next = m_top;
	m_top = ptr;
}

template <typename T>

void NodeArray<T>::pop()
{
	ListNode<T>* ptr = m_top;
	m_top = m_top -> next;
	delete ptr;
}

template <typename T>

T NodeArray<T>::top()const
{
	return m_top->value;
}

template <typename T>

bool NodeArray<T>::empty()const
{
	return (m_top == nullptr);
}

template <typename T>

void NodeArray<T>::clear()
{
	while (!empty())
	{
		pop();
	}
}

template <typename T>

NodeArray<T>& NodeArray<T>:: operator=(const NodeArray& obj)
{
	ListNode<T>* ptr = obj.m_top;
	NodeArray<T> rev;
	while (ptr != nullptr)
	{
		rev.push(ptr->value);
		ptr = ptr->next;
	}
	ptr = rev.m_top;
	while (ptr != nullptr)
	{
		this->push(ptr->value);
		ptr = ptr->next;
	}

	return *this;
}

template <typename T>

NodeArray<T> NodeArray<T>:: operator+(const NodeArray& obj)const
{
	NodeArray<T> res, res2;
	res = obj;
	res2 = *this; 
	ListNode<T>* ptr = res2.m_top;
	while (ptr->next != nullptr)
	{
		continue;
	}
	ptr->next = res.m_top;
	return res;
}
