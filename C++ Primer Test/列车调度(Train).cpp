#include <iostream>
#include <cstdio>
using namespace std;

//const int SZ = 1 << 20;  //����io ������������ٶ�
//struct fastio
//{
//	char inbuf[SZ];
//	char outbuf[SZ];
//	fastio()
//	{
//		setvbuf(stdin, inbuf, _IOFBF, SZ);
//		setvbuf(stdout, outbuf, _IOFBF, SZ);
//	}
//}io;

int nn, mm = 0; int train_A[1600000], train_B[3200000], train_S[1600000];

int main_Train()
{
	int ini = 0;
	scanf("%d%d", &nn, &mm);
	for (int i = 0; i < nn; i++)
		scanf("%d", &train_A[i]);
	int flag = 1;  // 1-���У�0-������

	int xb_B = 0;  // �������B���±�
	int xb_S = 0;  // ����ջS���±�

	for (int i = 1, j = 0; i <= nn && j < nn; i++)  //�㷨��Ҫ˼·Ϊ��1��n���뵽ջ�У�����������в��ϱȽ�ԭ�������ݣ�һ������ͬ����ջ�����ռ��flag�Ǻź�ջ��Ԫ�أ������ж�no���߲�������
	{
		if (xb_S < mm) 
		{
			train_B[xb_B++] = 1;   //����ĸ�ֵ1���൱�ڸ�S�в�ֵ����־��B�и�ֵΪ1���൱��push
			train_S[xb_S++] = i;
		}
		else 
		{
			flag = 0;   //��ջ�дﵽ��󻺴�ʱ��û���꣬��Ĭ��ʧ�ܣ�ֱ������ѭ��
			break;
		}
		if (i == train_A[j])   //��ǰ������A�е�j��Ԫ�����ʱ��S�з�����һλ���¸�ֵΪ0���൱�ڵ�������λ����pop�������B�е���һλ��ֵΪ0������pop
		{
			j++;
			train_S[--xb_S] = 0;   //xb_S���ͣ�һ������ͬ�����ݣ���ͬ��pop����
			train_B[xb_B++] = 0;
			while (xb_S > 0 && train_S[xb_S - 1] == train_A[j])   //���αȽ�ջ��Ԫ����A�д洢��Ԫ�أ����ܷ��Ӧ��ȫ
			{
				j++;
				train_S[--xb_S] = 0;
				train_B[xb_B++] = 0;
			}
		}
	}

	if (flag == 0 || xb_S != 0) printf("No\n");
	else
	{
		for (xb_B = 0; xb_B < 2 * nn; xb_B++)
		{
			if (train_B[xb_B] == 0) printf("pop\n");
			else if (train_B[xb_B] == 1) printf("push\n");
		}
	}
	return 0;
}