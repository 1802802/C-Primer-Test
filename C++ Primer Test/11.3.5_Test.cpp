/*#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main1()  //��ϰ11.28
{
	vector<int> a1{ 1,2,3 };
	vector<int> a2{ 1,2,3 };
	vector<int> a3{ 1,2,3 };
	map<string, vector<int>> temp{ { "mike",a1 }, { "jack",a2 } ,{ "diny",a3 } };
	auto a = temp.find("jack");
	for (auto &s : a->second)
		cout << a->first << " " << s << endl;
	return 0;
}

int main2()  //��ϰ11.31��11.32
{
	multimap<string, string> lib{ {"lpc","talk and show"},{"wzz","study better"} ,{ "lpc","for fun" } };
	for (auto &s : lib)
		cout << "initial: " << s.first << " " << s.second << endl;
	auto temp = lib.find("lpc");  //find���ҵľ�Ϊ�ؼ��ʣ�����ֻ���ص�һ������Ҫ��ĵ�����
	if (temp != lib.end())
	{
		lib.erase(temp);
		cout << "erase success!" << endl;
	}
	else
		cout << "not find!" << endl;
	for (auto &s : lib)
		cout << "after: " << s.first << " " << s.second << endl;
	return 0;
}*/