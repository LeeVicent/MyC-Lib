#include<iostream>

using namespace std;

#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])    //��������洢��С


 /*************************************************
����������������
�������ܣ�����ȷ��λ�ú��ƶ�
���������values  //������  n  //���鳤��
����������NULL
����ֵ��NULL
ʱ�临�Ӷȣ�O(n^2)
 *************************************************/
void Sort(int values[], int n)
{
	for (int j = 1; j < n; j++)    //��ѭ��������һ��
	{
		int temp = values[j];   //��ס����Ҫ�ƶ���Ԫ��
		int i = j - 1;   //��ʼ��������ǰһ���Ƚ�
		while (i > 0 && values[i] > temp)  //��ѭ��������һ�Σ�ȷ��λ��
		{
			values[i + 1] = values[i];
			i = i - 1;
		}
		values[i + 1] = temp;   //����
	}
}



