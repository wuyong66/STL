#include <iostream>
#include <string>
#include <forward_list>
#include <iterator>      //其中的advance函数，可以移动迭代器移动指定长度；
#include "myForward_list.h"   //单向链表
#include "myList.h"
/*
	（1）构造：
	（2）通用函数：empty(), front(）, swap(), clear(), push_front(), pop_front(), reverse(), 
	（3）特有函数：inert_after(), erase_after(), before_begin(), remove(), remove_if(), unique(), sort(), merge(), 

*/

void myForward_listTest()
{
	std::cout << "------------------------this is class forward_list demo-----------------------" << std::endl;
	std::forward_list<int> myForward_list = { 1, 3, 7, 5, 5 };
	std::cout << "the front of myForward_list is : " << myForward_list.front() << std::endl;    //front数

	myForward_list.push_front(0);
	for (auto tmp : myForward_list)
		std::cout << tmp << ' ';
	std::cout << '\n';
	/*
	lst.insert_after(p, t)       //在迭代器p之后的位置插入元素t，返回指向插入元素的迭代器
	lst.insert_after(p, b, e)    //在迭代器p之后插入范围为[b, e）的元素，返回最后一个插入链表的迭代器
	*/
	auto iter = myForward_list.before_begin();
	std::advance(iter, 1);                                                          //另外还可以使用iterator中的advance函数对迭代器进行偏移
	myForward_list.insert_after(myForward_list.before_begin(), 9);                  //list 和forward_list虽然不支持+,-操作，但是支持++， （--）操作
	std::cout << "after inserting , myForward_list is : " << std::endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)   
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';

	myForward_list.erase_after(myForward_list.before_begin());                      //在迭代器p之后的位置插入元素t，返回指向插入元素的迭代器
	std::cout << "after erasing , myForward_list is : " << std::endl;             
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';
	  
	//myForward_list.remove(9);                                                    //删除某一特定值元素
	//myForward_list.remove_if(is_odd);                                            //按照传入谓词来删除某一元素

	myForward_list.unique();                                                       //踢出重复数据
	std::cout << "after unique , myForward_list is : " << std::endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';

	myForward_list.sort();                                                         //对链表数据进行排序
	std::cout << "after sorting , myForward_list is : " << std::endl;  
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';


}