#pragma once

//小数转为分数函数

/**********************************************
传出参数 ：
-------------int numerator：分子
-------------int denominator：分母
传入参数：
-------------int num：小数

规范：传出参数在前，传入参数在后

1. 数字整体 *10直至成为整数
2. 整数与10的次幂进行约分即可（辗转相除法求最大公因数）

例如：1.25  变为125/1000

暂时的bug为二位数以上的整数次方结果都为10/1
*********************************************/


#include "..\..\stdafx.h"

int Gcd(int a, int b);

template <typename T>
void Float2Fraction(T num, int &numerator, int &denominator) 
{
	bool sign = false;   //false为正数
	char tempF2Str[50];
	int temp10 = 1;
	T tempNum = num;
	Float2String(tempF2Str, num);   //先转换为string
	                     //获取整数部分
	//numerator = static_cast<int>(numerator);   //显式转换，并关闭精度损失警告

	if (num > 0)
		sign = false;
	else
	{
		sign = true;
		num = -num;   //TODO 考虑使用位运算提高效率！！
	}

	num += 0.0000000000001;    //哈哈，把它进位不就好了（正负使用同样的处理规则）

	for (int i = 0; i < StrlenFloat(num, DECIMAL); i++)   //获得小数长度
		num *= 10;    //将num不停地 *10 直至有效位全部成为正数

	//TODO   解决   暂时的bug为10的正数次方结果都为10/1  的问题
	if (0 != StrlenFloat(num, DECIMAL))
	{
		for (int i = 0; i < StrlenFloat(num) - 1; i++)
			temp10 *= 10;   //将temp10不断*10整个数字的长度 -1  
	}
	//for (int i = 0; i < StrlenFloat(num) - 1; i++)
	//  	temp10 *= 10;   //将temp10不断*10整个数字的长度 -1    //举例，如果是 三位数整数 ，分母还是会变

	numerator = static_cast<int>(num);
	denominator = temp10;
	int tempGcd = 0;
	while ((tempGcd = Gcd(numerator, denominator)) != 1)    //当两数存在公因数
	{
		numerator /= tempGcd;
		denominator /= tempGcd;
	}

#if 1
	cout << "数字：" << tempNum <<"    最简分数为：" << numerator << "/" << denominator << endl;
#endif
}