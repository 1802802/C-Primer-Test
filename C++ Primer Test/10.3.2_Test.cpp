//#include <iostream>
//#include <numeric>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <iterator>
//#include <list>
//#include <algorithm>
//using namespace std;

/*int main()
{
	int sz = 0;
	[](int &b,int &c) {cout << b + c; }; //��ϰ10.14
	[sz](int &b) {return sz + b; };  //��ϰ10.15
}*/

/*void doit(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto temp = unique(word.begin(), word.end());  //temp��ʱΪ������
	word.erase(temp, word.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	doit(words);  //words�������ַ�����ĸ˳�����򣬲�ɾ���ظ��ĵ���
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //�����������ֵ���
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });  //���ҵ�һ��������������
	auto count = words.end() - wc;  //��������������Ԫ�ظ���
	cout << "����������Ԫ�ظ���Ϊ��" << count << endl;
	for_each(wc, words.end(), [](const string &s) {cout << "����������Ԫ��Ϊ��" << s << " "; });
	cout << endl;
}

int main()  //��ϰ10.16
{
	vector<string> word{ "i","can","fly","on","the","sky!" };
	biggies(word,2);
}*/

/*class Sales_data
{
public:
	string isbn;
};

int main()  //��ϰ10.17
{
	Sales_data a, b, c, d;
	a.isbn = "me";
	b.isbn = "and";
	c.isbn = "world";
	d.isbn = "me";
	vector<Sales_data> save{ a,b,c,d };
	stable_sort(save.begin(), save.end(), [](const Sales_data &s1, const Sales_data &s2) {return s1.isbn.size() < s2.isbn.size(); });
	//ʹ��lambda�����˺�����ν��
	for (auto &s : save)
		cout << s.isbn << " ";
	cout << endl;
	return 0;
}*/

/*void doit(vector<string> &word)
{
sort(word.begin(), word.end());
auto temp = unique(word.begin(), word.end());  //temp��ʱΪ������
word.erase(temp, word.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	doit(words);  //words�������ַ�����ĸ˳�����򣬲�ɾ���ظ��ĵ���
	//sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });  //��������(sort)���ֵ���(stable)
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a) {return a.size() < sz; });  //���ж�������ת��ʹ�ò�����Ϊtrue
	auto count = words.end() - wc;  //��������������Ԫ�ظ���												 //stable������ַ��������ֵ���
	cout << "����������Ԫ�ظ���Ϊ��" << count << endl;
	cout << "����������Ԫ��Ϊ��";
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()  //��ϰ10.18
{
	vector<string> word{ "i","can","fly!!!","fly","on","the","sky" };
	biggies(word, 3);
}*/