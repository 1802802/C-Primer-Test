#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
	friend istream &read(istream&is, Sales_data&item);              //��Ԫ����������������ʹ��غ�������private����
	friend ostream &print(ostream&os, const Sales_data&item);
	friend Sales_data add(const Sales_data&lhs, const Sales_data&rhs);
	friend istream& operator >> (std::istream &in, Sales_data &temp);
	friend ostream& operator<<(std::ostream &out, const Sales_data &temp);
public:
	//���캯��
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s), units_sold(0), revenue(0) {}
	Sales_data(istream &);
	string isbn() const { return bookNo; }   //����isbn�����е������붨�壬�䷵�ض�Ӧ��bookNo
	Sales_data& combine(const Sales_data&);  //����combine�����е����������ڽ������е��������������ֵ���
	double avg_price() const;                //����avg_price�����е����������ڼ���ĳ���е���Ʒ�۸�ƽ��ֵ
											 //���캯��������
	Sales_data &operator+=(const Sales_data &);
	Sales_data &operator=(const string &ISBN);
	explicit operator string() const { return bookNo; }
	explicit operator double() const { return avg_price(); }
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data &Sales_data::operator=(const string &ISBN)
{
	(*this).bookNo = ISBN;
	return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &temp)
{
	units_sold += temp.units_sold;
	revenue += temp.revenue;
	return *this;
}

istream& operator >> (std::istream &in, Sales_data &temp)
{
	double price = 0;
	in >> temp.bookNo >> temp.units_sold >> price;
	if (in)
		temp.revenue = price*temp.units_sold;
	else
		temp = Sales_data();
	return in;
}
ostream& operator<<(std::ostream &out, const Sales_data &temp)
{
	out << "��һ����ı��Ϊ��" << temp.isbn() << " ����Ϊ��" << temp.units_sold << " �ܼ�Ϊ��" << temp.revenue << " ƽ���۸�Ϊ��" << temp.avg_price() << endl;
	return out;
}
Sales_data operator+(const Sales_data&lhs, const Sales_data&rhs)
{
	Sales_data sum = lhs;
	sum = sum + rhs;
	return sum;
}

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