//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//#include "Quote.h"
//using namespace std;
//
//int main()   //��ϰ15.28��15.29����ϰ15.30
//{
//	vector<Quote> save;
//	Bulk_quote bb1("Light", 100, 10, 0.25);
//	Bulk_quote bb2("Night", 75, 10, 0.25);
//	Bulk_quote bb3("Right", 50, 10, 0.25);
//	//save.push_back(bb1);
//	//save.push_back(bb2);
//	//save.push_back(bb3);
//	//for (auto &s : save)
//	//	print_total(cout, s, 15);   //���ȫ��ԭ�۳�����������Ϊ������Ĳ��ֱ��е��ˣ�ֻ��bookNo��price
//	//cout << endl;
//	//vector<shared_ptr<Quote>> save2;
//	//save2.push_back(make_shared<Bulk_quote>(bb1));
//	//save2.push_back(make_shared<Bulk_quote>(bb2));
//	//save2.push_back(make_shared<Bulk_quote>(bb3));
//	//for (auto &s : save2)
//	//	print_total(cout, *s, 15);   //�����ж���Ϊָ��bulk_quote���͵�ָ�룬���Ե���ʱ�ۿ�����
//
//	cout << endl;
//
//	Basket all;
//	for(int i=0;i<15;i++)
//		all.add_item(bb1);
//	all.add_item(bb1);
//	all.add_item(bb2);
//	all.add_item(bb3);
//	all.total_receipt(cout);
//}