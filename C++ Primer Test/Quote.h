#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <set>
#include <memory>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) { cout << "Quote�������캯��" << endl; }
	string isbn() const { return bookNo; }
	//���ظ����������鼮�������ܶ���������д�˺������ڲ�ͬ�ۿ۵��㷨��
	virtual double net_price(size_t n) const { return n*price; }

	Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {cout << "Quote�������캯��" << endl;}

	Quote& operator=(const Quote &rhs) 
	{
		cout << "Quote������ֵ�����" << endl;
		price = rhs.price;
		bookNo = rhs.bookNo;
		return *this;
	}

	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {cout << "Quote�ƶ����캯��" << endl;}

	Quote& operator=(Quote &&rhs) noexcept 
	{
		cout << "Quote�ƶ���ֵ�����" << endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move((*this))); }
	virtual ~Quote() { cout << "Quote��������" << endl; };  
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
	Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) { cout << "Disc_quote����Ĭ�Ϲ��캯��" << endl; }
	double net_price(size_t n) const = 0;
protected:
	size_t min_qty = 0;   //�ۿ۵���͹�����
	double discount = 0.0;   //�ۿ۶��
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	//��������Ĺ��캯��������Quote�������
	Bulk_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) { cout << "Bulk_quote����Ĭ�Ϲ��캯��" << endl; }
	Bulk_quote(const Bulk_quote &rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "Bulk_quote�������캯��" << endl; }

	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		cout << "Bulk_quote������ֵ�����" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}

	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) { cout << "Bulk_quote�ƶ����캯��" << endl; }

	Bulk_quote& operator=(Bulk_quote &&rhs) noexcept
	{
		cout << "Bulk_quote�ƶ���ֵ�����" << endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	virtual Bulk_quote* clone() && { return new Bulk_quote(std::move((*this))); }
	virtual ~Bulk_quote() { cout << "Bulk_quote��������" << endl; };

	//���ǻ����еļ۸���㺯���汾
	double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
protected:
	size_t min_qty = 0;   //�ۿ۵���͹�����
	double discount = 0.0;   //�ۿ۶��
};

class Other_quote : public Quote
{
public:
	Other_quote() = default;
	//��������Ĺ��캯��������Disc_quote�������
	Other_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), min_qty(qty), discount(disc) { cout << "Other_quote����Ĭ�Ϲ��캯��" << endl; }

	Other_quote(const Other_quote &rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) { cout << "Other_quote�������캯��" << endl; }

	Other_quote& operator=(const Other_quote &rhs)
	{
		cout << "Other_quote������ֵ�����" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}

	Other_quote(Other_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) { cout << "Other_quote�ƶ����캯��" << endl; }

	Other_quote& operator=(Other_quote &&rhs) noexcept
	{
		cout << "Other_quote�ƶ���ֵ�����" << endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual ~Other_quote() { cout << "Other_quote��������" << endl; };

	//���ǻ����еļ۸���㺯���汾
	double net_price(size_t cnt) const override
	{
		if (cnt <= min_qty)
			return cnt*(1 - discount)*price;
		else
			return (min_qty*(1 - discount)*price + (cnt - min_qty)*price);
	}
protected:
	size_t min_qty = 0;   //�ۿ۵���͹�����
	double discount = 0.0;   //�ۿ۶��
};

class Basket
{
public:
	void add_item(const Quote &sale) { items.insert(shared_ptr<Quote>(sale.clone())); }   //��ֵ���
	void add_item(Quote &&sale) { items.insert(shared_ptr<Quote>(std::move(sale.clone()))); }  //��ֵ���
	void add_item(const shared_ptr<Quote> &sale) { items.insert(sale); }    //����Ĺؼ����������sale���͵���Ӧ
	//void add_item(const Quote &sale) { items.insert (make_shared<Quote>(sale)); }
	double total_receipt(ostream &) const;
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

//���㲢��ӡ���۸���������ĳ���鼮���õķ���
double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # solid: " << n << " total due: " << ret << endl;
	return ret;
}

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
		sum += print_total(os, **iter, items.count(*iter));
	os << "�ܼ۸�Ϊ�� " << sum << endl;
	return sum;
}
