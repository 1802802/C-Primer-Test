/*#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
using namespace std;

/*int main()  //��ϰ9.47
{
	string a{ "ab2c3d7R4E6" };
	string num{ "0123456789" };
	auto pos = 0;
	while ((pos = a.find_first_of(num, pos)) != string::npos)
	{
		cout << "�ڵ� " << pos << " ��λ���ҵ����� " << a[pos] << endl;
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = a.find_first_not_of(num, pos)) != string::npos)
	{
		cout << "�ڵ� " << pos << " ��λ���ҵ���ĸ " << a[pos] << endl;
		++pos;
	}
	return 0;
}*/

/*int main()  //��ϰ9.49
{
	string word;
	auto pos1 = 0, pos2 = 0;
	string st{ "bdfhiklt" };
	string xt{ "jgpqy" };
	ifstream infile("wordinput.txt");
	while (infile >> word)         //�������뵥��
	{
		cout << "ԭ����Ϊ��" << word << endl;
		while ((pos1 = word.find_first_of(st, pos1)) != string::npos)  //ɾ���ϳ�ͷ��ĸ
			word.erase(pos1, 1);
		pos1 = 0;
		while ((pos2 = word.find_first_of(xt, pos2)) != string::npos)  //ɾ���³�ͷ��ĸ
			word.erase(pos2, 1);
		pos2 = 0;
		cout << "�ֵ���Ϊ��" << word << endl;
	}
	return 0;
}*/