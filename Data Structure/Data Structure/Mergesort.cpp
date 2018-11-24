#include "Ch2.h"

template <typename T> void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	cout << "���ù鲢����" << endl;
	if ((hi - lo) < 2) return;
	int mi = (lo + hi) / 2;
	mergeSort(lo, mi);   cout << "   ����ǰ���ֹ鲢����" << endl;
	mergeSort(mi, hi);   cout << "   ���ú󲿷ֹ鲢����" << endl;//�ݹ�ֱ�����
	merge(lo, mi, hi);  //�鲢
}

template <typename T> void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
	T* A = _elem + lo;
	int lb = mi - lo; T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);  //��B�и�ֵA��ǰ�벿��
	int lc = hi - mi; T* C = _elem + mi;      //��C�и�ֵA�ĺ�벿��
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] < B[j]))) A[i++] = C[k++];
	}
	cout << "���ö�·�鲢" << endl;
	delete[]B;
}

int main_Mergesort()
{
	initializer_list<int> list{ 13,21,32,4,16,5,8,12 };
	Vector<int> a(list);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	a.mergeSort(0, 8);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}