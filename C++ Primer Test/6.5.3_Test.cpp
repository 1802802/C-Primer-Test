/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int a(int val)
{
#ifndef NDEBUG
	cout << "���������е�ֵ��Ϊ��" << val << endl;
#endif

		if (val > 1)
			return a(val - 1)*val;
	return 1;
}

int main()  //�׳˺���  ��ϰ6.33
{
	cout << a(5) << endl;
}*/