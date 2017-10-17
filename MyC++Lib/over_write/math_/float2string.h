#pragma once

//���������¾���ת��Ϊ�ַ�����

//ʹ��˵����������С��λ������12λ����  //��ʱ�о�����ʧ

/************************************
1���Ը�����ȡ���������ܼ򵥣��Ѹ�����ǿ��ת��Ϊ���Ρ�
2�����������ת��Ϊ�ַ������ͣ�����ʹ��itoa��������ȻҲ�����Լ�շת/10ȡ�ã�
3��������ĵõ����������ַ������У������һλ�����ַ�"."
4��ʹ�ø�������ȥ����õ��������õ�һ��0.xxxx�ĸ�����
5��ʹ���������������10^6(��Чλ�ķ�)�õ�һ��������***
6���ٴ�ִ��1��2��
7�������εõ����ַ������������Ϳ�����

ע�⸺������

��Ҫ����ܶ����⣺�ѵ���ģ������⣿   //�ǵġ�����
1.  123.5  ʵ��Ϊ 123.5000000000000000028
2.  123.6  ʵ��Ϊ 123.5999999999999999937   // ĩβ > 5ʱΪ����ֵ
************************************/

template <class T>
void Float2String(char *dest, T num)  //destΪ�������
{
	bool flag = false;    
	bool sign = false;   //falseΪ����
	int length = 0;
	int lengthDouble = 0;
	long long tempLong = 0;   //�������ɲ�ֹ12λ��num
	int tempInt = 0; 

	//TODO   Ԥ�������λ��ȫ������Ϊ����������ס����λ

	if (num > 0)
		sign = false;
	else
	{
		sign = true;
		num = -num;   //TODO ����ʹ��λ�������Ч�ʣ���
	}

	num += 0.0000000000001;    //������������λ���ͺ��ˣ�����ʹ��ͬ���Ĵ������
	tempInt = (int)num;   //��ת��Ϊ����

	while (tempInt != 0)
	{
		dest[length] = (tempInt % 10) + 48;   //����������ĩλ�����򱣴�
		tempInt /= 10;   //ɾ��һλ
		length++;
	}


	for (int i = 0; i < length/2; i++)    //�������򣬽���һ�������ʹ��λ�������һ���м����
	{
		dest[i] = dest[i] ^ dest[length - 1 - i];
		dest[length - 1 - i] = dest[i] ^ dest[length - 1 - i];
		dest[i] = dest[i] ^ dest[length - 1 - i];
	}
	dest[length] = '.';

	num -=((int)num);    //���С������
	for (int i = 0; i < 12; i++)    //��С������ȫ����Ϊ����
	{
		num *= 10;
	}
   //tempInt = (int)num;    //��������tempInt, ֱ��ת���������windows��double�ر��
	tempLong = (long long)num;

	//TODO  ��β��������ֱ����һ����Ϊ0����
	lengthDouble = length;   //С�������һλchar����λ��
	while (true)
	{
		if ((tempLong % 10) != 0 && flag == false)  //ע�����ȼ� ��=Ϊ7���� %=Ϊ14���������ڶ�����
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
	          
	for (int i = 0; i < (lengthDouble - length)/2; i++)   //�����������򣬿��Կ���д���㷨����������ָ��λ�ã�
	{                                                                              //�������״���������ʼλ�ã�����λ�ã����Ⱥ����ڼ��㣩��
		dest[length + 1 + i] = dest[length + 1 + i] ^ dest[lengthDouble - i];
		dest[lengthDouble - i] = dest[length + 1 + i] ^ dest[lengthDouble - i];
		dest[length + 1 + i] = dest[length + 1 + i] ^ dest[lengthDouble - i];
	}
	dest[lengthDouble + 1] = '\0';

	//TODO ���T���յ���������ɾ����.'
	if (strlen(dest) ==  length + 1)
	{
		dest[length] = '\0';
	}

	//TODO ����Ǹ��������ϡ�-����
	if (sign)        //�������һλ������д����
	{
		for (int i = strlen(dest); i >= 0; i--)
			dest[i + 1] = dest[i];
		dest[0] = '-';
	}


}
