/*****************************************
函数名：MyStrcpy
功能：字符串拷贝
传入参数：double x, double y
传出参数：NULL
返回值：double

【思路】

*****************************************/

char * MyStrcpy(char * dest, char * src)
{
	char *tempDest = dest;
	char *tempSrc = src;
	while (*tempSrc != '\0')
	{
		*tempDest = *tempSrc;
		tempDest++;
		tempSrc++;
	}
	*(++tempDest) = '\0';
	return dest;
}

/******************************************
=========标准文件===========
函数原型： char * strcpy (char *dest,char * src);
头文件：#include<string.h>
是否是标准函数：是
函数功能：实现字符串的拷贝工作，也就是把字符串src中的内容拷贝到字符串dest中，使两个字符串的内容相同。
返回值：指向字符串dest的指针

【缺陷】：存在越界的可能性，dest很有可能无法容纳src
*****************************************/