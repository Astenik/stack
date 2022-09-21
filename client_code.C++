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
	return 0;
}
