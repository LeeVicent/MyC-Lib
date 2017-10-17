/***************************************************************
Copyright© 1995-2017   All Rights Reserved.
File Name:   //TODO
Author: Lee Vicent（北风其凉）
Function List: 报错（返回一个包含行号，文件名的字符串）
Version:1.0           Date: 7/2/2017
History: NULL

【注意】
全部定义为static变量和函数，防止重命名和二次定义
****************************************************************/
#pragma once
#define TOSTRING(line)  #line
#define EXCHANGE(line) TOSTRING (line)
#define ERR(msg) Error(msg, EXCHANGE(__LINE__) , __FILE__)
#define TEST "行号:"EXCHANGE(__LINE__)"  "


char* MyStract(char *dest, char *src);
char* Error(char *msg, char* line, char* file);
char* MyStrrchr(char *str, char c);

namespace ErrorSpace {
	static char dest_test_[233] = {};
}

using namespace ErrorSpace;

static char* Error(char *msg, char* line, char* file)
{
	MyStract(dest_test_, "==================\n");
	MyStract(dest_test_, "警告:\t");
	MyStract(dest_test_, msg);
	MyStract(dest_test_, "\n");
	MyStract(dest_test_, "行号:\t");
	MyStract(dest_test_, line);
	MyStract(dest_test_, "\n");
	MyStract(dest_test_, "文件:\t");
	MyStract(dest_test_, MyStrrchr(file, '\\') + 1);
	MyStract(dest_test_, "\n=================\n\n");
	return dest_test_;
}

static char* MyStract(char *dest, char *src)
{
	char *tempDest = dest;
	char *tempSrc = src;

	while (*tempDest != '\0')
		tempDest++;
	while (*tempSrc != '\0')
	{
		*tempDest = *tempSrc;
		tempSrc++;
		tempDest++;
	}

	*(++tempDest) = '\0';

	return dest;
}

static char * MyStrrchr(char *str, char c)
{
	char *tempStr = str;
	char *tempReturn = NULL;
	while (*tempStr != '\0')
	{
		if (*tempStr == c)
		{
			tempReturn = tempStr;
		}
		tempStr++;
	}
	return tempReturn;
}