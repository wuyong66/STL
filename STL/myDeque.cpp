#include <iostream>
#include <string>
#include <deque>
#include "myDeque.h"

/*
	//特点：支持随机访问，可以在内部进行插入和删除操作，在两端插入删除性能最好，
	（1）创建：
	（2）通用操作：push_back(), pop_back(), insert(), erase(), clear(), swap(), empty(), back(), front(), at(), []
	（3）特有操作：push_front(), pop_front()
*/
void myDequeTest()
{
	std::cout << "---------------------------this is class deque demo--------------------------" << std::endl;
	std::deque<int >myDeque = { 3, 5, 7 };
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';

	myDeque.push_back(9);                                                   //在队列尾部添加元素
	myDeque.push_front(1);                                                  //在队列头部添加元素
	std::cout << "after pushing, myDeque is: \n";
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';

	/*
	insert()版本：
	（1）insert(p, t)     //在迭代器p之前创建一个值为t，返回指向新添加的元素的迭代器
	（2）insert(p, b, e)  //将迭代器[b, e）指定的元素插入到p所指位置，返回第一个插入元素的迭代器
	//关于迭代器确定范围都是左闭右开！！！！
	*/
	auto ret = myDeque.insert(myDeque.begin() + 1, 2);
	std::cout << "after inserting, myDeque is: \n";
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';
	std::cout << "返回迭代指向的元素为：";
	std::cout << *ret << std::endl;

	auto ret1 = myDeque.erase(ret);
	std::cout << "after earsing, myDeque is: \n";
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';
	std::cout << "返回迭代指向的元素为：";
	std::cout << *ret1 << std::endl;





	
}