/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()  //��ϰ5.23��5.25
{
	int a, b;
	double c;
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("�ڶ���������Ϊ0");
			cout << 1.0*a / b << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\n�Ƿ���Ҫ��������? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') //!cin �� c=='n'
				break;
		}
	}
}*/