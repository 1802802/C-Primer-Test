#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <memory>
using namespace std;

int main_shuixianhua_1() //Ч����Ϊ���£���Ҫѭ��900��  ʱ�临�Ӷ�n�����η�
{
	for (int a= 1; a != 10; ++a)
	{
		for (int b = 0; b != 10; ++b)
		{
			for (int c = 0; c != 10; ++c)
			{
				int sum = a * 100 + b * 10 + c;
				if (sum == (a*a*a) + (b*b*b) + (c*c*c))
					cout << "ˮ�ɻ���Ϊ��" << a << b << c << endl;
			}
		}
	}
	return 0;
}

int main_shuixianhua_2()
{
	for (int i = 100; i < 1000; i++)
	{
		int a = i / 100;
		int b = i % 100 / 10;
		int c = i % 100 % 10;
		int sum = a * 100 + b * 10 + c;
		if (sum == (a*a*a) + (b*b*b) + (c*c*c))
			cout << "ˮ�ɻ���Ϊ��" << a << b << c << endl;
	}
	return 0;
}


//���Ƕ�֪����C++����������»���ÿ������캯�����������©������һ������Ǻ�����ʵ���ʱ���ڶ�������Ǻ�������ʱ��
//����ջ���Ķ���Ḵ��һ�ݵ������ķ���ȥ���������������һ�������ʼ����һ������ʱҲ����ÿ������캯����

//��������������»���ÿ������캯�������������һ������ֵ����һ���������ʱ��ص������صĸ�ֵ�����������
//���������ƶ����캯���󣬿������캯��������������������ֵ��ֵ��ȷ�����ÿ������캯�������ƶ����캯��