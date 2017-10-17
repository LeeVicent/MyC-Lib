#pragma once
#include <time.h>   // time()函数
#include <stdlib.h>  // srand()与rand()函数
#include <assert.h>  //assert()
#include <memory> //share_ptr<T>()

namespace my
{
}


/*
* 功能：产生随机数，范围为 0~stop-1
* 参数： size_t stop：上界
* 返回值：范围随机值
* 2017-10-5  Vicent
*/
namespace my
{
	size_t rand(size_t stop)
	{
		//srand设置以后，每次调用my::rand()函数随机结果一样（仅在本次执行时std::rand()结果都不同，再次执行my::rand()和上次一样） 
		//也就是说，每次执行my::rand()后重新设置时间种子会导致std::rand()随机结果一样
		//TODO 考虑使用全局对象，先于main函数执行   //使srand((unsigned)time(time_t())); 程序运行期间只执行一次
		//srand((unsigned)time(time_t()));     //关于time_t()是否需要取地址，有待于研究srand()底层实现  //目前已知不需要  //可以设为NULL
		static bool srand_flag = false;
		if (srand_flag == false)
			srand((unsigned)time(time_t()));
		srand_flag = true;
		assert(stop > 0);
		return  std::rand() % stop;
	}
}

/*
* 功能：产生随机数，范围为 start~stop-1
* 参数：size_t start：下界
*            size_t stop：上界
* 返回值：范围随机值
* 2017-10-4  Vicent
*/
namespace my 
{
	size_t rand(size_t start, size_t stop)
	{
		assert(start > 0 && stop > 0 && start <= stop);
		//time_t time_;   //获取时间种子
		//srand((unsigned)time(&time_));   //原代码  2017-10-4   下面为改进

						//具体实现机制应该是srand()函数修改rand()的部分参数，以修改rand()函数的行为
		//srand((unsigned)time(new time_t));   //time()函数获得系统时间  //直接动态申请会造成内存泄露  //考虑智能指针
		//srand((unsigned)time(time_t()));   //2017-10-6  改为匿名局部对象
										 //此时rand函数生成大概是5位数
										 //x % y，计算结果必定为0 ~ x
		static bool srand_flag = false;
		if (srand_flag == false)
			srand((unsigned)time(time_t()));
		srand_flag = true;

		size_t temp = std::rand() % stop;  
		while (1)
		{
			if (start > temp)   //越界，重新生成
				temp = std::rand() % stop;
			else
				return temp;
		}
	}
}






