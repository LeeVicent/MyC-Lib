#pragma once
#include <time.h>   // time()����
#include <stdlib.h>  // srand()��rand()����
#include <assert.h>  //assert()
#include <memory> //share_ptr<T>()

namespace my
{
}


/*
* ���ܣ��������������ΧΪ 0~stop-1
* ������ size_t stop���Ͻ�
* ����ֵ����Χ���ֵ
* 2017-10-5  Vicent
*/
namespace my
{
	size_t rand(size_t stop)
	{
		//srand�����Ժ�ÿ�ε���my::rand()����������һ�������ڱ���ִ��ʱstd::rand()�������ͬ���ٴ�ִ��my::rand()���ϴ�һ���� 
		//Ҳ����˵��ÿ��ִ��my::rand()����������ʱ�����ӻᵼ��std::rand()������һ��
		//TODO ����ʹ��ȫ�ֶ�������main����ִ��   //ʹsrand((unsigned)time(time_t())); ���������ڼ�ִֻ��һ��
		//srand((unsigned)time(time_t()));     //����time_t()�Ƿ���Ҫȡ��ַ���д����о�srand()�ײ�ʵ��  //Ŀǰ��֪����Ҫ  //������ΪNULL
		static bool srand_flag = false;
		if (srand_flag == false)
			srand((unsigned)time(time_t()));
		srand_flag = true;
		assert(stop > 0);
		return  std::rand() % stop;
	}
}

/*
* ���ܣ��������������ΧΪ start~stop-1
* ������size_t start���½�
*            size_t stop���Ͻ�
* ����ֵ����Χ���ֵ
* 2017-10-4  Vicent
*/
namespace my 
{
	size_t rand(size_t start, size_t stop)
	{
		assert(start > 0 && stop > 0 && start <= stop);
		//time_t time_;   //��ȡʱ������
		//srand((unsigned)time(&time_));   //ԭ����  2017-10-4   ����Ϊ�Ľ�

						//����ʵ�ֻ���Ӧ����srand()�����޸�rand()�Ĳ��ֲ��������޸�rand()��������Ϊ
		//srand((unsigned)time(new time_t));   //time()�������ϵͳʱ��  //ֱ�Ӷ�̬���������ڴ�й¶  //��������ָ��
		//srand((unsigned)time(time_t()));   //2017-10-6  ��Ϊ�����ֲ�����
										 //��ʱrand�������ɴ����5λ��
										 //x % y���������ض�Ϊ0 ~ x
		static bool srand_flag = false;
		if (srand_flag == false)
			srand((unsigned)time(time_t()));
		srand_flag = true;

		size_t temp = std::rand() % stop;  
		while (1)
		{
			if (start > temp)   //Խ�磬��������
				temp = std::rand() % stop;
			else
				return temp;
		}
	}
}






