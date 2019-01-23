#include <iostream>
#include <cstdio>
#define UNDISCOVERED 0
#define DISCOVERED 1
#define VISITED 2
using namespace std;

/*����ʹ�õ�������ͼ�Ĺ�����������㷨�����ÿ���ڵ���ھ�ΪDIS���Լ�ΪVIS���ڹ�������Ĺ����в�����û���ھ�DIS��ײ
����������ѧϰ��ͼ���ڽӱ����ݽṹ������ṹ����ܺ��ã��Ժ��ѧϰ*/

struct ENode
{
	int v_to;  //��ǰ�ڵ�ָ�������
	ENode *v_from;   //ָ��ǰ�ڵ�Ľڵ�
};
struct Gragh
{
	ENode *v_self;  //����ͼ�������������ݼ���
};

Gragh cast[10000]; int queue[10000]; int status[10000];

static int BFS(int first)
{
	int queue_num = 0; int queue_front = 0;  //num��ʾ���г��ȣ�front��ʾ����
	queue[queue_num++] = first;
	status[first] = DISCOVERED; //�˴�DISCOVERED�����Ѿ���ӣ���ֵΪ1������ɨ��
	while (queue_num != queue_front)
	{
		int last_one = queue[queue_front];  //�洢��һ�����ӵ�Ԫ�أ����������ѭ����������visited״̬
		for (ENode *p = cast[queue[queue_front++]].v_self; p; p = p->v_from)  //ÿɨ��һ���ڵ㣬���׺���
		{
			switch (status[p->v_to])
			{
			case DISCOVERED:
				return -1;
			case UNDISCOVERED:
				status[p->v_to] = DISCOVERED; queue[queue_num++] = p->v_to; break; //�뵱ǰ�ڵ�������Ľڵ���� break;
			}//VISITED�ѷ��ʽ����Ľڵ㲻�ùܣ�ֱ�Ӻ���
		}
		status[last_one] = VISITED;  //��ʾ��ǰ�ڵ��Ѿ����������
	}
	return 1;
}

int main_wuxianguangbo()
{
	int cast_num, less_num, last_cast_num;
	cin >> cast_num >> less_num;
	for (int i = 0; i < less_num; i++)  //��ͼ
	{
		int start, end;
		cin >> start >> end;
		auto temp = new ENode; temp->v_to = end;
		temp->v_from = cast[start].v_self; cast[start].v_self = temp;
		temp = new ENode; temp->v_to = start;
		temp->v_from = cast[end].v_self; cast[end].v_self = temp;
		//�������ڵ㻥��ָ�򣬳�����ͼ��ÿ���ڵ�֪���Լ�ָ���ĸ��ڵ㣬���ǲ�֪���ĸ��ڵ�ָ���Լ�
		last_cast_num = start;  //�������һ������Ĵ�ׯ
	}
	cout << BFS(1) << endl;  //�ĳ�1��ȫ���ˣ���ѧ���⣬��ʵ����Ӧ��������ͼ��ȡһ���ڵ���е�

	//���д��������
	//for (int i = 0; i < 20; i++)
	//	cout << queue[i] << " ";
	//cout << endl;  

	return 0;
}
/*
4 3
1 2
1 3
2 4
*/