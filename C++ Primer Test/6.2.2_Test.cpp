/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret)i = 0; i != s.size(); i++)
	{
		if (s[i] == c)
		{
			if(ret==s.size())
				ret = i;
			occurs++;
		}
	}
	return ret;
}

int main()
{
	string s = ( "my name is yzt" );
	char c = 'y';
	string::size_type ctr;
	auto index = find_char(s, c, ctr);
	if (ctr == 0)
		cout << "�ַ�" << c << "û���ڸ��ַ����г��ֹ�" << endl;
	else
	{ 
		cout << "ԭ�ַ���Ϊ��" << s << endl << "�ַ�" << c << "��һ�γ������ַ����ĵ�" << index + 1
			<< "λ��" << "�乲����" << ctr << "�Ρ�" << endl;
	}
	return 0;
}*/