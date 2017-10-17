#pragma once

//浮点型以下精度转换为字符数组

//使用说明：浮点型小数位限制在12位以内  //暂时有精度损失

/************************************
1：对浮点数取整，方法很简单，把浮点数强制转化为整形。
2：把这个整形转化为字符串类型（可以使用itoa方法，当然也可以自己辗转/10取得）
3：把上面的得到的数放入字符数组中，在最后一位加上字符"."
4：使用浮点数减去上面得到的整数得到一个0.xxxx的浮点数
5：使用这个浮点数乘以10^6(有效位的方)得到一个浮点型***
6：再次执行1，2步
7：把两次得到的字符串连接起来就可以了

注意负数！！

还要解决很多问题：难道是模板的问题？   //是的。。。
1.  123.5  实际为 123.5000000000000000028
2.  123.6  实际为 123.5999999999999999937   // 末尾 > 5时为近似值
************************************/

template <class T>
void Float2String(char *dest, T num)  //dest为传入参数
{
	bool flag = false;    
	bool sign = false;   //false为正数
	int length = 0;
	int lengthDouble = 0;
	long long tempLong = 0;   //用于容纳不止12位的num
	int tempInt = 0; 

	//TODO   预处理符号位，全部处理为正数，并记住符号位

	if (num > 0)
		sign = false;
	else
	{
		sign = true;
		num = -num;   //TODO 考虑使用位运算提高效率！！
	}

	num += 0.0000000000001;    //哈哈，把它进位不就好了（正负使用同样的处理规则）
	tempInt = (int)num;   //先转换为整数

	while (tempInt != 0)
	{
		dest[length] = (tempInt % 10) + 48;   //保存整数的末位，逆序保存
		tempInt /= 10;   //删掉一位
		length++;
	}


	for (int i = 0; i < length/2; i++)    //进行逆序，交换一半次数，使用位运算减少一个中间变量
	{
		dest[i] = dest[i] ^ dest[length - 1 - i];
		dest[length - 1 - i] = dest[i] ^ dest[length - 1 - i];
		dest[i] = dest[i] ^ dest[length - 1 - i];
	}
	dest[length] = '.';

	num -=((int)num);    //获得小数部分
	for (int i = 0; i < 12; i++)    //将小数部分全部化为整数
	{
		num *= 10;
	}
   //tempInt = (int)num;    //继续利用tempInt, 直接转换会溢出，windows下double特别大
	tempLong = (long long)num;

	//TODO  从尾部遍历，直到第一个不为0的数
	lengthDouble = length;   //小数点后面一位char数组位置
	while (true)
	{
		if ((tempLong % 10) != 0 && flag == false)  //注意优先级 ！=为7级， %=为14级（倒数第二级）
			flag = true;
		else if (flag == false)
				{
					tempLong /= 10;
				}
		if (flag == true)
		{
			lengthDouble++;
			dest[lengthDouble] = (tempLong % 10) + 48;
			//cout << dest[lengthDouble] << endl;
			tempLong /= 10;
			//cout << "lengthDouble = " << lengthDouble << endl;
		}
		if (tempLong == 0)
			break;
	}
	          
	for (int i = 0; i < (lengthDouble - length)/2; i++)   //关于数组逆序，可以考虑写个算法函数（参数指定位置）
	{                                                                              //这样不易错，参数（起始位置，结束位置（长度函数内计算））
		dest[length + 1 + i] = dest[length + 1 + i] ^ dest[lengthDouble - i];
		dest[lengthDouble - i] = dest[length + 1 + i] ^ dest[lengthDouble - i];
		dest[length + 1 + i] = dest[length + 1 + i] ^ dest[lengthDouble - i];
	}
	dest[lengthDouble + 1] = '\0';

	//TODO 如果T接收的是整数，删掉‘.'
	if (strlen(dest) ==  length + 1)
	{
		dest[length] = '\0';
	}

	//TODO 如果是负数，加上“-”号
	if (sign)        //数组后移一位，考虑写函数
	{
		for (int i = strlen(dest); i >= 0; i--)
			dest[i + 1] = dest[i];
		dest[0] = '-';
	}


}
