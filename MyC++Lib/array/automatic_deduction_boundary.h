#pragma once

namespace my
{
	template <int len>  //函数模板全特化（函数模板仅支持全特化，偏特化编译失败）
	void fun(int (&arr)[len]) {}   //函数内能直接获得len
}