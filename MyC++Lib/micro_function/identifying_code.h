#pragma once
#include "..\over_write\stdlib\rand.h"
#include <assert.h>
#include <string>    //由于像数组这样的数据结构无法直接返回（必须作为参数传入），故考虑直接使用string类
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
		using my::rand;   // 自定义随机函数

		int all_elements_length = all_elements.length() - 1;   //长度提前计算出来  下标-1
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

			std::vector<string>::iterator it_end = ve_temp.end();  //提前计算终点   //遍历到本元素的前一个
			for (std::vector<string>::iterator it = ve_temp.begin(); it != it_end; ++it)
			{
				if (*it == str_temp && it != it_end - 1)  //去重
				{
					ve_temp.pop_back();   //删去，重新生成
					break;
				}
				else if (it == it_end - 1)   //遍历到当前元素所在位置的前一个
				{
					code_amount--;    //生成成功
				}
			}
		}
		return ve_temp;
	}
}