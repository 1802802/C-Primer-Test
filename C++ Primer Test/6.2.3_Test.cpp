/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

auto daxie(const string &a)  //����д����
{
	int m = 0;
	for (auto i : a)
	{
		if (isupper(a[m]))
			break;
		m++;
	}
	return m;
}

auto xiaoxie(string &a)  //Сд�޸ĺ���
{
	int m = 0;
	for (auto &i : a)
	{
		a[m] = tolower(a[m]);
		m++;
	}
	return 0;
}

int main()  //������
{
	string A = ("My Name is YZT.");
	auto n = daxie(A);
	cout << "ԭ�ַ���Ϊ��" << A << endl;
	if (n == A.size())
		cout << "�ַ�����û�д�д��ĸ" << endl;
	else
		cout << "�ַ������д�д��ĸ" << endl;
	xiaoxie(A);
	cout << "ȫΪСд���ַ���Ϊ��" << A << endl;
	return 0;
}*/