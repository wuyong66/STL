/*
实现string常见的操作：
（1）构造、赋值:
（2）基本操作：size(), empty(),  push_back(), pop_back(), insert(), erase(), clear();
（3）string特有操作：substr(), append(), replace(), find()系列函数, compare()
*/
#include <iostream>
#include <string>
#include <string.h>
#include "myString.h"


void myStringTest()
{
	std::cout << "-----------------------------this is class string demo--------------------------" << std::endl;
	std::string str1 = "hello world";
	std::cout << "the length of str1：" << str1.size() << std::endl;
	str1.push_back('!');                                 //在尾部添加字符
	std::cout << "after pushing, str1 is: " << str1 << std::endl;
	
	auto ret = str1.insert(str1.begin() + 5, '@');       //接受迭代器版本返回的是指向插入元素的迭代器
	std::cout << "after inserting, str1 is : " << str1 << std::endl;
	std::cout << "插入返回的迭代器所指向的值为：" << *ret << std::endl;

	auto ret1 = str1.insert(6, "#");                     //参数为下标的，插入的是字符串，返回的是插入之后str1的引用,记住字符串下标是从0开始的
	std::cout << "after inserting, str1 is : " << str1 << std::endl;
	std::cout << "插入返回的值为：" << ret1 << std::endl;

	auto ret2 = str1.erase(str1.begin() + 5);            //接受迭代器版本的，返回删除元素之后的迭代器
	std::cout << "after earsing , str1 is: " << str1 << std::endl;
	std::cout << "返回的迭代器指向元素为：" << *ret2 << std::endl;

	auto ret3 = str1.erase(5, 1);                       //接受下标参数的，,接受删除长度，返回删除元素之后的引用
	std::cout << "after earsing , str1 is: " << str1 << std::endl;
	std::cout << "返回的迭代器指向元素为：" << ret3 << std::endl;
	//string s.substr(pos, n) //n若缺失，到结尾
	std::string str2 = str1.substr(0, 5);                //从0开始，长度为5的子串，若5缺失，则默认到末尾
	std::cout << "after substr, str2 is :" << str2 << std::endl;

	str1.append("!!!");                                   //在尾部添加子串
	std::cout << "after appending, str1 is :" << str1 << std::endl;

	//string &s.replace(range, args)                      //将range范围内的元素，替换为args，可以不一样长
	//举例几种常见的：
	str1.replace(5, 1, "###");                            //(pos, len, str)形式
	std::cout << "after replace, str1 is : " << str1 << std::endl;

	str1.replace(str1.begin() + 5, str1.begin() + 7, "%%%");  //(iterator1, iterator2, string)形式
	std::cout << "after replace, str1 is : " << str1 << std::endl;

	//s.compare() ，目前就记住这一个就行，多了也记不住
	str1.compare(str2);

	/*
	find系列函数：
	(1) s.find(args)          //查找s中第一次出现的位置,并返回子串在主串中第一个字符的下标
	(2) s.rfind(args)         //查找最后一个...
	(3) s.find_first_of(args) //在s中查找args中任何一个字符的第一次出现的位置，
	(4) s.find_last_of(args)  //在s中查找args中任何一个字符最后一次出现的位置。
	(5) s.find_first_not_of(args)   //在s中查找第一个不在args中的字符
	(6) s.find_last_not_of(args)    //查找最后一个不在args中的字符
	*/
	auto pos = str1.find(str2);
	std::cout << "str2 is at the pos : " << pos << " of str1" << std::endl;
	std::string numbers("01234556789");
	std::string name("r2d2");
	auto pos1 = name.find_first_of(numbers);
	std::cout << "number first at the pos : " << pos1 << " of name" << std::endl;

	if (str1.compare(str2))    
		std::cout << "str1 > str2" << std::endl;
}