//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//using namespace std;
//class B1
//{
//public:
//	B1()
//	{
//		cout << "B1���캯��" << endl;
//	}
//	virtual void print()
//	{
//		cout << "B1��ӡ����" << endl;
//	}
//	virtual ~B1()
//	{
//		cout << "B1��������" << endl;
//	}
//};
//class D1 :public B1
//{
//public:
//	D1()
//	{
//		cout << "D1���캯��" << endl;
//	}
//	void print()
//	{
//		cout << "D1��ӡ����" << endl;
//	}
//	~D1()
//	{
//		cout << "D1��������" << endl;
//	}
//};
//class B2
//{
//public:
//	B2()
//	{
//		cout << "B2���캯��" << endl;
//	}
//	virtual void print()
//	{
//		cout << "B2��ӡ����" << endl;
//	}
//	virtual ~B2()
//	{
//		cout << "B2��������" << endl;
//	}
//};
//class D2 :public B2
//{
//public:
//	D2()
//	{
//		cout << "D2���캯��" << endl;
//	}
//	void print()
//	{
//		cout << "D2��ӡ����" << endl;
//	}
//	~D2()
//	{
//		cout << "D2��������" << endl;
//	}
//};
//class MI :public D1, public D2
//{
//public:
//	MI()
//	{
//		cout << "MI���캯��" << endl;
//	}
//	void print()
//	{
//		cout << "MI��ӡ����" << endl;
//	}
//	~MI()
//	{
//		cout << "MI��������" << endl;
//	}
//};
//int main()  //��ϰ18.25
//{
//	B1 *b1 = new MI;//���캯���ĵ����Ǵӻ��࿪ʼ��������
//	cout << endl;
//	B2 *b2 = new MI;
//	cout << endl;
//	D1 *d1 = new MI;
//	cout << endl;
//	D2 *d2 = new MI;
//	cout << endl;
//
//	b1->print();
//	cout << endl;
//	b2->print();
//	cout << endl;
//	d1->print();
//	cout << endl;
//	d2->print();
//	cout << endl;
//
//	delete b1;//ɾ��ָ��������Ļ���ָ����Ҫע�������
//	cout << endl;
//	delete b2;
//	cout << endl;
//	delete d1;
//	cout << endl;
//	delete d2;
//	cout << endl;
//
//	return 0;
//}
