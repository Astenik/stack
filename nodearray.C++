//nodearray.h
#pragma once

#include <assert.h>
#include "stack.h"
#include "listnode.h"

template <typename T>

class NodeArray: public Stack<T>
{
  public:
     NodeArray(const T&);
     NodeArray();
     NodeArray(const NodeArray&);
     NodeArray(NodeArray&&);
     ~NodeArray();
  public:
     void push(const T&);
     void pop();
     virtual bool is_empty()const;
     virtual T top()const;
     virtual void clear();
     NodeArray<T>& operator=(const NodeArray<T>&);
     NodeArray<T> operator+(const NodeArray<T>&)const;
     static int get_c();
  private:
     static int m_c;
     Listnode<T>* m_top;
};

template <typename T>

int NodeArray<T>:: m_c = 0;

template <typename T>

int NodeArray<T>:: get_c()
{
    return m_c; // returns the count of created objects;
}

template <typename T>

NodeArray<T>:: NodeArray(const T& num)
{
    Listnode <T> node;
    node.m_value = num;
    node.m_next = nullptr;
    m_top = &node;
    ++m_c;
}

template <typename T>

NodeArray<T>:: NodeArray()
    : m_top(nullptr)
    {
        ++m_c;
    }

template <typename T>

NodeArray<T>::NodeArray(const NodeArray& obj)
{
    m_top = nullptr;
    Listnode <T>* node = obj.m_top;
    NodeArray <T> arr();
    while(node->m_next != nullptr)
    {
        arr.push(node->m_value);
        node = node->m_next;
    }
    arr.push(node->m_value);
    
    node = arr.m_top;
    while(node.m_next != nullptr)
    {
        this->push(node->m_value);
        node = node->m_next;
    }
    this->push(node->m_value);
}

template <typename T>

NodeArray<T>:: NodeArray(NodeArray<T>&& obj)
{
    /*this is a move ctor for NodeArray.*/
    m_top = obj.m_top;
    obj.m_top = nullptr;
}

template <typename T>

NodeArray<T>::~NodeArray()
{
    --m_c;
    clear();
}

template <typename T>

void NodeArray<T>:: push(const T& new_mem)
{
    m_top = new Listnode<T> (new_mem, m_top);
}

template <typename T>

void NodeArray<T>:: pop()
{
    assert(!is_empty());
    Listnode<T>* ptr = m_top;
    m_top = m_top->m_next;
    delete ptr;
    ptr = nullptr;
}

template <typename T>

T NodeArray<T>:: top()const
{
      return m_top->m_value;
}

template <typename T>

bool NodeArray<T>:: is_empty()const
{
    return m_top == nullptr;
}

template <typename T>

void NodeArray<T>:: clear()
{
    while(!is_empty())
    {
        pop();
    }
}

template <typename T>

NodeArray<T>& NodeArray<T>:: operator=(const NodeArray<T>& other)
{
    if(m_top == other.m_top)
    {
        return *this;
    }
    Listnode<T>* cpy = other.m_top;
    NodeArray<T> obj;
    while(cpy->m_next != nullptr)
    {
        obj.push(cpy->m_value);
        cpy = cpy->m_next;
    }
    obj.push(cpy->m_value);
    
    NodeArray<T> obj2;
    cpy = obj.m_top;
    
    while(cpy->m_next != nullptr)
    {
        obj2.push(cpy->m_value);
        cpy = cpy->m_next;
    }
    obj2.push(cpy->m_value);
    obj.clear();
    this->clear();
    *this = obj2;
    return *this;
}

template <typename T>

NodeArray<T> NodeArray<T>:: operator+(const NodeArray<T>& obj)const
{
    NodeArray<T> sum_obj;
    Listnode<T>* ptr = m_top;
    while(ptr->m_next != nullptr)
    {
        sum_obj.push(ptr->m_value);
        ptr = ptr->m_next;
    }
    sum_obj.push(ptr->m_value);
    
    ptr = obj.m_top;
    while(ptr->m_next != nullptr)
    {
        sum_obj.push(ptr->m_value);
        ptr = ptr->m_next;
    }
    sum_obj.push(ptr->m_value);
    
    return sum_obj;
}
