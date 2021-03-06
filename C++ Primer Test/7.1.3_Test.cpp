/*#include <iostream>
#include <string>
using namespace std;

struct Sales_data  //练习7.6与7.7  //练习7.11
{
	//构造函数
	Sales_data() = default;
	Sales_data(const string &s):bookNo(s),units_sold(0),revenue(0){}
	Sales_data(istream &);
	//构造函数即以上
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn() const { return bookNo; }   //函数isbn在类中的声明与定义，其返回对应的bookNo
	Sales_data& combine(const Sales_data&);  //函数combine在类中的声明，用于将括号中的类与其主类的数值相加
	double avg_price() const;                //函数avg）price在类中的声明，用于计算某类中的商品价格平均值
};

Sales_data add(const Sales_data&lhs, const Sales_data&rhs)  //非类成员函数add的定义，用于将二类中的数据加入一类中，然后返回一类的值
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream&os, const Sales_data&item)  //非类成员函数print的定义，用于输出某类中的isbn号（bookNo）,单价，总价以及平均价格
{
	os << "上一批书的编号为：" << item.isbn() << " 销量为：" << item.units_sold << " 总价为：" << item.revenue << " 平均价格为：" << item.avg_price() << endl;
	return os;
}

istream &read(istream&is, Sales_data&item)  //非类成员函数read的定义，用于将输入流中的编号，销量，单价，并计算出总价，然后返回数据到类中
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

Sales_data::Sales_data(istream &is)  //istream为参数的构造函数
{
	read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) //类成员函数combine的定义，其类型为Sales_data的类类型
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const  //成员函数avg_price的定义，其类型为double的数据类型，返回值直接为商品单价
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main()
{
	Sales_data total;
	if (read(cin,total))
	{
		Sales_data add;
		while (read(cin,add))
		{
			if (add.isbn()== total.isbn())
			{
				total.combine(add);      //调用total类的函数中的combine函数，返回值this返回打total的成员函数中
			}
			else
			{
				print(cout,total);
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