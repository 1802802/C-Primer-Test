//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <istream>
//using namespace std;
//
//class Quote
//{
//public:
//	Quote() = default;
//	Quote(const string &book,double sales_price):bookNo(book),price(sales_price){}
//	string isbn() const { return bookNo; }
//	//���ظ����������鼮�������ܶ���������д�˺������ڲ�ͬ�ۿ۵��㷨��
//	virtual double net_price(size_t n) const { return n*price; }
//	virtual ~Quote() = default;  //�������������ж�̬��
//private:
//	string bookNo;   //���ISBN���
//protected:
//	double price = 0.0;    //����״̬�£������۵ļ۸��ʼ��
//};
//
////���㲢��ӡ���۸���������ĳ���鼮���õķ���
//double print_total(ostream &os, const Quote &item, size_t n)
//{
//	double ret = item.net_price(n);
//	os << "ISBN: " << item.isbn() << " # solid: " << n << " total due: " << ret << endl;
//	return ret;
//}