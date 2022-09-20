/*this file is "stack.h" header file.*/
/*you will create file by name "stack.h" in your computer and then this file you can use. */ 

template <typename T>

struct Listnode
{
    T m_value;
    Listnode* m_next;
    Listnode(int val = 0, Listnode* next = nullptr):m_value(val), m_next(next){}
    ~Listnode(){}
};
