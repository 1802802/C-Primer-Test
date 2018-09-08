/*#include <iostream>
#include <numeric>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include <algorithm>
#include<functional>

using namespace std::placeholders;
using namespace std;

/*bool doit(const string &words)
{
	return words.size() <= 6;
}

int main()  //��ϰ10.22
{
	vector<string> word{ "i","can","fly!!!!!!","fly","on","the","sky" };
	auto temp = count_if(word.begin(), word.end(), doit);
	cout << temp << endl;
}*/

/*bool check_size(const string &s, const size_t sz)
{
	return s.size() > sz;
}

int main()  //��ϰ10.24
{
	string ex = "Time";
	vector<string> word{ "i","can","fly!!!!!!","fly","on","the","sky" };
	auto temp = find_if(word.begin(), word.end(), bind(check_size, _1, ex.size()));
	cout << *temp << endl;
}*/

/*bool check_size(const string &s, const size_t sz)
{
	return s.size() < sz;
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
				  //sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //��������(sort)���ֵ���(stable)
	auto wc = stable_partition(words.begin(), words.end(), bind(check_size,_1,sz));  //bind�����ع����룬����1��λ��2��λ���ݲ�������
	auto count = words.end() - wc;  //��������������Ԫ�ظ���												 
	cout << "����������Ԫ�ظ���Ϊ��" << count << endl;
	cout << "����������Ԫ��Ϊ��";
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()  //��ϰ10.25
{
	vector<string> word{ "i","can","fly!!!","fly","on","the","sky" };
	biggies(word, 3);   //�õ����д��ڻ����sz��������Ŀ
}*/