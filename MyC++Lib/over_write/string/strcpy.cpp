/*****************************************
��������MyStrcpy
���ܣ��ַ�������
���������double x, double y
����������NULL
����ֵ��double

��˼·��

*****************************************/

char * MyStrcpy(char * dest, char * src)
{
	char *tempDest = dest;
	char *tempSrc = src;
	while (*tempSrc != '\0')
	{
		*tempDest = *tempSrc;
		tempDest++;
		tempSrc++;
	}
	*(++tempDest) = '\0';
	return dest;
}

/******************************************
=========��׼�ļ�===========
����ԭ�ͣ� char * strcpy (char *dest,char * src);
ͷ�ļ���#include<string.h>
�Ƿ��Ǳ�׼��������
�������ܣ�ʵ���ַ����Ŀ���������Ҳ���ǰ��ַ���src�е����ݿ������ַ���dest�У�ʹ�����ַ�����������ͬ��
����ֵ��ָ���ַ���dest��ָ��

��ȱ�ݡ�������Խ��Ŀ����ԣ�dest���п����޷�����src
*****************************************/