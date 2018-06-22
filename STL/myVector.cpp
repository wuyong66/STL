#include <iostream>
#include <string>
#include <vector>
#include "myVector.h"
#include "myVector.h"
/*
实现string常见的操作：
	（1）构造、赋值:
	（2）基本操作：size(), empty(),  push_back(), pop_back(), insert(), erase(), clear(), swap();
*/

void myVectorTest()
{
	std::cout << "-----------------------------this is class vector demo--------------------------" << std::endl;
	std::vector<int> myVec = { 1, 3, 5, 7, 9 };
	std::vector<int> myVec1 = { 4, 6, 8 };
	std::cout << "the length of myVec：" << myVec.size() << std::endl;
	myVec.push_back(0);                                                                 //在尾部添加字符
	std::cout << "after pushing, myVec is: "  << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	/*
	insert()版本：
		（1）insert(p, t)     //在迭代器p之前创建一个值为t，返回指向新添加的元素的迭代器
		（2）insert(p, b, e)  //将迭代器[b, e）指定的元素插入到p所指位置，返回第一个插入元素的迭代器
		（3）insert(p, il)    //将列表中的元素插入，返回第一个插入元素的迭代器
		                      //关于迭代器确定范围都是左闭右开！！！！
	*/
	auto ret = myVec.insert(myVec.begin() + 1, 2);                                //插入单个元素，返回该元素迭代器
	std::cout << "after inserting , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "返回的迭代器值为：" << *ret << std::endl;

	auto ret1 = myVec.insert(myVec.begin() + 1, myVec1.begin(), myVec1.end());     //插入系列元素，返回第一个插入元素迭代器
	std::cout << "after inserting , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "返回的迭代器值为：" << *ret1 << std::endl;
		/*
	insert()版本：
		（1）erase(p)         //删除迭代器p所指元素，返回下一个元素的迭代器
		（2）erase(b, e)      //删除迭代器[b, e) 范围内的元素；
		                      //关于迭代器确定范围都是左闭右开！！！！
	*/
	auto ret2 = myVec.erase(myVec.begin() + 1);                                 //删除单个迭代器指向的元素，
	std::cout << "after earsing , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "返回的迭代器值为：" << *ret2 << std::endl;

	auto ret3 = myVec.erase(myVec.begin() + 1, myVec.begin() + 4);              //返回迭代器对指向的范围内的元素
	std::cout << "after earsing , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "返回的迭代器值为：" << *ret3 << std::endl;

	std::swap(myVec, myVec1);                                                   //交换两个容器的值，其实实质上并不交换
	std::cout << "after swapping , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

}