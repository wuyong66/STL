#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>

using namespace std;
/*
	（1）构造：tuple<T1, T2, ..., Tn> t();     make_tuple(v1, v2, ... vn);   //返回一个元组， 元组是一个快速而随意的数据结构
	（2）

*/
void tupleAndBitsetTest()
{
	std::cout << "------------------------this is class tupleAndBitset demo----------------------" << std::endl;
	tuple<string, vector<double>, int, list<int>> someVal("constants", { 3.14, 2.718 }, 42, { 0, 1, 2, 3, 4, 5 });
	auto myVecOfTuple = get<1>(someVal);
	cout << "the vec of the tuple is: " << endl;
	for (auto tmp : myVecOfTuple)
		cout << tmp << ends;
	cout << endl;
	cout << "你这个人就是太自私，怎么可能所有的好事都轮着你？" << endl;

}