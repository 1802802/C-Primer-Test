/*#include <iostream>
#include <string>
using namespace std;

struct Sales_data  //��ϰ2.41
{
	string bookNo;
	unsigned units_sold;
	double revenue;
}; 

int main()
{
	Sales_data book1, book2;
	double price = 0;
	cin >> book1.bookNo >> book1.units_sold >> price;  //��һ������Ϣ����
	book1.revenue = book1.units_sold*price;            //�����һ�����ܼ�
	cin >> book2.bookNo >> book2.units_sold >> price;  //�ڶ�������Ϣ����
	book2.revenue = book2.units_sold*price;            //����ڶ������ܼ�
	
	if (book1.bookNo == book2.bookNo)
	{
		unsigned totalCnt = book1.units_sold + book2.units_sold;  //�����������֮��
		double totalRevenue = book1.revenue + book2.revenue;      //��������ܼ�֮��
		//����鱾��š����������������ۼ�
		cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
			//����鱾ƽ���۸�
			cout << totalRevenue / totalCnt << endl;
		else
			cout << "No Sale" << endl;			  //��������
		return 0;
	}
	else
		cerr << "�������ISBN�Ų�һ�£�" << endl; //����
	return -1;
}*/