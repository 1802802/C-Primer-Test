/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int f1(int a, int b)
{
	int c = a + b;
	return c;
}

int f2(int a, int b)
{
	int c = a - b;
	return c;
}

int f3(int a, int b)
{
	int c = a * b;
	return c;
}

int f4(int a, int b)
{
	int c = a / b;
	if (b == 0)
		return 0;
	else
		return c;
}
/*int main()   //��ϰ6.54
{
	typedef int(*fun1)(int a, int b);
	typedef decltype(f1) *fun2;
	vector<fun1> a;
	return 0;
}*/

/*int main()  //��ϰ6.55��6.56
{
	typedef decltype(f1) *fun2;
	vector<fun2> a { f1,f2,f3,f4 };  //���������뵥������ʱĬ��Ϊָ��
	for (auto f : a)   //ָ������ָ���ڵ���ʱ��������ã�ֱ��ʹ�ú���������
		cout << f(5, 2) << endl;
	return 0;
}*/