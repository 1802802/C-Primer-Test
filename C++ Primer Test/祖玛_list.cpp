//#include <iostream>
//#include <cstdio>
//using namespace std;
//
///*��������listд������д��ʵ�ں��ã����Ի�����������д�ɣ�C���յ�֪ʶȷʵ�ǲ����*/
//
//struct ListNode 
//{
//	char data; ListNode* pred; ListNode* succ;
//	ListNode(){}
//	ListNode(char e, ListNode* p = NULL, ListNode* s = NULL) :data(e), pred(p), succ(s) { }
//	ListNode* insertAspred(char const &e)
//	{
//		ListNode* x = new ListNode(e, pred, this);
//		pred->succ = x; pred = x;
//		return x;
//	}
//	ListNode* insertAssucc(char const &e)
//	{
//		ListNode* x = new ListNode(e, this, succ);
//		succ->pred = x; succ = x;
//		return x;
//	}
//};
//
//class List 
//{ 
//public:
//	int _size; ListNode* header; ListNode* trailer; //��ģ��ͷ�ڱ���β�ڱ�
//	int clear();
//	void init(); //�б���ʱ�ĳ�ʼ��
//	// ���캯��
//	List() { init(); } //Ĭ�Ϲ��캯��
//	~List() { clear(); delete header; delete trailer; } //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�
//	// ֻ�����ʽӿ�
//	int size() const { return _size; } //��ģ
//	bool empty() const { return _size <= 0; } //�п�
//	char& operator[] (int r) const//���أ�֧��ѭ�ȷ��ʣ�Ч�ʵͣ�
//	{
//		ListNode* p = first();
//		while (0 < r--)p = p->succ;
//		return p->data;
//	}
//		
//	ListNode* first() const { return header->succ; } //�׽ڵ�λ��
//	ListNode* last() const { return trailer->pred; } //ĩ�ڵ�λ��
//	ListNode* insertA(ListNode* p, char const& e); //��e����p�ĺ�̲���
//	ListNode* insertB(ListNode* p, char const& e); //��e����p��ǰ������
//	char remove(ListNode* p); //ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�
//}; //List
//
//void List::init()
//{
//	header = new ListNode;
//	trailer = new ListNode;
//	header->succ = trailer; header->pred = NULL;
//	trailer->pred = header; trailer->succ = NULL;
//	_size = 0;
//}
//
//ListNode* List::insertA(ListNode* p, char const &e)
//{
//	_size++; return p->insertAssucc(e);
//}
//
//ListNode* List::insertB(ListNode* p, char const &e)
//{
//	_size++; return p->insertAspred(e);
//}
//
//char List::remove(ListNode* p)
//{
//	char e = p->data;
//	p->pred->succ = p->succ; p->succ->pred = p->pred;
//	delete p; _size--;
//	return e;
//}
//
//int List::clear()
//{
//	int oldsize = _size;
//	while (0 < _size) remove(header->succ);
//	return oldsize;
//}
//
//ListNode* save_node[10000];
//
//void doit(List &save, int &step, char &in)
//{
//	save.insertB(save_node[step], in);
//	switch (step)
//	{
//	case 0:
//	{
//		if (save[step] == save[step + 1] == save[step + 2])
//		{
//			save.remove(save_node[step + 2]);
//			save.remove(save_node[step]);
//			save.remove(save_node[step + 1]);
//		}
//		break;
//	}
//	case 1:
//	{
//		if (save[step - 1] == save[step] == save[step + 1])
//		{
//			save.remove(save_node[step + 1]);
//			save.remove(save_node[step]);
//			save.remove(save_node[step - 1]);
//		}
//		else
//			if (save[step] == save[step + 1] == save[step + 2])
//			{
//				save.remove(save_node[step + 2]);
//				save.remove(save_node[step]);
//				save.remove(save_node[step + 1]);
//			}
//		break;
//	}
//	default:
//	{
//		if (save[step - 2] == save[step - 1] == save[step])
//		{
//			save.remove(save_node[step]);
//			save.remove(save_node[step - 1]);
//			save.remove(save_node[step - 2]);
//		}
//		else
//			if (save[step - 1] == save[step] == save[step + 1])
//			{
//				save.remove(save_node[step + 1]);
//				save.remove(save_node[step]);
//				save.remove(save_node[step - 1]);
//			}
//			else
//				if (save[step] == save[step + 1] == save[step + 2])
//				{
//					save.remove(save_node[step + 2]);
//					save.remove(save_node[step]);
//					save.remove(save_node[step + 1]);
//				}
//		break;
//	}
//	}
//	for (int i = 0; i < save._size; i++)
//		cout << save[i] << endl;
//}
//
//int main_ZUMA_list()
//{
//	char save_in[10000];
//	List save; int n = 0;
//	scanf("%s", &save_in);
//	for (int i = 0; i < strlen(save_in); i++)
//		save_node[i] = save.insertB(save.trailer, save_in[i]);   //����ַ�ȫ����������list��
//	scanf("%d", &n);  //��Ҫ���ֵĴ���
//	for (int i = 1; i <= n; i++)   //�����������ѭ��
//	{
//		int step = 0; char in;
//		scanf("%d%s", &step, &in);   //stepΪ�������λ�ã�inΪ��������ַ�
//		doit(save, step, in);
//	}
//	return 0;
//}