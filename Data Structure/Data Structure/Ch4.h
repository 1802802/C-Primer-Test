//#pragma once
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//template <typename T> class Stack : public vector<T> { //����������/ĩ����Ϊջ��/��
//public: //size()��empty()�Լ��������Žӿڣ�����ֱ������
//	void push(T const& e) { insert(size(), e); } //��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
//	T pop() { return remove(size() - 1); } //��ջ����Ч��ɾ��������ĩԪ��
//	T& top() { return (*this)[size() - 1]; } //ȡ����ֱ�ӷ���������ĩԪ��
//	void print() { for (int n = size() - 1; n >= 0; n--) cout << (*this)[n]; cout << endl; }
//};