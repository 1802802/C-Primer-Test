/*#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()   //��ϰ1.23��1.24
{
	Sales_item input, total;
	int add = 1;
	if (cin >> total)
	{
		while (cin >> input)
		{
			if (input.isbn() == total.isbn())
				add++;
			else
			{
				cout << "ISBNΪ " << total.isbn() << " ���鼮���ۼ�¼���� " << add << " ��" << endl;
				add = 1;
				total = input;
			}
		}
		cout << "ISBNΪ " << total.isbn() << " ���鼮���ۼ�¼���� " << add << " ��" << endl;
	}
	else
	{
		cerr << "No Data!" << endl;
		return -1;
	}
	return 0;
}*/