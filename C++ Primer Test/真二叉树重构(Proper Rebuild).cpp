#include <iostream>
#include <cstdio>
using namespace std;

int xianxu[4000000], houxu[4000000], BinaryTreezhongxu[4000000];
int PR_n;

const int SZ = 1 << 20;  //����io ������������ٶ�
struct fastio
{
	char inbuf[SZ];
	char outbuf[SZ];
	fastio()
	{
		setvbuf(stdin, inbuf, _IOFBF, SZ);
		setvbuf(stdout, outbuf, _IOFBF, SZ);
	}
}io;

/*�������ݽṹ���*/
typedef struct BinaryTree
{
	int key;
	BinaryTree *lson;
	BinaryTree *rson;
}BinaryTree;

/* ���������ж�Ӧ��ֵ��λ�� */
int Array_Find(int *A, int begin, int end, int key)
{
	for (int i = begin; i < end; i++)
		if (key == A[i])
			return i;
	return -1;
}

/*����������������������ʵ�ֵĵݹ�ʽ��������ع�*/
BinaryTree *GetBinaryTree(int *PreOrder, int pbegin, int pend, int *PostOrder, int tbegin, int tend)
{
	if (pbegin >= pend || tbegin >= tend) return NULL;   // ����, �޽ڵ����  

	BinaryTree *Root = new BinaryTree;         // �����ڶ���, ��������ʱ������ʧ  
	*Root = { PreOrder[pbegin], NULL, NULL };   // ������ڵ�  ���캯������ʼֵ�����ڵ㣩��ֵΪ�������λ

	if (pbegin + 1 == pend) return Root;   // �����������������  
	int lr = Array_Find(PostOrder, tbegin, tend, PreOrder[pbegin + 1]); // �ں�������в������������ֱ��ȷ���������ĸ��ڵ㣬��ֵ

																		// ȷ���������������� ǰ�򡢺���������, �ݹ���� */  
	//�����������ʼΪpbegin+1����ΪpbeginΪ���ڵ㣬�Ѿ�ʹ�ã�����ֹ��Ϊ(lr + 1 - tbegin) + pbegin + 1�������Ϊlr+2������lr+1Ϊ���������һ���ڵ�
	//���������Ϊtbegin�� lr + 1�������ĵ�һ���������ĵ�һ��������Ϊ[��
	Root->lson = GetBinaryTree(PreOrder, pbegin + 1, (lr + 1 - tbegin) + pbegin + 1, PostOrder, tbegin, lr + 1);
	Root->rson = GetBinaryTree(PreOrder, (lr + 1 - tbegin) + pbegin + 1, pend, PostOrder, lr + 1, tend - 1);

	return Root;
}

/*��������������еĽڵ�ֵ�Լ����Ӧ������*/
void Tree_Print(BinaryTree *Root)
{
	if (Root == NULL) return;

	printf("key:   %d\n", Root->key);      //visit tree
	if (Root->lson != NULL) 
		printf("lson:  %d\n", Root->lson->key);
	if (Root->rson != NULL) 
		printf("rson:  %d\n", Root->rson->key);
	printf("\n\n");

	Tree_Print(Root->lson);
	Tree_Print(Root->rson);
}

/*������������*/
void IN_Print(BinaryTree *Root)
{
	if (Root == NULL) return;
	IN_Print(Root->lson);
	printf("%d ", Root->key);
	IN_Print(Root->rson);
}

int main_erchashu()
{
	scanf("%d", &PR_n);   //�ڵ���������
	for (int i = 0; i < PR_n; i++)
		scanf("%d", &xianxu[i]);
	for (int i = 0; i < PR_n; i++)
		scanf("%d", &houxu[i]);
	BinaryTree *Root = GetBinaryTree(xianxu, 0, PR_n, houxu, 0, PR_n);
	IN_Print(Root);
	printf("\n");
	return 0;
}