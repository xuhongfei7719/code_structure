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
	vector<Person> v;//����һ������������������װPerson��������ġ�
	Person p1("aaa", 10);//����ʵ��
	Person p2("aaa", 20);
	Person p3("aaa", 30);
	Person p4("aaa", 40);
	Person p5("aaa", 50);
	Person p6("aaa", 60);

	v.push_back(p1);//β�巨������һ������vector����
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)//���еĵ�����iterator���������������Լ�����ģ���������
	{
		cout << "������" << (*it).m_Name << "����:" << (*it).m_Age << endl;//�����ŵ���ʲô���͵����ݣ����������ʵ���д�ŵ���Person��
	}

}

int main()
{
	text01();

	system("pause");
	return 0;
}