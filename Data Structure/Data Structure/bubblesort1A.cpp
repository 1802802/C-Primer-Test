#include "Ch1.h"

static int num = 0;  //������ͳ�ƻ��������Ĵ�����Ԫ�صıȽϺͽ����������������

void bubblesort1A(int A[], int n)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 1; i < n; i++)
		{
			if (A[i - 1] > A[i])
			{
				swap(A[i - 1], A[i]);
				sorted = false;
				num++;
			}
			num++;
		}
		n--;   //ÿ��ѭ����ĩβ�����Ѿ�ȷ��
	}
}

int main_bubblesort1A()
{
	int A[] = { 42,12,2,3,1,23,4,12,4,98 };
	for (auto &s : A)
		cout << s << " ";
	cout << endl;
	cout << num << endl;
	auto sz = sizeof(A) / sizeof(*A);  //������ܴ�С���Ե���Ԫ�صĴ�С�õ������Ԫ������
	bubblesort1A(A, sz);
	for (auto &s : A)
		cout << s << " ";
	cout << endl;
	cout << num << endl;
	return 0;
}