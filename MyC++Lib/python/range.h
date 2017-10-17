#pragma once
#include <vector>

//C++��֧��Python������λ�ò���������ʹ�ö������ذ汾

/*
* ���ܣ�����0~stop-1 �ĵȲ����У�����Ϊ1��
*            �� stop <= 0, �����������
* ������int stop���Ͻ� 
*            int step������
* 2017-10-6 Vicent
*/
namespace my
{
	std::vector<int> range(int stop)   //����ֵ����Ϊ���ã��ֲ�vector���ͷ�  //������Ҳ�����ԣ�ԭ��δ֪
	{
		if (stop <= 0)
			return std::vector<int>();
		else
		{ 
			std::vector<int> vTemp;
			for (size_t i = 0; i < stop; i++)
				vTemp.push_back(i);
			return vTemp;
		}
	}
}

/*
* ���ܣ�����0~stop-1 �ĵȲ����У�����ΪstepĬ��Ϊ1��  
*            �� stop <= 0 || stop <= start, �����������
* ������int start���½�
*            int stop���Ͻ�
*            int step������
* 2017-10-6 Vicent
*/
namespace my
{
	std::vector<int> range(int start, int stop, int step = 1)  
	{
		if (stop <= 0 || stop <= start)
			return std::vector<int>();
		else
		{
			std::vector<int> vTemp;
			for (int i = start; i < stop; i += step)
				vTemp.push_back(i);
			return vTemp;
		}
	}
}