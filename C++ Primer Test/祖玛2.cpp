//#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <stdlib.h>
//#include <stdio.h>
//using namespace std;
//
///*����size���ͣ�ֱ�ӽ��м���Ҳ���ԣ������ٶ���΢����һ��*/
///*���������˼·*/
///*��������list��������������OJ�н����˴���STL�⣬�������������������׫д������
//����ṹ��Ϊ�����֣���1���������壺���ڽ����ݶ���洢�����У�Ȼ�����strcpy�Ŀռ�仯��ÿ�β��뵼�������У����һ����������ѭ����ֱ�������������Ϊֹ�����������
//					��2��check�����壺��鵱ǰ�����Ƿ�����Ҫ�����Ĳ��֣�sum>=3���оͷ���1��û�оͷ���0��ÿ�β���/�޸�֮��Ҫ���м�飬����΢�ϵ�ʱ��
//					��3��change�����壺���ڸ������飬����ɾ�������������������ע��start����Ϊ��ֵ����Ҫ���ж������������СΪ0��֮�����жϵ�ǰ����ķ���������һ���п��ܵ���ͷ(������������Ͱ�����start���ؼ�������*/
//
//char save[20004], temp[20004];
//int point, n;
//
////const int SZ = 1 << 20;  //����io ������������ٶ�
////struct fastio
////{
////	char inbuf[SZ];
////	char outbuf[SZ];
////	fastio()
////	{
////		setvbuf(stdin, inbuf, _IOFBF, SZ);
////		setvbuf(stdout, outbuf, _IOFBF, SZ);
////	}
////}io;
//
//int check(char* save, int &step)    //��ѯ�Ƿ���Ҫɾ���������
//{
//	int sum = 0, pos = step;
//	while (pos <= strlen(save) && save[pos++] == save[step]) sum++;  //�����strlen(save)������С�ڻ�С�ڵ��ھ��ɣ���Ϊ�������һֱ����
//	pos = step - 1;  //pos��λ
//	while (pos >= 0 && save[pos--] == save[step]) sum++;
//	if (sum >= 3)
//		return 1;
//	return 0;
//}
//
//int change(char* save, int &step)
//{
//	int start = step, end = step;
//	while (save[start] == save[step] && start) start--;  //start����Ҳ���������ж�����������Ϊ0ʱ�������ܼ���-1
//	if (start || save[start] != save[step]) start++; //������һ�εıض���ȣ�ͬʱ��startΪ0�������е���
//	while (save[end] == save[step] && end) end++;
//	strcpy(temp, save + end);  //ֱ��Ū��start��end֮���������䣬����̰������ϲ�����������ʱ���������
//	strcpy(save + start, temp);
//	if ((save[start] == save[start + 1]) || (save[start] == save[start - 1]))  //�����жϲ��裬ֻ���������
//	{
//		if (start == 0)   //��startΪ0ʱ��Ϊ�˱���֮���check���㣬����step����1���ڼ��㡣��Ȼ����pos=step-1��λʱ���ᵼ����ֵΪ-1
//			return 1;
//		return start;  //�������������ʼλ�õ����
//	}
//	else
//		return 0;
//}
//
//int main_ZUMA2()
//{
//	fgets(save, 10002, stdin);   //�����ַ������ݣ�C++�е������fgets����gets  //stdinΪ��׼����   //Ҳ���Է�ֹ�մ�
//	scanf("%d", &n);  //�������ִ���n
//	for (int i = 1; i <= n; i++)
//	{
//		char data; int step;
//		scanf("%d %c", &step, &data);   //����Ĳ���λ����Ԫ��
//		strcpy(temp, save + step);  //�������ֵ�ĵط�֮������е�ַ������temp��
//		save[step] = data;			//������Ҫ�������ֵ
//		strcpy(save + step + 1, temp); //��temp�����ݵ�ַ���뵽step֮��ĵ�ַ�У�ʵ��step��ֵ�Ĳ�����̣�ÿ����һ�μ�һ��sz
//		while (check(save, step) == 1) step = change(save, step);   //ѭ��������ֱ��û������������Ϊֹ
//		if (strlen(save) == 1)  //������ЧԪ�ص����������ж�
//			puts("-");
//		else
//			printf("%s", save);
//	}
//	return 0;
//}