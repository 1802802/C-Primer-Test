/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class Employee
{
public:
	Employee() {};  //Ĭ�ϵĿչ��캯��
	Employee(const string &name)  //�����ַ�����Ĭ�Ϲ��캯��
	{
		Emname = name;
		static int temp = 10000;
		Emnum = temp++;
	}
	Employee(const Employee &temp) = delete;   //�������캯���Ķ��壬��Ҫ���������ǲ���Ҫ�书�ܣ�����ֱ��delete
	Employee &operator=(const Employee &temp) = delete;  //������ֵ������Ķ��壬��Ҫ���������ǲ���Ҫ�书�ܣ�����ֱ��delete
	~Employee() = default;    //��������������������ΪĬ��ֵ
	string Emname;
	int Emnum;
};

int main()   //��ϰ13.18
{
	Employee jeck;
	Employee jack("jack"), mike("mike");
	cout << jack.Emname << " " << jack.Emnum << endl;
	cout << mike.Emname << " " << mike.Emnum << endl;
}*/