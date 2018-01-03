/*****************************************
函数名：MyAtof
功能：将字符串转换为double
传入参数：const char *src
传出参数：NULL
返回值：float


【思路】
1. 先拆分成两个数
2. 求和（往高精度的double方向转化）

【注意】
1. ASC表中 十进制 48 代表字符 '0'
2. 使用了pow()函数
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
=========标准文件===========
函数原型：float atof(const char *str);
头文件：#include<stdlib.h>
是否是标准函数：是
函数功能：将字符串转换成浮点值，也就是将字符串str转换成浮点值然后获取转换后的结果。
返回值：返回转换后的浮点值

【缺陷】：NULL
*****************************************/