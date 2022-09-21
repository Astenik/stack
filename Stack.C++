/*name of this file is "stack.h" */

#pragma once

#include "listnode.h"

template <typename T>

class Stack
{
public:
	Stack() {}
	virtual ~Stack() {}
	virtual void push(const T&) = 0;
	virtual void pop() = 0;
	virtual T top()const = 0;
	virtual bool empty()const = 0;
	virtual void clear() = 0;
};
