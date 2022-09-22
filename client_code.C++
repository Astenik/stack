#include <iostream>
#include "nodearray.h"
#include "NodeArrayC.h"
#include "ListNode.h"
#include "Stack.h"

int main()
{
	NodeArray<int> obj;
	obj.push(6);
	std::cout << obj.top() << std::endl;
	obj.push(98);
	obj.push(938);
	obj.pop();
	std::cout << obj.top() << std::endl;
	obj.clear();
	std::cout << obj.empty() << std::endl;
	
	Datas <int> obj(5);
        obj.push(89);
        std::cout << obj.top() << std::endl;
        obj.push(34);
        obj.push(8);
        obj.pop();
        std::cout << obj.top() << std::endl;
        std::cout << obj[1] << std:: endl;
	return 0;
}
