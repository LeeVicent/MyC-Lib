
//辗转相除法求最大公约数（递归）   
//欧几里得发明

/*
原理：
int a = 25;   //先用大的对小的取余
int b = 15;

a % b = 10;
b % 10 = 5;
10 %5 = 0;
上式取余的结果再对下式取余，直至为0
*/
#include "..\..\universal_function\swap.h"

int Gcd(int a, int b)
{
	int temp;
	if (a < b)
		Swap(a, b);
	temp = a % b;
	if (temp == 0)
		return b;
	else
		Gcd(b, temp);
}