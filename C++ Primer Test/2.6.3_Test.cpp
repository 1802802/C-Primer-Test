/*#include <iostream>
#include <string>
using namespace std;

struct Sales_data  //��ϰ2.42
{
	string bookNo;
	unsigned units_sold;
	double revenue;
};

int main()
{
	Sales_data total;
	double price;
	if (cin >> total.bookNo >> total.units_sold >> price)
	{
		total.revenue = total.units_sold*price;
		Sales_data add;
		while (cin >> add.bookNo >> add.units_sold >> price)
		{
			add.revenue = add.units_sold*price;
			if (add.bookNo == total.bookNo)
			{
				total.revenue += add.revenue;      //���������ܼ�������
				total.units_sold += add.units_sold;
			}
			else 
			{
				cout << "��һ��ISBN�鼮Ϊ" << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;  //�����һ���鼮����Ϣ
				total = add;
			}
		}
		cout << "���һ��ISBN�鼮Ϊ" << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;   //������һ���鼮����Ϣ
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/