/*****************************************
��������MyPow
���ܣ���x��y�η�
���������double x, double y
����������NULL
����ֵ��double

��˼·��
1. ָ��ΪС��ʱת��Ϊ����
----��1����10�Ĵ��ݻ�Ϊ������0.25 *100 = 125
----��2��25/125Լ��
----��3������ѭ��С�����о�����ʧ���Ժ�����

2.    2��1/2�η�������2��һ�η����ٿ���
       2��2/3�η�������2��2�η����ٿ�3�η�
*****************************************/
#include "..\..\stdafx.h"
#pragma once
using namespace std;

extern float PowInt(float basicNum, int exponent);                                           //float�����η�
extern float Extract(float basicNum, int extractNum);                                     //���ַ���float�� extractNum�����ο�������ʱ������
//
//double MyPow(double basicNum, double exponent)
//{
//	int numerator;   //����
//	int denominator;   //��ĸ
//	unsigned long long temp = 0;
//	Float2Fraction(exponent, numerator, denominator);
//	
//	temp = PowInt(basicNum, numerator);    //�ȳ� ���� �η�   //���ӹ���Ļ���Խ��
//	basicNum = Extract(temp, denominator);   //�ٿ� ��ĸ �η�
//
//	return basicNum;
//}




/******************************************
=========��׼�ļ�===========
����ԭ�ͣ�double pow(double x, double y);
double pow10(int x);
ͷ�ļ���#include<math.h>
�Ƿ��Ǳ�׼��������
�������ܣ�ָ������������pow����x��y�η�������pow10�൱��pow(10.0,x)������10��x�η���
����ֵ�����ؼ�������˫����ֵ��

*****************************************/