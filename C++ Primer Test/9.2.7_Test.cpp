/*#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
using namespace std;

bool com(vector<int> v1, vector<int> v2)
{
	if (v1 == v2)
		return true;
	else
		return false;
}

auto com2(list<int> v1, vector<int> v2)
{
	vector<int> temp(v1.begin(), v1.end());
	if(temp==v2)
		return true;
	else
		return false;
}

int main()
{
	vector<int> a{ 1,2,3,4 };
	vector<int> b{ 1,2,3,4 };
	list<int> c{ 1,2,3 };
	if (com(a, b))   //��ϰ9.15
		cout << "���������" << endl;
	else
		cout << "�����������" << endl;

	if (com2(c, b))   //��ϰ9.16
		cout << "���������" << endl;
	else
		cout << "�����������" << endl;
}*/