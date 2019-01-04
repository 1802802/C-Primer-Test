#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <forward_list>
#include <math.h>
using namespace std;

/*�ַ������һ�����ʵĳ���*/
void mainhw1()
{
	vector<string> save;
	string word;
	while (cin >> word)
		save.push_back(word);
	auto a = save.back().size();
	cout << a << endl;
}

/*�����ַ�����*/
void main2()
{
	char word;
	vector<char> save;
	while (cin >> word)
		save.push_back(word);
	int num = 0;
	auto a = save.back();
	for (auto &s : save)
	{
		if (s == a||s+32==a||s-32==a)
			num++;
	}
	cout << num - 1 << endl;
}

/*�����������*/
int mainhw3_1()  //��סҪ���������ݣ��ⲿn����������ѭ��
{
	int n, num;
	while (cin >> n)
	{
		vector<int> save;  //save�Ķ�����ѭ���ڲ�����֤ÿ�μ����µ�����ʱ���Ϊ��
		while (n--)
		{
			cin >> num;
			save.push_back(num);
		}
		sort(save.begin(), save.end());
		auto temp = unique(save.begin(), save.end());
		save.erase(temp, save.end());
		for (auto &s : save)
			cout << s << endl;
	}
	return 0;
}

int mainhw3_2()
{
	int n, num;
	while (cin >> n)
	{
		int a[1001] = { 0 };
		while (n--)
		{
			cin >> num;
			a[num] = 1;
		}
		for (int i = 0; i<1001; i++)
		{
			if (a[i])
				cout << i << endl;
		}
	}
	return 0;
}

/*�ַ����ָ�*/
int mainhw4()
{
	string input;
	while (cin >> input)
	{
		string in = input;
		auto l = in.size() / 8;
		int len = l * 8;
		for (int i = 0; i < len; i++)
		{
			cout << in[i];
			if ((i+1) % 8 == 0 && i != 0)
				cout << endl;
		}
		if ((in.size() % 8)>0)
		{
			int n = 0;
			for (int i = len; i<in.size(); i++, n++)
				cout << in[i];
			for (int i = n; i < 8; i++)
				cout << 0;
			cout << endl;
		}
	}
	return 0;
}

/*����ת��*/
int mainhw5()
{
	string in;
	string sixty;
	while (cin >> in)
	{
		int sum = 0;
		sixty = in;
		string sixtoten;
		int len = sixty.size(), n = 0;
		for (int i = len - 1; i > 1; i--, n++)
		{
			switch (sixty[i])
			{
			case 'A':sum += (10 * (pow(16, n))); break;
			case 'B':sum += (11 * (pow(16, n))); break;
			case 'C':sum += (12 * (pow(16, n))); break;
			case 'D':sum += (13 * (pow(16, n))); break;
			case 'E':sum += (14 * (pow(16, n))); break;
			case 'F':sum += (15 * (pow(16, n))); break;
			default:sum += (sixty[i] - '0') * (pow(16, n));  break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

/*��������*/
int mainhw6()
{
	long a;
	cin >> a;
	for (int i = 2; i <= a;)
	{
		if (a%i == 0)
		{
			cout << i << " ";
			a = a / i;
		}
		else
			i++;
	}
	cout << endl;
	return 0;
}

/*ȡ����ֵ*/
int mainhw7()
{
	double a;
	cin >> a;
	int b = a + 0.5;
	cout << b << endl;
	return 0;
}

/*�ϲ����¼*/
int mainhw8()
{
	map<int, int> save;
	int n;
	cin >> n;
	while (n--)
	{
		int key = 0, value = 0;
		cin >> key >> value;
		if (!save[key])
			save[key] = value;
		else
			save[key] += value;
	}
	for (auto &s : save)
		cout << s.first << " " << s.second << endl;
	return 0;
}

/**/
int mainhw9()
{
	vector<char> save, b;
	char n;
	while (cin >> n)
		save.push_back(n);
	int len = save.size();
	for (int i = len - 1; i >= 0; i--)
	{
		int num = 0;
		for (auto &s : b)
		{
			if (s == save[i])
				num++;
		}
		if (num == 0)
			cout << (save[i]-'0');
		b.push_back(save[i]);
	}
	cout << endl;
	return 0;
}

int mainhw10()
{
	char a;
	set<char> save;
	while (cin >> a)
	{
		if (a >= 0 && a<128)
			save.insert(a);
	}
	cout << save.size() << endl;
	return 0;
}

int mainhw11()
{
	char n;
	string s;
	list<string> save;
	while (getline(cin, s))
		save.push_back(s);
	for (auto &t1 : save)
		for (auto &t2 : t1)
			cout << t2;
	return 0;
}

int mainhw12()
{
	vector<string> save;
	string a;
	while (cin >> a)
		save.push_back(a);
	for (auto &s : save)
	{
		if (s.size() <= 8)
		{
			cout << "NG_SIZE" << endl;
			continue;
		}
		bool flag = false;
		for (int i = 0; i <= s.size() - 6; i++)
			for (int j = i + 3; j <= s.size() - 3; j++)
			{
				if (s[i] == s[j] && s[i + 1] == s[j + 1] && s[i + 2] == s[j + 2])
					flag = true;
			}
		if (flag)
		{
			cout << "NG_SAME" << endl;
			continue;
		}
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		for (auto &t : s)
		{
			if (t >= 'A'&&t <= 'Z')
				sum1 = 1;
			if (t >= 'a'&&t <= 'z')
				sum2 = 1;
			if (t >= '0'&&t <= '9')
				sum3 = 1;
			if (t >= 0 && t <= 127)
				sum4 = 1;
		}
		if (sum1 + sum2 + sum3 + sum4 >= 3)
			cout << "OK" << endl;
		else
			cout << "NG_ITEM" << endl;
	}
	return 0;
}

int mainhw13()
{
	string b;
	while (cin >> b)
	{
		map<char, int> m;
		vector<char> save;
		vector<char> remo;
		for (auto &a : b)
		{
			save.push_back(a);
			m[a]++;
		}
		int min = m.size();
		for (auto &s : m)
			if (s.second<min)
				min = s.second;
		for (auto &s : m)
			if (s.second == min)
				remo.push_back(s.first);
		for (auto &s1 : save)
		{
			bool flag = true;
			for (auto &s2 : remo)
			{
				if (s2 == s1)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cout << s1;
		}
		cout << endl;
	}
	return 0;
}

int mainhw14()
{
	vector<int> save;
	int a, b; int sum = 0;
	cin >> a;
	while (cin >> b)
		save.push_back(b);
	auto beg = save.begin();
	auto aft = save.begin() + 1;
	while (aft != save.end())
	{
		if (*beg >= *aft)
		{
			aft = aft + 1;
			sum++;
		}
		else
		{
			beg = aft;
			aft = aft + 1;
		}
	}
	cout << sum << endl;
	return 0;
}

int mainhw15()
{
	int n;
	while (cin >> n)
	{
		string a, b;
		int sum = 0;
		for (int i = 0; i<n; i++)
		{
			a = to_string(i*i);
			b = to_string(i);
			if (a.substr(a.size() - b.size()) == b)
				sum++;
		}
		cout << sum << endl;
	}
	return 0;
}

int mainhw16()
{
	string a;
	while (getline(cin, a))
	{
		vector<char> s;
		for (int i = 0; i<26; i++)
			for (int j = 0; j<a.size(); j++)
				if (a[j] - 'a' == i || a[j] - 'A' == i)
					s.push_back(a[j]);
		for (int i = 0, k = 0; i<a.size() && k<s.size(); i++)
			if ((a[i] >= 'a'&&a[i] <= 'z') || (a[i] >= 'A'&&a[i] <= 'Z'))
				a[i] = s[k++];
		cout << a << endl;
	}
	return 0;
}

int mainhw17()
{
	list<string> a;
	string b;
	while (cin >> b)
		a.push_front(b);
	for (auto &s1 : a)
	{
		bool flag = false;
		for (auto &s2 : s1)
		{
			if (s2 >= 'a'&&s2 <= 'z' || s2 >= 'A'&&s2 <= 'Z')
			{
				cout << s2;
				flag = true;
			}
		}
		if (flag)
			cout << " ";
	}
	cout << endl;
	return 0;
}
//AB %C ^ CBA% A

int mainhw18()
{
	string a;
	while (getline(cin, a))
	{
		list<string> save;
		string b = "";
		for (auto &s : a)
		{
			if (s >= 'a'&&s <= 'z' || s >= 'A'&&s <= 'Z')
				b.push_back(s);
			else
				if (b.size() > 0)
				{
					save.push_front(b);
					b = "";
				}
		}
		if (b.size() > 0)
			save.push_front(b);
		int sum = 0;
		for (auto &s : save)
		{
			cout << s;
			if (sum != save.size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}

int mainhw19()
{
	string str;
	while (getline(cin, str))
	{
		vector<string>svec;
		svec.clear();
		string temp = "";
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
				temp += str[i];
			else
			{
				if (temp.size()>0)
				{
					svec.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp.size()>0)
			svec.push_back(temp);
		for (int i = svec.size() - 1; i>0; --i)
			cout << svec[i] << ' ';
		cout << svec[0] << endl;
	}
	return 0;
}

int mainhw20()
{
	char a;
	vector<char> b;
	while (cin >> a)
		b.push_back(a);
	//for(int i=0;i<b.size();i++)
	// {
	//    for(int j=i;j<b.size();j++)
	//   {
	//       if()
	//  }
	//  }
	sort(b.begin(), b.end());
	for (auto &s : b)
		cout << s;
	cout << endl;
	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int w[10] = { 0 }, x[10] = { 0 };
		int in;
		for (int i = 0; i < n; i++)
		{
			cin >> in;
			w[i] = in;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> in;
			x[i] = in;
		}
		for (int i = 0; i < 10; i++)
			cout << w[i] << " " << x[i] << endl;
	}
}