#include "stdafx.h"
#include "micro_function\identifying_code.h"
#include "STL\vector_\remove_duplication.h"
#include "python\range.h"
#include <string>
#include <vector>
#include <time.h>
#include "universal_function\clock.h"
#define C(x_) std::cout << x_ << "\n"


#define CC(x) #x
#define X(x) x##CC(__LINE__)

#include <math.h>

using namespace std;
//参考网址：http://blog.csdn.net/stormbjm/article/details/8191737


//重新实现sqrt函数，二分法，效率极低
/*
用二分的方法，在一个区间中，每次拿中间数的平方来试验，如果大了，就再试左区间的中间数；如果小了，就再拿右区间的中间数来试
*/
/*
比如求sqrt(16)的结果，你先试（0+16）/2=8，8*8=64，64比16大，然后就向左移，
试（0+8）/2=4，4*4=16刚好，你得到了正确的结果sqrt(16)=4。
*/


float MySqrt(float n)
{
	if (n<0) //小于0的按照你需要的处理 
		return n;
	float mid, last;
	float low, up;
	low = 0, up = n;
	mid = (low + up) / 2;
	do
	{
		if (mid*mid>n)
			up = mid;
		else
			low = mid;
		last = mid;
		mid = (up + low) / 2;
	} while (abs(mid - last) > 0.000001);  //精度控制
	return mid;
}





int main(int argc, char **argv)
{
	using std::vector;
	using std::string;
	using std::cout;

	//clock_t start = clock();
	//vector<int> v{ 1,1,1,3,5,5 };
	//for (int x : my::range(1000))
	//	;
	//clock_t end = clock();
	//cout << "Running Time : " << (double)(end - start) / 1000 << "\n";
	//V(1);
	////C(a1);
	//int X(c);
	//c29 = 10;

	A(1);
	C(MySqrt(489789794546));
	B(1);

	A(2);
	C(sqrt(489789794546));
	B(2);



	return system("pause");
}


