/*#include <iostream>
#include <string>
using namespace std;


struct Sales_data  //��ϰ7.2
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn() const 
	{ 
		bookNo;
	}
	Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data add;
		while (cin >> add.bookNo >> add.units_sold >> add.revenue)
		{
			if (add.bookNo == total.bookNo)
			{
				total.combine(add);      //����total��ĺ����е�combine����������ֵthis���ش�total�ĳ�Ա������
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