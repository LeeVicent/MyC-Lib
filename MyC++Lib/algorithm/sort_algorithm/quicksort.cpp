#include<iostream>

using namespace std;

#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])    //测量数组存储大小


 /*************************************************
函数名：快速排序
函数功能：排序，确定位置后移动
传入参数：values  //数组名  n  //数组长度
传出参数：NULL
返回值：NULL
时间复杂度：O(n^2)
 *************************************************/
void Sort(int values[], int n)
{
	for (int j = 1; j < n; j++)    //外循环，遍历一次
	{
		int temp = values[j];   //记住可能要移动的元素
		int i = j - 1;   //初始条件，与前一个比较
		while (i > 0 && values[i] > temp)  //内循环，遍历一次，确定位置
		{
			values[i + 1] = values[i];
			i = i - 1;
		}
		values[i + 1] = temp;   //交换
	}
}



