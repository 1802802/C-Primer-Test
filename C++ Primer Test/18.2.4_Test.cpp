//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//using namespace std;
//
//
//namespace p
//{
//	void compute(int) { cout << "p int" << endl; }   //����ʱ��ͬ�β���������������
//	void compute(){cout << "��"<<endl; }//������  
//	void compute(const void *) { cout <<"const void *"<< endl; }//����,0->NULL  
//}
//using namespace p;
////using p::compute;
//void compute(int) { cout << "int"<<endl; }//����,���ƥ��  
//void compute(double, double = 1.1) { cout <<"double"<< endl; }//����,int->double  
//void compute(char*, char* = 0) { cout << "char*"<<endl; }//����,0->NULL  
////using p::compute;
//void f()
//{
//	//using p::compute;
//	//compute(0);//��compute(int)�汾���ƥ��  
//	p::compute(0);
//}
//
//int main()   //��ϰ18.20
//{
//	f();
//}
//
////�ܽ᣺using����ʱ�����䴦�ھֲ������򣬻����ص��ⲿ������ĺ�����������ֲ���������ʹ�õ��������ģ��ⲿ������ʹ�õ����Լ��ģ�
////���ǵ��������ⲿ������ʱ���������ͬ�β������������ĺ������Լ�ͬ���ı�����ܣ���Ϊ�ض����ˡ�������ͬ�βεĺ���������
////usingָʾʱ����������һֱΪȫ������������ͬ�βεĺ��������ء�����������ͬ�β������������ĺ������Լ�ͬ���ı�����ܣ���Ϊ�Ƕ����ԡ�
////��������ͨ���ڵ��ñ�������ʱע�������ȫ�ַ�Χ����Ļ��������ռ䶨��ļ��ɽ�����⡣