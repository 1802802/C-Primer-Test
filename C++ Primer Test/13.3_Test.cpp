/*
#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
#include<algorithm>
using namespace std;

class HasPtr  //ģ����   
{
public:
	friend bool operator<(const HasPtr &a, const HasPtr &b)
	{
		cout << "������<����" << endl;
		return *a.ps < *b.ps;
	}
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) { cout << "Ĭ�Ϲ��캯��" << endl; }   //����һ���ַ�����Ĭ�Ϲ��캯��
	HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) { cout << "�������캯��" << endl; }  //�������캯�� 
	void swap(HasPtr &a, HasPtr &b)
	{
		using std::swap;
		swap(a.ps, b.ps);
		swap(a.i, b.i);
	}
	HasPtr& operator=(HasPtr &rhs) //������ֵ�����=�Ĺ��캯��  
	{
		swap(*this, rhs);  //�����뽻���ĸ�ֵ�����
		cout << "swap�Ϳ�����ֵ�����" << endl;
		return *this;
	}
	~HasPtr()  //��ϰ13.10  //��������
	{
		delete ps; //����delete����ps����Ϊ����new�Ķ�̬�ڴ棬��Ҫ�ֶ��ͷ�
	}
	string *ps;
	int i;
};

int main()
{
	HasPtr a("time3");
	HasPtr b("mine2");
	//a = b;
	HasPtr c("life1");   //����Ĭ�Ϲ��캯����һ��swap������ֵ�����
	vector<HasPtr> text{ a, b, c };   //�����������캯��
	sort(text.begin(), text.end());   //����sort��һ�������㷨�� ���������в��Ͻ�����ֵ��ֵ����ʱ������ֵ������swap������ֵ�뿽�����캯������һЩ
}//����Ҳ�����˶��<���ŵĵ���
*/