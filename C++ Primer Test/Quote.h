#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <istream>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }
	//���ظ����������鼮�������ܶ���������д�˺������ڲ�ͬ�ۿ۵��㷨��
	virtual double net_price(size_t n) const { return n*price; }
	virtual ~Quote() = default;  //�������������ж�̬��
	virtual void debug() { cout << "���ISBN���Ϊ�� " << bookNo << " ���ԭ��Ϊ�� " << price << endl; }
private:
	string bookNo;   //���ISBN���
protected:
	double price = 0.0;    //����״̬�£������۵ļ۸��ʼ��
};

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) {}
	double net_price(size_t n) const = 0;
protected:
	size_t min_qty = 0;   //�ۿ۵���͹�����
	double discount = 0.0;   //�ۿ۶��
};



class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	//��������Ĺ��캯��������Disc_quote�������
	Bulk_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
	//���ǻ����еļ۸���㺯���汾
	double net_price(size_t cnt) const override
	{
		if (cnt > min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
};

class Other_quote :public Disc_quote
{
public:
	Other_quote() = default;
	Other_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
	double net_price(size_t cnt) const override
	{
		if (cnt < min_qty)
			return cnt*(1 - discount)*price;
		else
			return (min_qty*(1 - discount)*price + (cnt - min_qty)*price);
	}
};

//���㲢��ӡ���۸���������ĳ���鼮���õķ���
double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # solid: " << n << " total due: " << ret << endl;
	return ret;
}
