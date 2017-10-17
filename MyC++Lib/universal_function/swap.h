#pragma once

//交换函数模板

template <class T>
void Swap(T &a, T &b)
{
	T temp;    
	temp = a;    //T必须实现“=”运算符的深拷贝
	a = b;
	b = temp;
}