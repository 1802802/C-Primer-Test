//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//#include <iterator>
//#include <istream>
//#include <memory>
//using namespace std;
//
//////����+λ��1
////namespace Exercise
////{
////	int ivar = 0;
////	double dvar = 0;
////	const int limit = 1000;
////}
////int ivar = 0;
//////λ��1
////using Exercise::ivar;//������ȫ�ֱ���ivar��ͻ���������
////using Exercise::dvar;
////using Exercise::limit;
////void manip()
////{
////	//λ��2
////	double dvar = 3.1416;
////	int iobj = limit + 1;
////	++ivar;
////	++::ivar;
////	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
////}
//
//////����+λ��2
////namespace Exercise
////{
////	int ivar = 0;
////	double dvar = 0;
////	const int limit = 1000;
////}
////int ivar = 0;
//////λ��1
////
////void manip()
////{
////	//λ��2
////	using Exercise::ivar;//����ȫ�ֱ���
////	using Exercise::dvar;
////	using Exercise::limit;
////	double dvar = 3.1416;//���󣬶��ض��壬��γ�ʼ������ǰdvar�����Ѿ��ɼ�
////	int iobj = limit + 1;
////	++ivar;
////	++::ivar;
////	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
////}
//
//////ָʾ+λ��1
////namespace Exercise
////{
////	int ivar = 0;
////	double dvar = 0;
////	const int limit = 1000;
////}
////int ivar = 0;
//////λ��1
////using namespace Exercise;
////void manip()
////{
////	//λ��2
////	double dvar = 3.1416;
////	int iobj = limit + 1;
////	++ivar;  //�����ԣ�����ȷ
////	++::ivar;
////	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
////}
//
////ָʾ+λ��2
//namespace Exercise
//{
//	int ivar = 0;
//	double dvar = 0;
//	const int limit = 1000;
//}
//int ivar = 0;
////λ��1
//
//void manip()
//{
//	//λ��2
//	using namespace Exercise;
//	double dvar = 3.1416;
//	int iobj = limit + 1;
//	++ivar;  //�����ԣ�����ȷ
//	++::ivar;
//	cout << dvar << " " << iobj << " " << ivar << " " << ::ivar << endl;
//}
//
//int main()
//{
//	manip();
//	return 0;
//}