//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <algorithm>  
//#include <istream>
//#include <memory>
//#include <initializer_list>
//#include <tuple>
//#include "Sales_data.h"
//using namespace::std;
//
//bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() < rhs.isbn(); }
////��ϰ17.4
////typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
////vector<vector<Sales_data>> files;
////vector<matches> findBook(const vector<vector<Sales_data>> &files, string &book)
////{
////	vector<matches> ret;
////	//��ÿ����꣬����������鼮ƥ��ļ�¼��Χ
////	for (auto it = files.begin(); it != files.end(); ++it)
////	{
////		auto found = equal_range(it->cbegin(), it->end(), book, compareIsbn);
////		if (found.first != found.second)  //����������˸����鼮
////			//��ס������������ƥ�䷶Χ
////			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
////	}
////	return ret;
////}
//
////��ϰ17.5
//typedef pair<vector<Sales_data>::size_type,pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches;
//vector<vector<Sales_data>> files;
//vector<matches> findBook(const vector<vector<Sales_data>> &files, string &book)
//{
//	vector<matches> ret;
//	//��ÿ����꣬����������鼮ƥ��ļ�¼��Χ
//	for (auto it = files.begin(); it != files.end(); ++it)
//	{
//		auto found = equal_range(it->cbegin(), it->end(), book, compareIsbn);
//		if (found.first != found.second)  //����������˸����鼮
//										  //��ס������������ƥ�䷶Χ
//			ret.push_back({ it - files.cbegin(), {found.first, found.second} });
//	}
//	return ret;
//}