
//շת����������Լ�����ݹ飩   
//ŷ����÷���

/*
ԭ��
int a = 25;   //���ô�Ķ�С��ȡ��
int b = 15;

a % b = 10;
b % 10 = 5;
10 %5 = 0;
��ʽȡ��Ľ���ٶ���ʽȡ�ֱ࣬��Ϊ0
*/
#include "..\..\universal_function\swap.h"

int Gcd(int a, int b)
{
	int temp;
	if (a < b)
		Swap(a, b);
	temp = a % b;
	if (temp == 0)
		return b;
	else
		Gcd(b, temp);
}