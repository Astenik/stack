/*this is a array based stack*/
//Data.h
#pragma once

#include "stack.h"

template <typename U>

class Datas : public Stack<U>
{
public:
    Datas();
    Datas(int);
    Datas(Datas&&);
    ~Datas();

public:
    void push(U);
    void pop();
    Datas<U>& operator=(const Datas&);
    Datas<U> operator+(const Datas&)const;
    U operator[](int);
    int get_top();

private:
    int m_size;
    U* m_arr;
    int m_top;
};

template <typename U>

U Datas<U>:: operator[](int i)
{
    return m_arr[i];
}

template <typename U>

int Datas<U>::get_top()
{
    return m_top;
}

template <typename U>

Datas<U>::Datas() :m_size(1), m_top(-1)
{
    /*this is default constructor*/
    m_arr = new U[m_size];
    assert(m_arr);
    ++m_count;
}

template <typename U>
Datas<U>::Datas(int size) :m_size(size), m_top(-1)
{
    /*this is constructor with parametres*/
    m_arr = new U[m_size];
    assert(m_arr);
    ++m_count;
}

template <typename U>

Datas<U>::Datas(Datas<U>&& obj)
{
    /*this is a move ctor.*/
    m_size = obj.m_size;
    m_top = obj.m_top;
    m_arr = obj.m_arr;
    obj.m_arr = nullptr;
    obj.m_top = 0;
    obj.m_size = 0;
}

template <typename U>

Datas<U>:: ~Datas()
{
    /*this is destructor*/
    delete[] m_arr;
    --m_count;
}

template <typename U>

void Datas<U>::push(U elem)
{
    /*this member function(method) addes a element to the array to the top.*/
    if (m_top <= m_size - 1)
    {
        ++m_top;
        m_arr[m_top] = elem;
    }
    else
    {
        std::cout << "the array is full." << std::endl;
    }
}

template <typename U>

void Datas<U>::pop()
{
    /*this method remove the top elemrny*/
    if (m_top >= 0)
    {
        delete& m_arr[m_top];
        --m_top;
    }
    else
    {
        std::cout << "there is no element to remove." << std::endl;
    }
}

template <typename U>

Datas<U>& Datas<U>:: operator=(const Datas<U>& obj)
{
    /*this is a operator =.*/
    if (m_size == obj.m_size)
    {
        for (int i = 0; i <= obj.m_top; ++i)
        {
            m_arr[i] = obj.m_arr[i];
        }
    }
    else
    {
        delete[] m_arr;
        m_arr = new U[obj.m_size];
        assert(m_arr);
        m_size = obj.m_size;
        m_top = obj.m_top;
        for (int i = 0; i <= m_top; ++i)
        {
            m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}

template <typename U>

Datas<U> Datas<U>:: operator+(const Datas<U>& obj)const
{
    Datas<U> res(m_size + obj.m_size);
    int i;
    for (i = 0; i <= m_top; ++i)
    {
        res.m_arr[i] = m_arr[i];
    }
    for (int j = 0; j <= obj.m_top; ++j)
    {
        res.m_arr[i] = obj.m_arr[j];
        ++i;
    }
    res.m_top = i - 1;
    return res;
}
