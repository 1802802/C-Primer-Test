/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*bool find(vector<int>::iterator a, vector<int>::iterator b,int c)   //��ϰ9.4
{
	while (a != b)  //������ѭ��
	{
		if (*a == c)
			return true;  //���ҵ�����ֱ�ӷ���true
		++a;
	}
	return false;  //������ѭ����δ�ҵ����򷵻�false��
}

int main()
{
	vector<int> word(10,1);
	int num = 1;
	if (find(word.begin(), word.end(), num))
		cout << "find the number " << num << " in the word" << endl;
	else
		cout << "don't find the number" << endl;
	return 0;
}*/

/*auto find(vector<int>::iterator a, vector<int>::iterator b, int c)   //��ϰ9.5
{
	while (a != b)  //������ѭ��
	{
		if (*a == c)
			return a;  //���ҵ�����ֱ�ӷ��ص�ǰ��������ֵ
		++a;
	}
	return a;  //������ѭ����δ�ҵ����򷵻ص�ǰ��������ֵ����ʱ����end����ͬ���ã���Ϊδ�ҵ���������ý������end��
}

int main()
{
	vector<int> word(10, 1);
	int num = 2;
	auto res = find(word.begin(), word.end(), num);
	if (res != word.end())
		cout << "find the number " << *res << " in the word" << endl;
	else
		cout << "don't find the number" << endl;
	return 0;
}*/