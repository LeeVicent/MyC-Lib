#pragma once
#include "..\over_write\stdlib\rand.h"
#include <assert.h>
#include <string>    //�������������������ݽṹ�޷�ֱ�ӷ��أ�������Ϊ�������룩���ʿ���ֱ��ʹ��string��
#include <iostream>
#include <vector>
#include <algorithm>

namespace my
{
	std::vector<std::string> identifying_code(const std::string &all_elements, size_t code_length, size_t code_amount)
	{
		using std::cout;
		using std::string;
		using std::vector;
		using my::rand;   // �Զ����������

		int all_elements_length = all_elements.length() - 1;   //������ǰ�������  �±�-1
		string str_temp;
		vector<string> ve_temp;

		str_temp.resize(code_length);
		//assert(code_length >= str_temp.capacity());

		while (code_amount != 0)
		{

			for (size_t i = 0; i < code_length; i++)
				str_temp.at(i) = all_elements.at(rand(all_elements_length));
			ve_temp.push_back(str_temp);
			//cout << *(ve_temp.end() - 1);

			std::vector<string>::iterator it_end = ve_temp.end();  //��ǰ�����յ�   //��������Ԫ�ص�ǰһ��
			for (std::vector<string>::iterator it = ve_temp.begin(); it != it_end; ++it)
			{
				if (*it == str_temp && it != it_end - 1)  //ȥ��
				{
					ve_temp.pop_back();   //ɾȥ����������
					break;
				}
				else if (it == it_end - 1)   //��������ǰԪ������λ�õ�ǰһ��
				{
					code_amount--;    //���ɳɹ�
				}
			}
		}
		return ve_temp;
	}
}