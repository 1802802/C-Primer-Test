/*#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <iterator>
using namespace std;

/*int main()   //��ϰ9.27
{
	forward_list<int> flst{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
		if (*curr % 2)
			curr = flst.erase_after(prev);  //ɾ��prev֮���Ԫ�أ���curr�������б�����ָ��Ԫ�أ�ɾ��֮��֮��Ԫ�صĵ�������ֵ��curr�У�
		else                                //ͬʱ������curr��Ԫ�ر�ɾ����������֮���Ԫ���Զ���䣬curr�������Դ���prev������֮��
		{
			prev = curr;  //��curr��������ֵ����prev�У�ʹ��ǰ��һ��
			curr++;  //curr��������ǰ��һ��
		}
	for (auto &s : flst)
	{
		cout << "�����е�ż��Ϊ��";
		cout << s << endl;
	}
}*/

/*void find(forward_list<string> &a, string b, string c)  //����ı�a����ֵ���������ø�ʽ
{
	auto it1 = a.before_begin();
	auto it2 = a.begin();
	bool tm = false;
	for (; it2 != a.end(); it1 = it2++)  //����forward_list��ѭ����ʽ���������ڵĵ�����������ǰ����  //��++��֤it2��Զ��it1��һλ
	{
		if (*it2 == b)
		{
			a.insert_after(it2, c);
			tm = true;
		}
	}
	if (!tm)
		a.insert_after(it1, c);
}

int main()  //��ϰ9.28
{
	forward_list<string> text{ "my","name","yzt" };
	string word1{ "name" };
	string word2{ "is" };
	find(text, word1, word2);
	for (auto &s : text)
		cout << s  <<" ";
	cout << endl;
}*/