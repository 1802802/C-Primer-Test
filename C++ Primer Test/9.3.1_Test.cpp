/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //��ϰ9.18
{
	string word;
	deque<string> text;
	while (cin >> word)
		text.push_back(word);
	for (auto beg = text.begin(), end = text.end(); beg != end; ++beg)
		cout << *beg << endl;
	return 0;
}*/

/*int main()  //��ϰ9.19
{
	string word;
	list<string> text;
	while (cin >> word)
		text.push_back(word);
	for (auto beg = text.begin(), end = text.end(); beg != end; ++beg)
		cout << *beg << endl;
	return 0;
}*/

/*int main()  //��ϰ9.20
{
	list<int> a{ 1,2,3,4,5 };
	deque<int> even;
	deque<int> odd;
	for (auto &s : a)
	{
		if (s % 2 == 0)
			even.push_back(s);
		else
			odd.push_back(s);
	}
	for (auto &s1 : even)
	{
		cout << "even is ";
		cout << s1 << endl;
	}
	for (auto &s2 : odd)
	{
		cout << "odd is ";
		cout << s2 << endl;
	}
	return 0;
}*/

/*void insertDoubleValue(vector<int>& iv, int some_val)  
{
	auto cursor = iv.size() / 2;
	auto iter = iv.begin(), mid = iv.begin() + cursor;
	while (iter != mid)
	{
		if (*iter == some_val) 
		{
			iter = iv.insert(iter, 2 * some_val);
			++iter;
			++cursor;
			mid = iv.begin() + cursor;  //���¶���midΪiv���м�������Ϊ�Ѿ�������һ������
		}
		++iter;
	}
}

void print(const vector<int>& iv)
{
	for (auto i : iv) std::cout << i << " ";
	std::cout << std::endl;
}

int main()   //��ϰ9.22
{
	vector<int> iv = { 1, 7, 1, 1, 1, 7, 1, 9 };  //ֻ��ǰ�벿����Ч
	insertDoubleValue(iv, 1);
	print(iv);
}*/