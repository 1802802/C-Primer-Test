/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Account
{
	friend istream &read(istream&is, Account&item);
	friend ostream &print(ostream&os, const Account &item);
public:
	void calculate() { amount += amount*interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 0.42;   //�����������
	static double initRate() { return todayRate; }   //initRate�����������붨�壬���ڷ��ؽ�������ֵ
};

double Account::interestRate = initRate();  //���о�̬��ԱinterestRate�ĳ�ʼ�����䱻��ֵ��������ֵ

void Account::rate(double newRate)
{
	interestRate = newRate;
}

istream &read(istream&is, Account&item)  //�����Ա����read�Ķ��壬��������ĳ���������͵�ַ
{
	cout << "�������������뱾��" << endl;
	is >> item.owner >> item.amount;
	return is;
}

ostream &print(ostream&os, const Account &item)  //�����Ա����print�Ķ��壬�������ĳ�����������ַ
{
	os << "����Ϊ��" << item.owner << " ����ܶ�Ϊ��" << item.amount << endl;
	return os;
}

int main()
{
	Account D7_31;
	Account::rate(0.5);   //�ֶ��������ʳ�ʼֵ
	read(cin, D7_31);
	D7_31.calculate();
	print(cout, D7_31);
}*/