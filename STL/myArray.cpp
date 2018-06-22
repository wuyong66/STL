#include <iostream>
#include <string>
#include <array>
#include "myArray.h"
/*
	（1）构造：std::array<int, 5> myArr = {2, 4, 6};
	（2）通用操作：size(), maxsize(), empty(), operator[](), at(), front(), back(), swap(),  
	（3）特有操作：data(), fill()
*/
void myArrayTest()
{
	std::cout << "---------------------------this is class array demo--------------------------" << std::endl;
	std::array<int, 10 >myArray = { 3, 5 };
	for (auto tmp : myArray)
	{
		std::cout << tmp << std::ends;

	}
	std::cout << '\n';
	//没啥好讲的这一节：

	auto p = myArray.data();                    //返回数组第一个元素的指针
	std::cout << *p << std::endl;

}