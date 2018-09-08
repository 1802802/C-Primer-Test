/*#include <iostream>
#include <string>
using namespace std;

struct Sales_data  //��ϰ7.6��7.7  //��ϰ7.11
{
	friend istream &read(istream&is, Sales_data&item);              //��Ԫ����������������ʹ��غ�������private����
	friend ostream &print(ostream&os, const Sales_data&item);
	friend Sales_data add(const Sales_data&lhs, const Sales_data&rhs);
public:     
	//���캯��
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s), units_sold(0), revenue(0) {}
	Sales_data(istream &);
	string isbn() const { return bookNo; }   //����isbn�����е������붨�壬�䷵�ض�Ӧ��bookNo
	Sales_data& combine(const Sales_data&);  //����combine�����е����������ڽ������е��������������ֵ���
	double avg_price() const;                //����avg_price�����е����������ڼ���ĳ���е���Ʒ�۸�ƽ��ֵ
	//���캯��������
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&lhs, const Sales_data&rhs)  //�����Ա����add�Ķ��壬���ڽ������е����ݼ���һ���У�Ȼ�󷵻�һ���ֵ
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream&os, const Sales_data&item)  //�����Ա����print�Ķ��壬�������ĳ���е�isbn�ţ�bookNo��,���ۣ��ܼ��Լ�ƽ���۸�
{
	os << "��һ����ı��Ϊ��" << item.isbn() << " ����Ϊ��" << item.units_sold << " �ܼ�Ϊ��" << item.revenue << " ƽ���۸�Ϊ��" << item.avg_price() << endl;
	return os;
}

istream &read(istream&is, Sales_data&item)  //�����Ա����read�Ķ��壬���ڽ��������еı�ţ����������ۣ���������ܼۣ�Ȼ�󷵻����ݵ�����
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

Sales_data::Sales_data(istream &is)  //istreamΪ�����Ĺ��캯��
{
	read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) //���Ա����combine�Ķ��壬������ΪSales_data��������
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const  //��Ա����avg_price�Ķ��壬������Ϊdouble���������ͣ�����ֱֵ��Ϊ��Ʒ����
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main()
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data add;
		while (read(cin, add))
		{
			if (add.isbn() == total.isbn())
			{
				total.combine(add);      //����total��ĺ����е�combine����������ֵthis���ش�total�ĳ�Ա������
			}
			else
			{
				print(cout, total);
				total = add;
			}
		}
		print(cout, total);
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/