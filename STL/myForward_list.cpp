#include <iostream>
#include <string>
#include <forward_list>
#include "myForward_list.h"   //单向链表

/*
	（1）构造：
	（2）通用函数：empty(), front(）, swap(), clear(), push_front(), pop_front(), reverse(), 
	（3）特有函数：inert_after(), erase_after(), remove(), remove_if(), unique(), sort(), merge(), 

*/
void myForward_listTest()
{
	std::cout << "------------------------this is class forward_list demo-----------------------" << std::endl;
	std::forward_list<int> myForward_list = { 1, 3, 5, 7 };
	std::cout << "the front of myForward_list is : " << myForward_list.front() << std::endl;    //front数

	myForward_list.push_front(0);
	for (auto tmp : myForward_list)
		std::cout << tmp << ' ';
	std::cout << '\n';



}