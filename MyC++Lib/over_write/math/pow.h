/*****************************************
函数名：MyPow
功能：求x的y次方
传入参数：double x, double y
传出参数：NULL
返回值：double

【思路】
1. 指数为小数时转换为分数
----（1）乘10的次幂化为整数，0.25 *100 = 125
----（2）25/125约分
----（3）无限循环小数会有精度损失，以后讨论

2.    2的1/2次方，就是2的一次方，再开方
       2的2/3次方，就是2的2次方，再开3次方
*****************************************/
#include "..\..\stdafx.h"
#pragma once
using namespace std;

extern float PowInt(float basicNum, int exponent);                                           //float整数次方
extern float Extract(float basicNum, int extractNum);                                     //二分法，float的 extractNum整数次开方（暂时正数）
//
//double MyPow(double basicNum, double exponent)
//{
//	int numerator;   //分子
//	int denominator;   //分母
//	unsigned long long temp = 0;
//	Float2Fraction(exponent, numerator, denominator);
//	
//	temp = PowInt(basicNum, numerator);    //先乘 分子 次方   //分子过大的话会越界
//	basicNum = Extract(temp, denominator);   //再开 分母 次方
//
//	return basicNum;
//}




/******************************************
=========标准文件===========
函数原型：double pow(double x, double y);
double pow10(int x);
头文件：#include<math.h>
是否是标准函数：是
函数功能：指数函数。函数pow是求x的y次方；函数pow10相当于pow(10.0,x)，是求10的x次方。
返回值：返回计算结果的双精度值。

*****************************************/