#ifndef  CLOCK_H_
#define CLOCK_H_

/*
*  文件功能：代码段所用时间计算
*  基本演示：
*                   A(1);
*                   Sleep(1000);
*                   B(1);    //Test 1 spends time is : 1.001
*  2017-10-9  Vicent
*/

#include <time.h>
#include <Windows.h>   //Sleep()函数使用

#define A(x) clock_t start##x = clock()
#define B(x) \
              {\
                    clock_t end##x = clock();\
                    cout << "Test " << #x <<" spends time : " << static_cast<double>((end##x) - (start##x)) / CLK_TCK << "\n";\
              }

#endif // ! CLOCK_H_



