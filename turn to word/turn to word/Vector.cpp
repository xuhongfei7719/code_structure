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
	//����һ����������Ϊ����һ������
	vector<int> v;

	v.push_back(10);//β�����ݣ���������β������һ������
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	vector<int>::iterator itBegin = v.begin();//��ʼ��������ָ�������ĵ�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();//������������ָ�����һ��Ԫ�صĺ�һ��ֵ

	//while (itBegin != itEnd)//��һ�ֱ�����ʽ
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//�ڶ��ֱ�����ʽ
	//for (vector<int>::iterator it = v.begin(); it !=v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//�����ַ�ʽ��STL�㷨����
	for_each(v.begin(), v.end(),my_print);


}

int main()
{

	text01();

	system("pause");
	return 0;
}