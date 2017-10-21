#pragma once

//C++新特性，限制数组长度

namespace my
{
	void fun(int(&arr)[10]) {}  //传入数组的长度必须为10，否则编译失败
}