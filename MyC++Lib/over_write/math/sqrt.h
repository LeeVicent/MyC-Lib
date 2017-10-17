#include <math.h>
#include <iostream>

using namespace std;
//�ο���ַ��http://blog.csdn.net/stormbjm/article/details/8191737


//����ʵ��sqrt���������ַ���Ч�ʼ���
/*
�ö��ֵķ�������һ�������У�ÿ�����м�����ƽ�������飬������ˣ���������������м��������С�ˣ���������������м�������
*/
/*
������sqrt(16)�Ľ���������ԣ�0+16��/2=8��8*8=64��64��16��Ȼ��������ƣ�
�ԣ�0+8��/2=4��4*4=16�պã���õ�����ȷ�Ľ��sqrt(16)=4��
*/
#pragma once

float MySqrt(float n)
{
	if (n<0) //С��0�İ�������Ҫ�Ĵ��� 
		return n;
	float mid, last;
	float low, up;
	low = 0, up = n;
	mid = (low + up) / 2;
	do
	{
		if (mid*mid>n)
			up = mid;
		else
			low = mid;
		last = mid;
		mid = (up + low) / 2;
	} while (abs(mid - last) > 0.000001);  //���ȿ���
	return mid;
}


