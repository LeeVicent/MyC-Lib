/*
【思路】：
1. 进行下一次二分查找时，要记住上一次的位置，用于控制精度（esp）
2. 理论上可以用于任意开方的计算，效率极差而已
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
		float back = basicNum;   //起始上限为结尾

								 //TODO  先执行一次二分，用于提供精度控制
		mid = (back + front) / 2;   //中点
		do
		{
			if (powf(mid, extractNum) > basicNum)    //如果 mid 的 extractNum 次方 > basicNUm
				back = mid;    //修改上限为mid（因为上限不再需要）
			else
				front = mid;
			last = mid;    //记住上次的中点
			mid = (back + front) / 2;

		} while (abs(mid - last) > 0.000001);    //当两次二分查找的距离大于esp，执行循环
		return mid;
	}
}
