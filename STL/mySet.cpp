#include <iostream>
#include <stdio.h>
#include <string>
#include <set>

#include "mySet.h"

/*
	//所有元素都是按照字典序自动排序，set只有键值，键值就是市值
	（1）构造：
	（2）通用操作：empty(), insert(), erase(), size(), swap(), find(), count(), 
	（3）特有操作：equal_range(), lower_bound(), upper_bound()
*/

void mySetTest()
{
	std::cout << "-----------------------------this is class set  demo--------------------------" << std::endl;
	std::set<std::string >mySet = {"a", "b", "c"};

	/*
		//insert返回一个pair，first是一个迭代器指向具有给定关键字的值，second是一个bool量，若是true则表示插入成功，
		//若为false则表示插入失败，说明已经存在，则该语句什么也不做
		m.insert(e);                                              //插入pair对象
		m.insert(beg, end);                                       //将范围内的元素插入
		m.insert(iter, e);                                        //unknow
	*/

	bool flag = mySet.empty();
	auto ret = mySet.insert("d");                                                //插入键值
	std::cout << "after inserting, mySet is : \n";
	if (ret.second)
	{
		for (auto tmp : mySet)
			std::cout << tmp << std::ends;
	};
	std::cout << "\n";
	auto ret1 = mySet.erase("d");                                                //删除元素
	for (auto tmp : mySet)
		std::cout << tmp << std::ends;
	std::cout << "\n";

	auto ret2 = mySet.find("a");
	if (ret2 == mySet.end())
		std::cout << "dont find it \n";
	else
		std::cout << "find it \n";

	unsigned int cnt = mySet.count("a");
	printf("a occurred %d times", cnt);

	std::set<std::string>::iterator iter_beg = mySet.lower_bound("a");
	std::set<std::string>::iterator iter_end = mySet.upper_bound("a");      //给定关键字的范围[lower_bound, upper_bound)

}