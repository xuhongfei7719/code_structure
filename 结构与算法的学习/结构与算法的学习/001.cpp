#include<iostream>
#include<list>

using namespace std;


void unionL(List *La, List Lb)
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
			ListInsert(La, ++La_len, e);
	}
}


int main()
{
	List Lb;
	List

	unionL(*La, Lb);
	cout << sum << endl;
	system("pause");
	return 0;
}
