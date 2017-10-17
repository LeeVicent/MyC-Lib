#pragma once

#include "float2string.h"

enum num_component {
	INT,
	DECIMAL
};


//测量双精度及以下精度的整数或小数部分长度
template <typename T>
int StrlenFloat(T num, int num_component)
{
	char tempF2Str[50];   //局部数组貌似只能放在函数首部

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
		if (StrlenFloat(num, INT) == strlen(tempF2Str))    //证明其是一个不含小数点的整数
		{
			return 0;
		}
		else
			return strlen(tempF2Str) - StrlenFloat(num, INT) - 1;
	}
}


//测量双精度及以下精度的数字长度
template <typename T>
int StrlenFloat(T num)
{
	char tempF2Str[50];
	Float2String(tempF2Str, num);   //先转换为string
	return StrlenFloat(num, INT) + StrlenFloat(num, DECIMAL);    //因为小数有小数点，所以为了顾及整数
}

