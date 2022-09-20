/*name of this file is "nodearray.h". */

#pragma once

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
     virtual bool is_empty();
     virtual U top()const;
     virtual void clear();
     NodeArray<T>& operator=(const NodeArray&);
     NodeArray<T> operator+(const NodeArray)const;
     static int get_c();
     std::ostream&  operator<<(std::ostream&);
  private:
     Listnode<T>* m_top;
};
