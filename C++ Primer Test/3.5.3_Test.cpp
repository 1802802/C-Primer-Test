#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //��ϰ3.35
{
	int a[5] = { 1,2,3,4,5 };
	for (auto *i = a, b = 0; i < end(a); i++, b++)
	{
		*i = 0;
		cout << "a[" << b << "]=" << *i << endl;
	}
	return 0;
}*/

/*int main()
{
	int a[3] = { 1,2,5 };
	int b[3] = { 1,2,3 };
	int i = 0;
	for (; i < 3; i++)
	{
		if (a[i] != b[i])
		{
			cout << "�����鲻���" << endl;
			break;
		}
	}
	if (i == 3)
		cout << "���������" << endl;
}*/

/*int main()
{
	string temp1;
	vector<string> a;
	while (cin >> temp1)
		a.push_back(temp1);
	string temp2;
	vector<string> b;
	while (cin >> temp2)
		b.push_back(temp2);
	auto a1 = a.begin();
	auto b1 = b.begin();
	if (a.size() != b.size())
		cout << "���ַ��������1" << endl;
	else
	{
		for (; a1 < a.end(); a1++)
			for (; b1 < b.end(); b1++)
				if (*a1 != *b1)
				{
					cout << "���ַ��������2" << endl;
					break;
				}
	}
	if (a1 == a.end())
		cout << "���ַ������" << endl;
	return 0;
}*/

/*int main()
{
	vector<string> a{ "Hello s" ,"fer"};
	vector<string> b{ "helloo" ,"fer"};
	auto a1 = a.begin();
	auto b1 = b.begin();
	int an = 0;
	int bn = 0;
	for (auto temp1 : a)
		for (auto temp11 : temp1)
		{
			an++;
			cout << an << endl;
		}
	for (auto temp2 : b)
		for (auto temp22 : temp2)
		{
			bn++;
			cout << bn << endl;
		}
	if (an != bn)
		{
			cout << "���ַ��������1" << endl;
			return 0;
		}
	for (; a1 < a.end(); a1++)
		for (; b1 < b.end(); b1++)
			if (*a1 != *b1)
			{
				cout << "���ַ��������2" << endl;
				return 0;
			}
	if (a1 == a.end())
		cout << "���ַ������" << endl;
	return 0;
}*/

/*int main()
{
	string a("hello");
	string b("world");
	auto c = a + b;
	cout << c << endl;
}*/