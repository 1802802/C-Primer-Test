/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <istream>
using namespace std;

class IFE    //��ϰ14.34
{
public:
	int &operator()(bool a, int b, int c) { return a ? b : c; }
private:
	bool condition;
	string yes;
	string no;
};

class PrintString  //��ϰ14.35��14.36
{
public:
	PrintString(istream &i = cin) :in(i){}
	string operator()() const
	{
		string temp;
		getline(in, temp);
		return in ? temp : string();
	}
private:
	istream &in;
};

class EQ   //��ϰ14.37
{
public:
	//EQ() { cout << "�޲ι��캯��" << endl; }
	EQ(int a = 0, int b = 0) :num1(a), num2(b) { cout << "Ĭ�Ϲ��캯��" << endl; }
	EQ(int &a, int&b) :num1(a), num2(b) { cout << "�������Ĺ��캯��" << endl; }
	bool operator()(int a, int b) const { return (a == b); }
private:
	int num1 = 0;
	int num2 = 0;
};

int main()
{
	PrintString a;
	cout << a() << endl;
	vector<string> b;
	for (std::string tmp; !(tmp = a()).empty();) b.push_back(tmp);
	for (auto &s : b)
		cout << s << endl;
	int ob_num = 1;
	int cg_num = 3;
	EQ change;
	vector<int> place{ 1,2,3,4,4,2,1,13,5 };
	cout << "before:";
	for (auto &s : place)
	{
		cout << s << " ";
		if (change(s, ob_num))
			s = cg_num;
	}
	cout << endl;
	cout << "after:";
	for (auto &s : place)
		cout << s << " ";
	cout << endl;
	return 0;
}*/

//���������ʱ
//i)���� ��������Ĭ�ϵ��á�������()��������캯������ջ�ڴ��д��ڶ��������ڶ��ڴ��д���ʵ�ʶ���

//ii)���� ������(һ�������ϸ�����)��Ĭ�ϵ�����Ӧ�Ĺ��캯������ջ�ڴ��д��ڶ��������ڶ��ڴ���Ҳ�Ǵ���ʵ�ʶ���ģ�

//iii)���� ������()���������κι��캯���������󣬽���ջ�����д��ڶ��������ڶ��ڴ��в�������ʵ�ʵĶ���