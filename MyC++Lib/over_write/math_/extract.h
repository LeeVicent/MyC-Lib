/*
��˼·����
1. ������һ�ζ��ֲ���ʱ��Ҫ��ס��һ�ε�λ�ã����ڿ��ƾ��ȣ�esp��
2. �����Ͽ����������⿪���ļ��㣬Ч�ʼ������
*/

#include <iostream>

using namespace std;

namespace my
{
	float extract(float basicNum, int extractNum)
	{
		float last = 0;
		float mid = 0;
		float front = 0;
		float back = basicNum;   //��ʼ����Ϊ��β

								 //TODO  ��ִ��һ�ζ��֣������ṩ���ȿ���
		mid = (back + front) / 2;   //�е�
		do
		{
			if (powf(mid, extractNum) > basicNum)    //��� mid �� extractNum �η� > basicNUm
				back = mid;    //�޸�����Ϊmid����Ϊ���޲�����Ҫ��
			else
				front = mid;
			last = mid;    //��ס�ϴε��е�
			mid = (back + front) / 2;

		} while (abs(mid - last) > 0.000001);    //�����ζ��ֲ��ҵľ������esp��ִ��ѭ��
		return mid;
	}
}
