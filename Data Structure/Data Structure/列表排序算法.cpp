//#include "Ch3.h"
//
//template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�������e�������
//ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const 
//{
//	// assert: 0 <= n <= rank(p) < _size
//	/*DSA*/
//	printf("searching for "); print(e); printf(" :\n");
//	while (0 <= n--) //����p�������n��ǰ����������������Ƚ�
//		/*DSA*/ 
//	{
//		printf("  <%4d>", p->pred->data);
//		if (((p = p->pred)->data) <= e) break; //ֱ�����С���ֵԽ���ΧԽ��
//											   /*DSA*/
//	} printf("\n");
//	// assert: ����λ��p�ط����������Լ���������ܴ�ǰ���һ�ιؼ���ȽϿ���û�����壨��Ч����-inf�Ƚϣ�
//	return p; //���ز�����ֹ��λ��
//} //ʧ��ʱ������������߽��ǰ����������header�����������߿�ͨ��valid()�жϳɹ����
//
//template <typename T> //�б��ѡ�������㷨������ʼ��λ��p��n��Ԫ������
//void List<T>::selectionSort(ListNodePosi(T) p, int n) 
//{ //valid(p) && rank(p) + n <= size
//	/*DSA*/printf("SelectionSort ...\n");
//	ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
//	for (int i = 0; i < n; i++) tail = tail->succ; //����������Ϊ(head, tail)
//	while (1 < n) 
//	{ //�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
//		ListNodePosi(T) max = selectMax(head->succ, n); //�ҳ�����ߣ�����ʱ�������ȣ�
//		insertB(tail, remove(max)); //����������������ĩβ����Ϊ���������µ���Ԫ�أ�
//									/*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
//		tail = tail->pred; n--;
//	}
//}
//
//template <typename T> //�б�Ĳ��������㷨������ʼ��λ��p��n��Ԫ������
//void List<T>::insertionSort(ListNodePosi(T) p, int n) 
//{ //valid(p) && rank(p) + n <= size
//	/*DSA*/printf("InsertionSort ...\n");
//	for (int r = 0; r < n; r++) 
//	{ //��һΪ���ڵ�
//		insertA(search(p->data, r, p), p->data); //�����ʵ���λ�ò�����
//		p = p->succ; remove(p->pred); //ת����һ�ڵ�
//	}
//}
//
//template <typename T> //�б�Ĺ鲢�����㷨������ʼ��λ��p��n��Ԫ������
//void List<T>::mergeSort(ListNodePosi(T) & p, int n) 
//{ //valid(p) && rank(p) + n <= size
//	/*DSA*/printf("\tMERGEsort [%3d]\n", n);
//	if (n < 2) return; //��������Χ���㹻С����ֱ�ӷ��أ�����...
//	int m = n >> 1; //���е�Ϊ��
//	ListNodePosi(T) q = p; for (int i = 0; i < m; i++) q = q->succ; //�����б�
//	mergeSort(p, m); mergeSort(q, n - m); //��ǰ�������б�ֱ�����
//	merge(p, m, *this, q, n - m); //�鲢
//} //ע�⣺�����p��Ȼָ��鲢������ģ��£����