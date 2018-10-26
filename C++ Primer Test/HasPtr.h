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

	HasPtr(HasPtr &&rhs) noexcept:ps(new string(*rhs.ps)), i(rhs.i)   //�ƶ����캯��
	{
		rhs.ps = nullptr;
		rhs.i = 0;
		cout << "�ƶ����캯��" << endl;
	}

	void swap(HasPtr &a, HasPtr &b)
	{
		using std::swap;
		swap(a.ps, b.ps);
		swap(a.i, b.i);
	}

	HasPtr& operator=(HasPtr &rhs) //������ֵ�����=�Ĺ��캯��  //�˴����ܼ����ţ���ΪҪֱ�Ӹ�ֵ�������ݣ�ʹ��swapʱ��
	{							   //�˴�ʹ��swapʱ���ܼ����ţ���Ϊ����Ҫ������ֵ���ڽ��д�ͳ������ֵ���������ʱ�������ţ��������ô���
		//swap(*this, rhs);  //�����������ĸ�ֵ�����
		delete ps;
		ps = new string(*rhs.ps);  //����ʹ�ô�ͳ�Ŀ�����ֵ˳��
		i = rhs.i;
		cout << "������ֵ�����" << endl;
		return *this;
	}

	HasPtr& operator=(HasPtr &&rhs) noexcept   //�ƶ���ֵ�����
	{
		if (this != &rhs)
		{
			delete ps;
			ps = new string(*rhs.ps);
			i = rhs.i;
		}
		cout << "�ƶ���ֵ�����" << endl;
		return *this;
	}

	~HasPtr()  //��ϰ13.10  //��������
	{
		delete ps; //����delete����ps����Ϊ����new�Ķ�̬�ڴ棬��Ҫ�ֶ��ͷ�
	}
//private:
	string *ps;
	int i;
};