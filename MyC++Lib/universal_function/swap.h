#pragma once

//��������ģ��

template <class T>
void Swap(T &a, T &b)
{
	T temp;    
	temp = a;    //T����ʵ�֡�=������������
	a = b;
	b = temp;
}