/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class numbered1
{
public:
	numbered1()  //Ĭ�Ϲ��캯���Ķ���
	{
		static int temp = 10;  //static ȫ�־�̬��������֤�ڳ�ʼ��һ����ֵ����һ����ʼ����ʼʱtemp�����ᱻ��ʼ��
		mysn = temp++;
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	int mysn;  //��Աmysn�Ķ���
};

void f(numbered1 s)
{
	cout << s.mysn << endl;
}

int main1()  //��ϰ13.14   ���еĹ��캯����ΪĬ�ϵĺϳɹ��캯���������俽��Ϊ�򵥿���������ʹ��ֵ��������
{
	numbered1 a, b = a, c = b;
	numbered1 d, e;
	cout << a.mysn << d.mysn << e.mysn << endl;   //����Ĭ�Ϲ��캯�������d��e����ִ���˵�������
	f(a); f(b); f(c);
	return 0;
}
//ȫ��ֻ���ʼ������a��һ��Ĭ�Ϲ��캯����Ȼ�����b��c����ֱ�ӵļ򵥿������������յõ��Ľ��Ϊ����10


class numbered2
{
public:
	numbered2()  //Ĭ�Ϲ��캯���Ķ���
	{
		static int temp = 10;
		mysn = temp++;
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	numbered2(const numbered2 &temp)   //�������캯���Ķ���
	{
		mysn = temp.mysn + 1;  //�ڿ���֮����ֵ��������������Ǽ򵥵ĸ�ֵ����
		cout << "�������캯��" << endl;
	}
	int mysn;  //��Աmysn�Ķ���
};

void f(numbered2 s)
{
	cout << s.mysn << endl;
}

int main2()  //��ϰ13.15
{
	numbered2 a, b = a, c = b;  //�ڽ��б����Ŀ�����ʼ��ʱ������ʹ�õ��ǿ������캯����������ֵ�����ֻ���������������Ѿ������ʼ������Ż����
	//b = a; //��������ͻ���ÿ�����ֵ������������ǿ������캯�����������캯�����ڳ�ʼ��������ʼ��ҳ���������β�ʵ�μ��ת����
	cout << a.mysn << b.mysn << c.mysn << endl;  //�˴����ڲ鿴��һ�γ�ʼ��֮��abc����ֵ
	f(a); f(b); f(c);
	return 0;
}
//�ڶ�a���и�ֵ������һ��Ĭ�Ϲ��캯������b��c���Ķ���Ҳ��Ϊ������Ŀ������캯�������Դ�ʱaΪ10��bΪ11��cΪ12��
//�ڵ���f����ʱ�����ε��þ���ʵ�����β�֮���ת������Ҳ���������ο������캯����ÿ����Ӧ����ֵ����+1������aΪ11��bΪ12��cΪ13

class numbered3
{
public:
	numbered3()  //Ĭ�Ϲ��캯���Ķ���
	{
		static int temp = 10;
		mysn = temp++;
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	numbered3(const numbered3 &temp)   //�������캯���Ķ���
	{
		mysn = temp.mysn + 1;  //�ڿ���֮����ֵ��������������Ǽ򵥵ĸ�ֵ����
		cout << "�������캯��" << endl;
	}
	int mysn;  //��Աmysn�Ķ���
};

void f(const numbered3 &s)  //�˴�����Ϊconst�����á��������ں�����ʵ���β�ת�������ÿ������캯��ʱ���޷����е�������
{
	cout << s.mysn << endl;
}

int main3()  //��ϰ13.15
{
	numbered3 a, b = a, c = b;
	cout << a.mysn << b.mysn << c.mysn << endl;
	f(a); f(b); f(c);  //���ս���޷��ڵ��ú���ʱ���Լ�1������Ϊ10��11��12
	return 0;
}*/