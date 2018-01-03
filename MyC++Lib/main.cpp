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
#define X(x) x##CC(__LINE__)4


template <class T>
void fun  (T x)
{
	C(x);
}
//È«ÌØ»¯  
template<>
void fun<int >(int a)
{

}


int main(int argc, char **argv)
{
	using std::vector;
	using std::string;
	using std::cout;



	return system("pause");
}


