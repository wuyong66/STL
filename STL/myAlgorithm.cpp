#include <iostream>
#include <string>
#include <algorithm>
#include "myAlgorithm.h"

/*
（1）简单查找算法
		（1） find(beg, end, val)           //返回迭代器，若找到指向指定元素迭代器 
		（2） find_if(beg, end, unaryPred)  //返回第一个满足unaryPred的元素  否则尾后迭代器
		（3） count(beg, end, val)          //返回一共有多少个
		（4） count_if(beg, end, val)       //满足条件的一共有多少个

		（5） search(beg1, end1, beg2, end2)         //子序列2在序列1中所处的位置
		（6） find_first_of(beg1, end1, beg2, end2)  //返回第二个序列任意元素在第一个范围内出现的位置  
		（7） find(beg1, end1, beg2, end2)           //和search相反，返回最后一个出现的子序列的位置

（2）其他只读算法
		（1）for_each(beg, end, unaryOp)   //对每个元素使用可调用对象
		（2）equal(beg1, end1, beg2)      //如果输入序列每个元素都和beg2开始的序列相等，则返回true

（3）二分搜索算法
		（1）lower_bound(beg, end, val)    //返回指向第一个小于等于val的迭代器
		（2）upper_bound(beg, end, val)    //返回指向第一个大于val的迭代器
		（3）equal_range(beg, end, val)    //返回以上一个pair包含以上两个函数返回参数

（4）写容器算法
		（1）暂不总结；

（5）划分算法
		（1）is_partitioned(beg, end, unaryPrey)                 //若满足谓词的在前，不满足在后，则返回true, 空也是true
		（2）partitioned_copy(beg, end, dest1, dest2, unaryPred) //将满足谓词的元素放在dest1中，将不满足拷贝在dest2中，返回一个pair
																 //,first指向dest1的末尾，second指向dest2的末尾

（6）排序算法
		（1）sort(beg, end)                                 //给容器排序
		（2）stable_sort(beg, end, comp)                    //稳定排序
		（3）is_sorted(beg, end)                            //返回bool，表示是否有序
		（4）is_sorted_until(beg, end)                      //返回最长有序子序列的尾后迭代器

		（5）remove(beg, end, val)                          //删除元素val，返回指向删除最后一个元素的迭代器
		（6）remove_if(beg, end, unaryPred)                 //删除满足谓词的元素，返回指向删除最后一个元素的迭代器
		（7）unique(beg, end, val)                          //重排元素，对于重复元素重新排在最大不重复子序列的尾后迭代器，一般sort之后
		                                                    //使用该元素将重复元素放在最大不重复子序列的后面，然后可以使用erase删除
		（8）reverse(beg, end)                              //翻转序列

（7）最大最小值算法
		（1）min(val1, val2)
		（2）max(val1, val2)

		（3）min_element(beg, end)                         //返回指向最小值的迭代器
		（4）max_element(beg, end)                         //返回指向最大值的迭代器
		
		（5）minmax_element(beg, end)                      //返回pair 指向（min, max）的两个迭代器

（8）数值算法
		（1）accumulate(beg, end, init)                    //求容器和，init设定为初值，返回和
*/


void myAlgorithmTest()
{
	std::cout << "----------------------------this is class Algorithm demo------------------------" << std::endl;

}