/*#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()   //��ϰ1.25 ����ϰ1.22��ͬ
{
	Sales_item add, total;
	if (cin >> total)
	{
		while (cin >> add)
		{
			if (add.isbn() == total.isbn())
				total += add;
			else {
				cout << "��һ��ISBN�鼮Ϊ" << total << endl;
				total = add;
			}
		}
		cout << "���һ��ISBN�鼮Ϊ" << total << endl;
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/