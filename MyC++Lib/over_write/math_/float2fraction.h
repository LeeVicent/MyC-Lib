#pragma once

//С��תΪ��������

/**********************************************
�������� ��
-------------int numerator������
-------------int denominator����ĸ
���������
-------------int num��С��

�淶������������ǰ����������ں�

1. �������� *10ֱ����Ϊ����
2. ������10�Ĵ��ݽ���Լ�ּ��ɣ�շת����������������

���磺1.25  ��Ϊ125/1000

��ʱ��bugΪ��λ�����ϵ������η������Ϊ10/1
*********************************************/


#include "..\..\stdafx.h"

int Gcd(int a, int b);

template <typename T>
void Float2Fraction(T num, int &numerator, int &denominator) 
{
	bool sign = false;   //falseΪ����
	char tempF2Str[50];
	int temp10 = 1;
	T tempNum = num;
	Float2String(tempF2Str, num);   //��ת��Ϊstring
	                     //��ȡ��������
	//numerator = static_cast<int>(numerator);   //��ʽת�������رվ�����ʧ����

	if (num > 0)
		sign = false;
	else
	{
		sign = true;
		num = -num;   //TODO ����ʹ��λ�������Ч�ʣ���
	}

	num += 0.0000000000001;    //������������λ���ͺ��ˣ�����ʹ��ͬ���Ĵ������

	for (int i = 0; i < StrlenFloat(num, DECIMAL); i++)   //���С������
		num *= 10;    //��num��ͣ�� *10 ֱ����Чλȫ����Ϊ����

	//TODO   ���   ��ʱ��bugΪ10�������η������Ϊ10/1  ������
	if (0 != StrlenFloat(num, DECIMAL))
	{
		for (int i = 0; i < StrlenFloat(num) - 1; i++)
			temp10 *= 10;   //��temp10����*10�������ֵĳ��� -1  
	}
	//for (int i = 0; i < StrlenFloat(num) - 1; i++)
	//  	temp10 *= 10;   //��temp10����*10�������ֵĳ��� -1    //����������� ��λ������ ����ĸ���ǻ��

	numerator = static_cast<int>(num);
	denominator = temp10;
	int tempGcd = 0;
	while ((tempGcd = Gcd(numerator, denominator)) != 1)    //���������ڹ�����
	{
		numerator /= tempGcd;
		denominator /= tempGcd;
	}

#if 1
	cout << "���֣�" << tempNum <<"    ������Ϊ��" << numerator << "/" << denominator << endl;
#endif
}