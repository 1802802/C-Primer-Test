/*#include<iostream>  
#include<string>  
#include<vector>  
using namespace std;

class HasPtr  //ģ����   
{
	
	HasPtr(const HasPtr &rhs) : ps(new string (*rhs.ps)), i(rhs.i) {}  //�������캯��  //��ϰ13.5 
	HasPtr& operator=(const HasPtr &rhs)  //������ֵ�����=�Ĺ��캯��    //��ϰ13.8
	{
		string *p = new string(*rhs.ps);
		delete ps;
		ps = p;
		i = rhs.i;
		return *this;
	}
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}   //���Ա��ֱ�ӳ�ʼ����psĬ����һ��ָ�룬ָ��һ��s���ַ�����iĬ��Ϊ0
	~HasPtr()  //��ϰ13.10  //��������
	{
		delete ps; //����delete����ps����Ϊ����new�Ķ�̬�ڴ棬��Ҫ�ֶ��ͷ�
	}
private:
	string *ps;
	int i;
};*/

