#include <iostream>
#include <cstdio>
#include <vector>
#define GetMax(a,b) (a>b)?a:b
using namespace std;

/*�������������˼�룬�ڹ��������������е�ͬʱ�������������Ĵ�ׯ�ĳ��ȵ������ӣ�Ŀǰ���Լ�¼���յ����������·��
���ǰ��ߵ�·����ʾ�����������Ƕ���·��ʱ�������Ƿȱ����*/
struct ENode 
{
	int v_to;  //��v_to��ʾ��ǰ���fͨ�����һ�����f
	ENode *v_from;
};
struct VNode 
{
	int in, len;//������ڽӱ�ṹ���������������len�Լ��㵽ÿ����������·����in�����
	ENode *v_self;
};
VNode village_to_village[1000000]; //village_to_village�д洢���㹻��VNode�ڵ㣬�ýڵ��Ա��in��ȣ�len���·����fstEdge
int visited[1000000], stack[1000000], maxlen; vector<int> save;

void TSort(int villages)   //���������������˼��������
{
	int top = 1;
	for (int i = 1; i<=villages; i++)
		if (!village_to_village[i].in)
		{
			stack[top++] = i;    //�����Ӧ�Ĵ�ׯû����ȣ���û�н�ȥ�ĵ�·�����ִ�ׯһ��Ϊͼ�Ķ���֮��ģ�����ջ��ֵΪ��ׯ��
			save.push_back(i);
		}
	while (top)   //ֱ��topΪ0����ջ��û����Ԫ��
	{
		int v = stack[top--];  //vΪջ���Ĵ�ׯ����ջ�о�Ϊ���Ϊ0�Ĵ�ׯ
		for (ENode *p = village_to_village[v].v_self; p; p = p->v_from) //������Ӧ�Ĵ�ׯ�ж�Ӧ��������Ϣ�����洢������߹�ϵ��
		{
			//���ԣ���̬�滮-���ϵĸ��µ�ÿ�����Ϊ0�Ķ�����ھӵ����·������
			village_to_village[p->v_to].len = GetMax(village_to_village[v].len + 1, village_to_village[p->v_to].len);
			maxlen = GetMax(village_to_village[p->v_to].len, maxlen);
			//����ͼ�ϵ���߲�����ǰ�ݽ���ֱ�����㵽����һ���ڵ㣬���յ�maxlenΪ�����Ĵ�ׯ��Ŀ�������ջ��������ʼ��ׯ
			//������������򣬶������������2���Ը��µ�ÿ���ھӵ����·�����Ⱥͼ�¼ͼ�����·������ 
			if (!(--village_to_village[p->v_to].in))
			{
				stack[++top] = p->v_to;  //�˴���ջ�����Ϊ0�Ĵ�ׯ���ڵ㣩
				save.push_back(p->v_to);
			}
		}
	}
}

int main_lvxingshang()
{
	int villages, pass;
	cin >> villages >> pass;
	for (int i = 0; i < pass; i++)  //��ͼ
	{
		int start, end;
		cin >> start >> end;
		auto temp = new ENode; temp->v_to = end; village_to_village[end].in++;  
		//��ʾ��ǰ�ڵ�ͨ��end��ׯ����Ӧ��end��ׯ�����+1
		temp->v_from = village_to_village[start].v_self; village_to_village[start].v_self = temp;
		//��start��ׯ���е�v_self��Ϣ�洢����ǰ�ڵ��v_from�У�Ȼ�󽫵�ǰ�ڵ�temp����start��ׯ��self��Ϣ
		//�ܽ���˵��������start�ڵ��м�¼�£���ָ��end�ڵ㣬ͬʱҲ��self�д洢�Ľڵ�ָ��
		//Ҳ����˵�����������ͼ���ݽṹ�У��ڵ�ֻ֪���Լ�ָ����Щ�ڵ㣬����֪��ָ���Լ��Ľڵ㾿����ʲô���˴���v_self��Ϊ�գ�
	}
	TSort(villages);
	cout << maxlen + 1 << endl;  //Ҫ������ʼ��ׯ�����Լ�1

	for (auto &s : save)  //���������˳��
		cout << s << " ";
	cout << endl;

	return 0;
}

/*��������
6 9
1 2
4 2
4 5
1 6
2 3
2 5
5 6
1 6
3 6
*/