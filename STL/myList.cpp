#include <iostream>
#include <list>
#include <string>
#include "myList.h"

/*
	(1)构造：
	(2)通用函数：push_back(), pop_back(), empty(), clear(), swap(), insert(), erase(), reverse()
	(3)特有操作：push_front(), pop_front(), merge(), remove(), remove_if()
*/

bool  is_odd(const int x)      //充当一元谓词
{
	return (x % 2 == 1);
}
void myListTest()
{
	std::cout << "-----------------------------this is class List demo--------------------------" << std::endl;
	std::list<int >myList{ 3, 5 };
	myList.push_back(7);
	myList.push_front(1);                       //双向链表支持在两端的快速插入和删除
	std::cout << "after push, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

											   //插入操作和其他的一样，在此不再赘述
	auto ret = myList.insert(myList.end(), 9);  
	std::cout << "after inserting, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

	std::list<int >myList1 = { 2, 4, 6, 8 };
	myList.merge(myList1);                        //合并两个有序链表,且元素无重复，返回合并后的排序链表，若二者其一就会出错
	std::cout << "after merging, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

	myList.remove(8);                             //删除所有满足等于8的元素
	std::cout << "after removing, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

	                                               //remove_if()  //当满足条件时，删除
	myList.remove_if(is_odd);
	std::cout << "after remove_if(is_odd), myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';
}
