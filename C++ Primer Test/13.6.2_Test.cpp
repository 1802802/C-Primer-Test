//#include <iostream>  
//#include <vector>
//#include "String.h"
//#include "HasPtr.h"
//using namespace std;
//
//int main() //��ϰ13.50   //�������ƶ����캯����	�伸������������ԭ�еĿ������캯��
//{
//	String s0;
//	String s1("hello");
//	String s2(s0);
//	String s3 = s1;
//	cout << endl;
//	s2 = s1;
//	cout << endl;
//	for (auto &s : s1)
//		cout << s;
//	cout << s1.size() << endl;
//
//	cout << endl;
//
//	foo(s1);
//	cout << endl;
//	bar(s1);
//
//	cout << endl;
//
//	foo("temporary");
//	bar("temporary");
//	String s4 = baz();   //��baz��������ʱ��ԭ�еĿ������캯����������ƶ����캯������Ϊ���ڷ���ʱΪ�ַ���������ɵ���ֵ����
//	String &s5 = baz();
//	baz();//baz()��ʼ��һ��C���Ȼ��������ʱ����һ�ο������캯��
//
//	cout << endl;
//
//	//�������ֵ���룬��ֵ��String�ı������ȸ��ֱ�������ʹ�ÿ������캯������ֵ�������泣������������ֵ�ȣ�ʹ���ƶ����캯��
//	std::vector<String> svec;        //���ڴ浽���ڴ��ת�����̾�������ƶ����캯�����������ݵĶ���Ϊ����ʱ��Ϊ��ֵ�����ÿ������죻���������Ϊ��������ֵ���������ʱ��Ϊ��ֵ�������ƶ�����
//	cout << svec.capacity() << endl;
//	svec.push_back(s0);  //�����ݱ������룬���������Ŀ������캯��
//	cout << svec.capacity() << endl;
//	svec.push_back(s1);  //svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ���ƶ�����һ�Σ������ݱ������룬���������Ŀ������캯��һ��
//	cout << svec.capacity() << endl;
//	svec.push_back(baz()); //svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ���ƶ��������Σ������ݺ�������ֵ���룬�����������ƶ����캯��һ�Σ�baz()�����������һ��Cһ���ƶ�����
//	cout << svec.capacity() << endl;
//	svec.push_back("good job");  //svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ���ƶ��������Σ��������ַ������룬�����������ƶ����캯��һ�Σ�good job��ΪC�ַ����������C���Ĺ���
//	cout << svec.capacity() << endl;
//	svec.push_back(s2);//svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ�Ŀ����ƶ��ĴΣ������ݶ��룬���������Ŀ������캯��һ�Σ�
//	cout << svec.capacity() << endl;
//	svec.push_back("good job");//�������ַ������룬�ƶ����캯��һ�Σ��ַ����������C���һ��//��Ϊ��ʱ��cap�Ѿ������6�������ݲ���ʱ����Ҫ�����ڴ��С��
//	cout << svec.capacity() << endl;
//	svec.push_back(s3);//svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ���ƶ��������Σ������ݶ��룬���������Ŀ������캯��һ�Σ�
//	cout << svec.capacity() << endl;
//	svec.push_back(baz()); //baz()�����������һ��Cһ���ƶ����죨CΪ�ַ����ĳ�ʼ�����ƶ�����Ϊreturnʱԭ��Ա�ĳ�ʼ�����������ݺ�������ֵ���룬����һ���ƶ����캯��
//	cout << svec.capacity() << endl;
//
//	for (auto &s : svec)
//	{
//		for (auto &ss : s)
//			cout << ss;
//		cout << " " << s.size() << " ";
//	}
//	cout << endl;
//	return 0;
//}
//
//int main2()   //��ϰ13.53
//{
//	HasPtr a;
//	HasPtr b("me");
//	HasPtr c("icon");
//	cout << endl;
//	a = b;  //�������캯��+������ֵ�����
//	cout << endl;
//	HasPtr d(c);
//	cout << *a.ps << *b.ps << *c.ps << *d.ps << endl;
//
//	vector<HasPtr> word;
//	cout << word.capacity() << endl;
//	word.push_back(a);
//	cout << word.capacity() << endl;
//	word.push_back(b);
//	cout << word.capacity() << endl;
//	word.push_back(c);
//	cout << word.capacity() << endl;
//	word.push_back(d);
//	cout << word.capacity() << endl;
//
//	for (auto &s : word)
//		cout << *s.ps << endl;
//
//	return 0;
//}