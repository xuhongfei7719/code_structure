#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;


};

void text01()
{
	vector<Person> v;//声明一个容器，容器是用来装Person这个东西的。
	Person p1("aaa", 10);//函数实现
	Person p2("aaa", 20);
	Person p3("aaa", 30);
	Person p4("aaa", 40);
	Person p5("aaa", 50);
	Person p6("aaa", 60);

	v.push_back(p1);//尾插法，插入一个对象到vector容器
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)//其中的迭代器iterator是用来连接容器以及对象的，其中中括
	{
		cout << "姓名：" << (*it).m_Name << "年龄:" << (*it).m_Age << endl;//号里存放的是什么类型的数据，比如在这个实例中存放的是Person类
	}

}

int main()
{
	text01();

	system("pause");
	return 0;
}