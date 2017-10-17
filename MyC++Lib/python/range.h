#pragma once
#include <vector>

//C++不支持Python那样的位置参数，必须使用多种重载版本

/*
* 功能：产生0~stop-1 的等差数列（步长为1）
*            若 stop <= 0, 则产生空序列
* 参数：int stop：上界 
*            int step：步长
* 2017-10-6 Vicent
*/
namespace my
{
	std::vector<int> range(int stop)   //返回值不可为引用，局部vector已释放  //常引用也不可以，原因未知
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
* 功能：产生0~stop-1 的等差数列（步长为step默认为1）  
*            若 stop <= 0 || stop <= start, 则产生空序列
* 参数：int start：下界
*            int stop：上界
*            int step：步长
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