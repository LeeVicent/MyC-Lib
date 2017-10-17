#pragma once

#include "float2string.h"

enum num_component {
	INT,
	DECIMAL
};


//����˫���ȼ����¾��ȵ�������С�����ֳ���
template <typename T>
int StrlenFloat(T num, int num_component)
{
	char tempF2Str[50];   //�ֲ�����ò��ֻ�ܷ��ں����ײ�

	if (num_component == INT)
	{
		int length = 0;
		num_component = static_cast<int>(num);
		while (num_component != 0)
		{
			num_component /= 10;
			length++;
		}
		return length;
	}

	if (num_component == DECIMAL)
	{
		Float2String(tempF2Str, num);   
		if (StrlenFloat(num, INT) == strlen(tempF2Str))    //֤������һ������С���������
		{
			return 0;
		}
		else
			return strlen(tempF2Str) - StrlenFloat(num, INT) - 1;
	}
}


//����˫���ȼ����¾��ȵ����ֳ���
template <typename T>
int StrlenFloat(T num)
{
	char tempF2Str[50];
	Float2String(tempF2Str, num);   //��ת��Ϊstring
	return StrlenFloat(num, INT) + StrlenFloat(num, DECIMAL);    //��ΪС����С���㣬����Ϊ�˹˼�����
}

