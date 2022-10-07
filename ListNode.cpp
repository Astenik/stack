/*this file is "stack.h" header file.*/
/*you will create file by name "stack.h" in your computer and then this file you can use. */ 

#pragma once

template <typename T>

struct ListNode
{
	T value;
	ListNode<T>* next;
	ListNode(const T& val = 0, ListNode<T>* n = nullptr)
		: value(val)
		, next(n)
	{}
	~ListNode() {}
};
