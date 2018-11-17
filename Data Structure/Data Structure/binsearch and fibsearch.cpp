#include "Ch2.h"
#include "Fib.h"

template<typename T> static Rank binsearch_C(T *A, T const &e, Rank lo, Rank hi)
{
	while (lo < hi)
	{
		cout << "�������ѭ��" << endl;
		Rank mi = (lo + hi) >> 1;
		cout << "����ѭ��mi��ֵ" << endl;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
		cout << "����ѭ���Ƚϲ���" << endl;
		cout << "�˳�����ѭ��" << endl;
	}
	return --lo;
}

template<typename T> static Rank fibsearch_B(T *A, T const &e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);
	while (lo < hi)
	{
		cout << "����fibѭ��" << endl;
		while ((hi - lo) < fib.get()) fib.prev();
		cout << "fibѭ��ȡfibֵ" << endl;
		Rank mi = lo + fib.get() - 1;
		cout << "fibѭ����ֵ" << endl;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
		cout << "fibѭ���Ƚ�" << endl;
		cout << "�˳�fibѭ��" << endl;
	}
	return --lo;
}

int main_binsearch_and_fibsearch()
{
	initializer_list<int> list{ 1,2,3,4,5,8,12 };
	Vector<int> a(list);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] <<" ";
	cout << endl;
	auto b1 = binsearch_C(a._elem, 2, 0, 7);
	cout << b1 << endl;
	auto b2 = fibsearch_B(a._elem, 2, 0, 7);
	cout << b2 << endl;
	return 0;
}