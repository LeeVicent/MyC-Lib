#ifndef REMOVE_DUPLICATION_
#define REMOVE_DUPLICATION_

//其实，这个函数应该放在<algorithm>里，为所有容器提供去重功能
#include <vector>
using std::vector;

/*
* 功能：插入元素时查重
* 参数： vector<T> &ve_src：源vector对象的引用（一般情况下内部已有元素应该没有重复，或是一个空vector_object）
*            T insert_element：     待插入元素
* 返回值：int : 插入成功返回 1，插入失败返回 0
* 2017-10-7  Vicent
*/
namespace my
{
	template <typename T>
	void remove_duplication(vector<T> &ve_src)
	{
		vector<T> ve_unique;   // 临时保存非重复元素

		vector<T>::iterator it_end = ve_src.end();
		for (vector<T>::iterator it = ve_src.begin(); it != it_end; ++it)
			remove_duplication(ve_unique, *it);

		ve_src = ve_unique;
	}
}


/*
* 功能：插入元素时查重
* 参数： vector<T> &ve_src：源vector对象的引用（一般情况下内部已有元素应该没有重复，或是一个空vector_object）
*            T insert_element：     待插入元素
* 返回值：int : 插入成功返回 1，插入失败返回 0
* 2017-10-7  Vicent
*/
namespace my
{
	template <typename T>
	int remove_duplication(vector<T> &ve_src, T insert_element)
	{
		if (ve_src.empty() == true)   //为空直接插入
		{
			ve_src.push_back(insert_element);
			return 1;
		}

		vector<T>::iterator it_end = ve_src.end();
		for (vector<T>::iterator it = ve_src.begin(); it != it_end; ++it)
		{
			if (*it == insert_element)
				return 0;
			else if (it == it_end - 1)  //最后一次for循环
			{
				ve_src.push_back(insert_element);
				return 1;
			}
		}
	}
}

#endif // !REMOVE_DUPLICATION_

