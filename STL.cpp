/********************************************************************************************************
Copyright: wuyong
Author: wuyong
Date: 2018-05-16
Description:本例程提供了C++的STL常用数据结构及其算法的使用范例，为面试笔试编程题提供便利
*********************************************************************************************************/

#include <iostream>  
/*************************************************顺序容器***********************************************/
#include <string> //和vector是一样的，支持快速随机访问，在尾部之外的其他的位置插入都很慢
#include <vector> //可变大小数组，支持快速随机访问，在尾部之外的其它位置插入或者删除元素可能很慢

#include <list>   //双向链表，只支持双向顺序访问，在list中的任意位置插入和删除都很快

//forward_list单向链表设计目标是达到与手写单向链表相当的性能。
#include <forward_list>  //单向链表，只支持单向顺序访问，在链表任意位置插入和删除都很快,是c++11新加的标准

//在queue的中间位置插入或者删除元素代价都很高
#include <deque>  //双端队列，支持快速随机访问（肯定是顺序存储式队列），从头尾位置处插入和删除速度很快

//与内置数组相比，更加安全和方便；
#include <array>  //固定数组大小，支持快速，不能添加或者删除元素，是c++11新加的标准，支持对象赋值或者拷贝操作

//是一种容器适配器实现的栈结构
#include <stack> //栈结构，支持栈顶的快速进栈出栈操作，在栈的其他部位不可操作。
/*************************************************顺序容器***********************************************/

/*************************************************关联容器***********************************************/
#include <map> 
/*************************************************关联容器***********************************************/


/*************************************************无序容器***********************************************/

/*************************************************无序容器***********************************************/

/*----------------------------------------容器所共同支持的操作--------------------------------------------
1）类型别名
	1. iterator/const_iterator/size_type/difference_type/reference/const_reference

2）构造函数
	1. C c         //调用默认构造函数，无参
	2. C c1(c2)    //调用复制构造函数，有参，可合成
	3. C c(b, e)   //调用构造函数，带参，迭代器b,e指向的容器范围进行初始化构造
	4. C c{a, b, c, ......} //列表初始化构造，带参构造

3）赋值与swap
	c1 = c2
	c1 = {a, b, c, ......}
	a.swap(b)     //成员函数版的交换函数
	swap(a, b)    //非成员函数版的交换函数

4）大小
	1. c.size()   //求容器大小，
	2. c.max_size() //容器最多可保存的数据
	3. c.empty()    //返回容器是否为空

5）添加删除元素
	1. c.insert(args)  //插入元素
	2. c.emplace(inits)  //使用inits构造c中的一个元素
	3. c.erase(args)    //删除元素

6）获取迭代器
	1. c.bengin() c.end()
	2. c.cbegin(), c.cend()
反向迭代器的成员
	reverse_iterator
	const_reverse_interator
	3. c.rbegin(), c.rend()
	4. c.crbegin(), c.crend()
-----------------------------------------------------------------------------------------------------------*/


/*-------------------------------------------选择顺序容器的准则：-------------------------------------------

	1）若要求支持随机访问,vector queue
	2）程序要求在中间插入或者删除元素，则选择使用list 或者forward_list
	3）如果程序只会在头部或者尾部插入删除数据，则选择使用queue
	4）如果不知道选择哪种容器，则在程序中只使用list和vector容器，并且只使用迭代器而不使用下标操作
-----------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------容器的定义及初始化--------------------------------------------
C c          默认构造函数，若c是个array，则执行默认初始化，若是vector等则是空容器
C c1(c2)     c1初始化为c2的拷贝，必须是同种类型，且保存的相同的元素类型，若是array，两者还必须是相同的大小
C c1 = c2    同上

C c{a, b, c,...}    对于array，列表中的元素必须少于array的大小
C c = {a, b, c,...}

C c(b, e)    c初始化为迭代器b,e指定范围中元素的拷贝

//只有顺序容器才支持的操作：
C seq(n)    seq包含n个元素,这些元素进行了值初始化
C seq(n, t) seq包含n个初始化为值t的元素

//关于array类型：
array<int, 40> 
-----------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------赋值和swap()--------------------------------------------
c1 = c2            c2向c1拷贝

c = {a, b, c,...}  列表赋值， 而array不适用，因为array没有定义隐式转换的构造函数？
swap(c1, c2)       交换两个容器的元素
c1.wap(c2)         同上

//assign 操作不适合关联容器和array
seq.assign(b, e)   使用迭代器b，e替换容器中的元素
seq.assign(il)     使用列表进行复制
seq.assign(n, t)   使用n个值为t的元素。

//使用swap()       交换两个容器的值，不对元素进行拷贝工作，所以速度很快，除array以外
                   统一使用非成员swap(）是一个很好的选择
vector<string> svec1(10);
vector<string> svec2(20);
swap(svec1, svec2);
-----------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------容器大小操作-----------------------------------------------
> < == : 比和string字符串的比较一样的，只有容器的元素定义了关系运算符，才可以比较容器之间的大小
size()     返回容器中元素的个数
empty()    容器是否为空
max_size() 该类型容器最大容纳的元素的个数
           //forward_list不支持size()操作，原因肯定是因为要去手写单向链表一致
-----------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------顺序容器操作-----------------------------------------------

//forward_list   有自己专门的insert和emplace,不支持push_back和emplace_back, vector/string不支持push_front
				 以及emplace_front,虽然有些容器支持,但是对于insert(begin,...)没有限制

c.push_back(t)         在c的尾部创建t或者args创建的元素，返回void
c.emplace_back(args) 

c.push_front(t)        在c的开头创建t或者args创建的元素，返回void
c.emplace_front(t)

c.insert(p, n, t)      在迭代器p之前插入n个值为t的元素，返回新添加的第一个元素的迭代器，若n为0，则返回p
c.insert(p, b, e)      将迭代器b, e指向的元素之前插入到p所指向新添加元素之前，返回新添加第一个元素的迭代器
//insert 是按顺序向后插入的，比如{0, 1, 2}的begin插入{3，4，5}是{3, 4, 5, 0, 1, 2}
//向一个vector/string/deque中插入元素会使所有指向容器的迭代器、引用、指针失效。
//当我们使用一个对象来初始化容器时，或者将元素插入容器中，实际上放入容器的是其对象值的一个拷贝，两者并无关联

//vector和string不支持push_front()操作，而list、forward_list、deque支持push_front()操作;push_front是一种倒序的结果
//emplace_back emplace emplace_front 是在内存空间里直接构造对象，而不是拷贝。 emplace_back(args)

*************************************************************************************************************
访问元素，除了forward_list 每一个容器都提供了c.front(),以及c.back()成员，用以返回容器的首尾元素的引用
at和下标操作只适合string vector deque array  如果越界，则会爆出out_of _range错误

*************************************************************************************************************
以下操作不适合array，因为这些操作会改变容器的大小，不适于array
c.pop_back()   //删除c中的尾元素,若c为空则函数行为未定义
c.pop_front()  //删除队头元素，若c为空，则函数未定义

c.erase(p)     //删除迭代器所指的元素，返回一个指向被删除元素之后的元素的迭代器，若p指向最后一个元素，则返回
               //尾后迭代器，
c.erase(p, e)  //删除迭代器b和e所指定范围内的元素，返回一个指向最后一个被删除元素之后的元素的迭代器，若e本身也是
               //最后一个元素，那么也返回尾后迭代器,双闭

c.clear()     //删除所有的元素，

//PS：删除deque除首尾之外的所有元素都会值得所有迭代器，引用或者指针失效，指向vector以及string的删除点之后位置的
迭代器、引用、指针失效。

**************************************************************************************************************
forward_list特有的操作：forward_list<int >lst
lst.before_begin()
lst.cbefore_begin()  返回首前迭代器

lst.insert_after(p, t) 在迭代器p之后插入为值t的对象
lst.insert_after(p, n, t) n个值为t的对象 返回最后一个插入的元素的迭代器，
lst.insert_after(p, b, e) n个值为t的对象 返回最后一个插入的元素的迭代器，
lst.insert_after(p, il)   n个值为t的对象 返回最后一个插入的元素的迭代器，
emplace_after(p, args) 在p之后创建元素

lst.erase_after(p) 删除p之后的元素,返回一个被删除元素之后的元素的迭代器
lst.erase_after(b, e) 删除[p, e)的元素,返回最后一个被删除元素之后的元素的迭代器

***********************************************************************************************************
//resize()      不适合array
c.resize()      调整c的大小为c个元素，若不足，则补足
c.resize(n, t)  略

***********************************************************************************************************
c.capacity()    返回在不扩张内存的情况下可以容纳多少元素。
c.reserve()     分配至少能容纳n个元素的内存空间
c.size()        容器中有多少元素
-----------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------额外的string构造方法-----------------------------------------------
string s(cp, n)     s是cp指向数组中前n个字符的拷贝，此数组至少应该包含n个字符
string s(s2, pos2)  s是s2从下标pos2开始的拷贝，
string s(s2, pos2, len2) s是s2从下标pos2开始，长度为len2的拷贝

s.substr(pos = 0, n = s.size() - pos)    //返回一个string 包含从pos开始的n个字符的拷贝

string s("hello world");
string s2 = s.substr(0, 5);      //s2 = hello
string s3 = s.substr(6);         //s3 = world
string s4 = s.substr(6, 11);     //s4 = world
string s5 = s.substr(12);        //抛出一个out_of_range

//除了普通的insert()和erase()操作，string还有以下的重载版本，都是在pos之前插入或者删除，字符串下标是从0开始的
//string还提供了两个额外的成员append(),replace()，append()是在string末尾加入的一种形式，而replace是调用erase()和
//insert()的简写形式

s.insert(pos, args)   //在pos之前插入args指定的字符，pos是个下标或者是一个迭代器，接受下标的版本返回一个指向s的
                        引用,接受迭代器的版本返回指向第一个插入字符的迭代器

s.erase(pos, len)    //删除从pos处开始的len个字符，如果len省略则删除pos开始的所有字符，返回一个指向s的引用

s.replace(range, args)  //删除range内的元素，替换为args的元素，args可以是一个下标加一个长度，或者一对迭代器，返回
                          返回一个指向s的引用
s.append(args)          //将args加入到s的尾部，返回一个指向s的引用

s.assign(args)          //将s中的字符替换为args字符，返回一个引用

***************************************************************************************************************
string的搜索函数：
(1) s.find(args)          //查找s中第一次出现的位置,并返回子串在主串中第一个字符的下标
(2) s.rfind(args)         //查找最后一个...
(3) s.find_first_of(args) //在s中查找args中任何一个字符的第一次出现的位置，
(4) s.find_last_of(args)  //在s中查找args中任何一个字符最后一次出现的位置。
(5) s.find_first_not_of(args)   //在s中查找第一个不在args中的字符
(6) s.find_last_not_of(args)    //查找最后一个不在args中的字符

(1) args必须是以下的形式：
（c, pos）   从s中位置pos开始查找字符c，pos默认0。
（s2, pos）  从s中位置pos开始查找字符串s2，pos默认0。
（cp, pos）  从s中位置pos开始查找cp指向的以空字符结尾的C风格字符串，pos默认为0
（cp, pos, n）  从s中位置pos开始查找指针cp指向的数组的前n个字符。pos和n无默认值

**************************************************************************************************************

-----------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------额外的string构造方法---------------------------------------
给出string vector array list forward_list deque stack map multimap set multiset tuple bitset所支持的操作以及范例
-----------------------------------------------------------------------------------------------------------*/

int main()
{
	std::cout << "顺序容器的实验：\n";
	std::vector<int >int_vec_des = { 0, 1, 2, 3 };
	std::cout << "原容器内的元素为：\n";
	for (auto tmp : int_vec_des)
		std::cout << tmp << std::ends;
	std::cout << '\n';
	std::cout << "待插入的元素：\n";
	std::vector<int >int_vec_res = { 4, 5, 6, 7 };
	for (auto tmp : int_vec_res)
		std::cout << tmp << std::ends;
	std::cout << '\n';
	std::cout << "插入之后容器为：\n";
	std::vector<int>::iterator iter = int_vec_des.begin();
	auto iter1 = int_vec_des.insert(iter, int_vec_res.begin(), int_vec_res.end());
	for (auto tmp : int_vec_des)
		std::cout << tmp << std::ends;
	std::cout << "\n";
	std::cout << "返回的迭代器指向的元素为";
	std::cout << *iter1 << std::endl;

	std::cout << "插入列表元素为{7， 8， 9}，插入之后原容器为：\n";
	int_vec_des.insert(iter1, { 7, 8, 9 });
	for (auto tmp : int_vec_des)
		std::cout << tmp << std::ends;


	std::cout << "\n--------------------------------------------------------------" << std::endl;
	std::string str = "abcdef";
	str.insert(1, "v");
	std::cout << str << std::endl;

	system("pause");

	return 0;
}
















