#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stdio.h>

#include "myStackAndQueue.h"

/*
	（1）构造：std::atack<int >myStack;
	（2）通用操作：empty(), size(),
	（3）特有操作：pop(), push(),top(),
*/
void myStackTest()
{
	std::cout << "---------------------------this is class stack demo--------------------------" << std::endl;
	std::stack<int >myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);                                                      //元素进栈
	 

	int top_num = myStack.top();                                          //栈顶元素
	std::cout << "the num of myStack is: " << top_num << std::endl;
	myStack.pop();                                                        //弹出栈顶元素
	int top_num1 = myStack.top();
	std::cout << "the num of myStack is: " << top_num1 << std::endl;
	
}
/*
	（1）构造：  std::queue<int> myQueue;
	（2）通用操作：empty(), size(), front(), back(), 
	（3）特有操作：push(), pop(), 
*/
void myQueueTest()
{
	std::cout << "---------------------------this is class queue demo--------------------------" << std::endl;
	std::queue<int > myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);                                   //入队列
	int front_num = myQueue.front();                   //队列头元素
	int back_num = myQueue.back();                     //队列尾元素
	printf("the front and back num of the myQueue : %d and %d \n", front_num, back_num);

	myQueue.pop();                                     //弹出元素不返回元素
	myQueue.pop();
	int front_num1 = myQueue.front();
	int back_num1 = myQueue.back();
	printf("the front and back num of the myQueue : %d and %d \n", front_num1, back_num1);





}