#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

/*������1*/
class A
{
public:
	virtual void print(void)
	{
		cout << "A::print()" << endl;
	}
};

class B :public A
{
public:
	virtual void print(void)
	{
		cout << "B::print()" << endl;
	}
};

class C:public B
{
public:
	virtual void print(void)
	{
		cout << "C::print()" << endl;
	}
};

void print(A a)
{
	a.print();
}

int main1()
{
	A a, *pa, *pb, *pc;
	B b;
	C c;
	pa = &a;
	pb = &b;
	pc = &c;
	cout << endl;
	a.print();
	b.print();
	c.print();
	cout << endl;
	pa->print();
	pb->print();
	pc->print();
	cout << endl;
	print(a);
	print(b);
	print(c);

	return 0;
}

/*������2*/
int sum(int a)
{
	int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a + b + c);
}

int main2()
{
	int a = 3;
	for (int i = 0; i < 5; i++)
		cout << sum(a) << endl;
	return 0;
}

/*������3*/
class Base1
{
public:
	Base1(int i) { cout << "Constructing Base1 " << i << endl; }
	virtual ~Base1() { cout << "Destructing Base1" << endl; }
};

class Base2
{
public:
	Base2(int j) { cout << "Constructing Base2 " << j << endl; }
	virtual ~Base2() { cout << "Destructing Base2" << endl; }
};

class Derived :public Base2, public Base1
{
public:
	Derived(int a, int b, int c, int d) :Base1(a), member2(d), member1(c), Base2(b) { cout << "Constructing Derived" << endl; }
	~Derived() { cout << "Destructing Derived" << endl; }
private:
	Base1 member1;
	Base2 member2;
};

int main3()
{
	Derived *p = new Derived{ 1,2,3,4 };
	delete p;
	return 0;
}

/*������4*/
int main4()
{
	char s[] = "abccda";
	char c;
	for (int i = 1; (c = s[i]) != '\0'; i++)
	{
		switch (c)
		{
		case 'a':
			cout << "%";
			continue;
		case 'b':
			cout << "$";
		case 'c':
			cout << "*";
			break;
		case 'd':
			continue;
		}
		cout << "#" << endl;
	}
	return 0;
}

/*������5*/
class Base
{
private:
	char* name;
public:
	Base(char* className)  //Ĭ�Ϲ��캯��
	{
		name = new char[strlen(className) + 1];
		strcpy(name, className);
	}
	//~Base() { delete name; }
	~Base() { cout << "������������" << endl; }   //����Ϊԭ����������ɾ���˲���ɾ���ĳ�Աname���䲢���Ƕ�̬�ڴ棬��ȥ��ɾ��������
	char* copyName()
	{
		//char newname[256];
		char* newname = new char[256];    //�޸ĺ���䣬ԭ��Ϊ�ϣ�û�������ڴ�洢���ݣ��޸�Ϊnew�洢
		strcpy(newname, name);
		return newname;
	}
	char* getName() { return name; }
	static void print(Base base)
	{
		printf("name: %s\n", base.name);
	}
};

class Subclass :public Base
{
public:
	Subclass(char* className) :Base(className) {}
};

int main5()
{
	Base* pBase = new Subclass("text");
	pBase->getName()[2] = 'X';
	cout << pBase->getName() << endl;  //char *��������飬ʹ�����±�ֻ�ܷ��ʣ������޷���ֵ��char[]���͵ļȿ��Է��ʣ�Ҳ���Ը�ֵ
	char *a = "word";				   //���ǲ���һ�Ŷ��ۣ���ΪVS��������ǿ�󣬶��ڴ������Ѿ��½��ڴ��char*���͵��±�Ҳ�ǿ��Ը�ֵ��
	char b[] = "word";
	char c[10] = "word";
	char d = 'word';
	//a[2] = 'X';    //��������£��˲����޷����У���Ϊ��ʱ�����ݴ洢���ı������޷���ֵ
	b[2] = 'X';
	cout << a << b << c << d << endl;
	Base::print(*pBase);  //��������������������(��Ϊ�൱��ֱ�ӵ����˻��࣬���Դ�ʱϵͳ��Ϊ�˻����Ѿ�ʹ����ϣ�)
	printf("name: %s\n", pBase->getName());  
	printf("name: %s\n", pBase->copyName());
	return 0;
}

/*2015������1*/
int main6()
{
	int a[7] = { 1,5,2,3,4,1,2 };
	for (int i = 0; i<7; i++)
	{
		switch (a[i])
		{
		case 1:
			cout << "%";
			continue;
		case 2:
			cout << "$";
		case 3:
			cout << "*";
			break;
		case 4:
			continue;
		}
		cout << "#" << endl;
	}
	return 0;
}
