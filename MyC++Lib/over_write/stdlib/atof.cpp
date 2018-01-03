/*****************************************
��������MyAtof
���ܣ����ַ���ת��Ϊdouble
���������const char *src
����������NULL
����ֵ��float


��˼·��
1. �Ȳ�ֳ�������
2. ��ͣ����߾��ȵ�double����ת����

��ע�⡿
1. ASC���� ʮ���� 48 �����ַ� '0'
2. ʹ����pow()����
*****************************************/
#include <math.h>
using namespace std;


float MyAtof(const char *src)
{
	int i = 0;
	int exponent = 0;
	int tempInt = 0;
	float tempDouble = 0;

	while (src[i] != '.')
		i++;

	for (int temp = i - 1; temp >= 0; temp--, exponent++)
		tempInt = tempInt + pow(10, exponent) * (src[temp] - 48);

	exponent = -1;
	i++;
	while (src[i] != '\0')
	{
		tempDouble = tempDouble + pow(10, exponent) * (src[i] - 48);
		exponent--;
		i++;
	}

	return tempDouble += tempInt;
}

/******************************************
=========��׼�ļ�===========
����ԭ�ͣ�float atof(const char *str);
ͷ�ļ���#include<stdlib.h>
�Ƿ��Ǳ�׼��������
�������ܣ����ַ���ת���ɸ���ֵ��Ҳ���ǽ��ַ���strת���ɸ���ֵȻ���ȡת����Ľ����
����ֵ������ת����ĸ���ֵ

��ȱ�ݡ���NULL
*****************************************/