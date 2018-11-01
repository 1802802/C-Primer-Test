/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>  
#include <map>
using namespace std;

class Str_EQ
{
public:
	Str_EQ() {}
	Str_EQ(int &temp) :limit(temp) {}
	bool operator()(const string &temp) const { return temp.size() == limit; }
private:
	size_t limit;
};

int main1()   //��ϰ14.38
{
	ifstream in("input_line.txt");
	string word;
	vector<string> save;
	while (in >> word)
		save.push_back(word);
	for (int n = 1; n <= 10; ++n)
	{
		Str_EQ eq(n);
		int add = 0;
		for (auto &s : save)
		{
			if (eq(s))
				++add;
		}
		cout << "���ȵ��� " << n << " ���ַ��� " << add << " ��" << endl;
	}
	return 0;
}

int main2()   //��ϰ14.39  //�����������׳���������޸�
{
	ifstream in("input_line.txt");
	string word;
	vector<string> save;
	while (in >> word)
		save.push_back(word);
	int add1 = 0, add2 = 0;
	for (int n = 1; n <= 9; ++n)
	{
		Str_EQ eq(n);
		for(auto &s :save)
		{
			if (eq(s))
				++add1;
		}
	}
	cout << "���ȵ���1��9���ַ��� " << add1 << " ��" << endl;
	for (int n = 10; n <= 100; ++n)
	{
		Str_EQ eq(n);
		for (auto &s : save)
		{
			if (eq(s))
				++add2;
		}
	}
	cout << "���ȴ���10���ַ��� " << add2 << " ��" << endl;
	return 0;
}

int main3()  //��ϰ14.39  //�������ʹ��map�洢�������޸�
{
	ifstream in("input_line.txt");
	string word;
	map<size_t, size_t> save;
	while (in >> word)
	{
		auto ret = save.insert({ word.size(),1 });
		if (!ret.second)
			++ret.first->second;
	}
	size_t add1 = 0, add2 = 0;
	for (auto &s : save)
	{
		if (s.first < 10)
			add1 += s.second;
		else
			add2 += s.second;
	}
	cout << "���ȵ���1��9���ַ��� " << add1 << endl;
	cout << "���ȴ���10���ַ��� " << add2 << endl;
	return 0;
}

void doit(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto temp = unique(word.begin(), word.end());  //temp��ʱΪ������
	word.erase(temp, word.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	doit(words);  //words�������ַ�����ĸ˳�����򣬲�ɾ���ظ��ĵ���
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //�����������ֵ���
	auto wc = find_if(words.begin(), words.end(), SizeComp(sz));  //���ҵ�һ��������������
	auto count = words.end() - wc;  //��������������Ԫ�ظ���
	cout << "����������Ԫ�ظ���Ϊ��" << count << endl;
	for_each(wc, words.end(), [](const string &s) {cout << "����������Ԫ��Ϊ��" << s << " "; });
	cout << endl;
}

class SizeComp
{
	friend void biggies(vector<string> &words, vector<string>::size_type sz);
public:
	SizeComp(size_t n):sz(n){}
	bool operator()(const string &s) const { return s.size() > sz; }
private:
	size_t sz;
};*/