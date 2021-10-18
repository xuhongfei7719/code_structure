#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void my_print(int val)
{
	cout << val << endl;
}

void text01()
{
	//创建一个容器，认为其是一个数组
	vector<int> v;

	v.push_back(10);//尾插数据，在容器的尾部插入一个数字
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器的第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向最后一个元素的后一个值

	//while (itBegin != itEnd)//第一种遍历方式
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it !=v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//此三种方式，STL算法迭代
	for_each(v.begin(), v.end(),my_print);


}

int main()
{

	text01();

	system("pause");
	return 0;
}