/*this is a array based stack*/
//Data.h
#pragma once

#include "stack.h"

template <typename T>

class Datas: public Stack<T>
{
public:
    Datas();
    Datas(const T& = 0, int = 1);
    Datas(const Datas<T>&);
    Datas(const Datas<T>&&);
    virtual ~Datas();
    
public:
    virtual void push(const T&);
    virtual void pop();
    virtual T top()const;
    virtual bool empty()const;
    virtual void clear();
    
public:
    Datas<T>& operator=(const Datas<T>&);
    Datas<T> operator+(const Datas<T>&);
    int operator[](int);
    
private:
    int  m_top;
    T* m_arr;
    int m_size;
};

template <typename T>

Datas<T>:: Datas()
     :m_top(-1)
     ,m_arr(nullptr)
     , m_size(0)
     {}

template <typename T>

Datas<T>::Datas(const T& num, int s)
     :m_size(s)
{
    m_arr = new T [m_size];
    m_arr[0] = num;
    ++m_top;
}

template <typename T>

Datas<T>::Datas(const Datas<T>& obj)
{
    m_size = obj.m_size;
    m_arr = new T [m_size];
    for(int i = 0; i <m_size; ++i)
    {
        push(obj.m_arr[i]);
    }
}

template <typename T>

Datas<T>::Datas(const Datas<T>&& tmp)
{
    m_arr = tmp.m_arr;
    m_size = tmp.m_size;
    m_top = tmp.m_top;
    tmp.m_arr = nullptr;
    tmp.m_size = 0;
    tmp.m_top = 0;
}

template <typename T>

Datas<T>::~Datas()
{
    delete [] m_arr;
    std::cout<<"Datas destructor" << std:: endl;
}

template <typename T>

void Datas<T>::push(const T& num)
{
    ++m_top;
    m_arr[m_top] = num;
}

template <typename T>

void Datas<T>::pop()
{
    T* ptr = this;
    T* arr = new T[m_size];
    for(int i = 0; i < m_top; ++i)
    {
        arr[i] = m_arr[i];
    }
    this->m_arr = arr;
    this->m_top = m_top - 1;
    delete ptr;
}

template <typename T>

T Datas<T>::top()const
{
    return m_arr[m_top];
}

template <typename T>

bool Datas<T>:: empty()const
{
    return m_top == -1;
}

template <typename T>

void Datas<T>::clear()
{
    delete [] m_arr;
    m_size = 0;
    m_top = -1;
    m_arr = nullptr;
}

template <typename T>

Datas<T>& Datas<T>:: operator=(const Datas<T>& obj)
{
    if(this == &obj)
    {
        return *this;
    }
    m_size = obj.m_size;
    m_arr = new T [m_size];
    for(int i = 0; i <m_size; ++i)
    {
        push(obj.m_arr[i]);
    }
    return *this;
}

template <typename T>

Datas<T> Datas<T>:: operator+(const Datas<T>& obj)
{
    Datas<T> res(0, m_size+obj.m_size);
    for(int i = 0; i < m_size; ++i)
    {
        res.push(m_arr[i]);
    }
    for(int j = 0; j < obj.m_size; ++j)
    {
        res.push(obj.m_arr[j]);
    }
    return res;
}

template <typename T>

int Datas<T>:: operator[](int i)
{
    return m_arr[i];
}
