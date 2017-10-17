#ifndef REMOVE_DUPLICATION_
#define REMOVE_DUPLICATION_

//��ʵ���������Ӧ�÷���<algorithm>�Ϊ���������ṩȥ�ع���
#include <vector>
using std::vector;

/*
* ���ܣ�����Ԫ��ʱ����
* ������ vector<T> &ve_src��Դvector��������ã�һ��������ڲ�����Ԫ��Ӧ��û���ظ�������һ����vector_object��
*            T insert_element��     ������Ԫ��
* ����ֵ��int : ����ɹ����� 1������ʧ�ܷ��� 0
* 2017-10-7  Vicent
*/
namespace my
{
	template <typename T>
	void remove_duplication(vector<T> &ve_src)
	{
		vector<T> ve_unique;   // ��ʱ������ظ�Ԫ��

		vector<T>::iterator it_end = ve_src.end();
		for (vector<T>::iterator it = ve_src.begin(); it != it_end; ++it)
			remove_duplication(ve_unique, *it);

		ve_src = ve_unique;
	}
}


/*
* ���ܣ�����Ԫ��ʱ����
* ������ vector<T> &ve_src��Դvector��������ã�һ��������ڲ�����Ԫ��Ӧ��û���ظ�������һ����vector_object��
*            T insert_element��     ������Ԫ��
* ����ֵ��int : ����ɹ����� 1������ʧ�ܷ��� 0
* 2017-10-7  Vicent
*/
namespace my
{
	template <typename T>
	int remove_duplication(vector<T> &ve_src, T insert_element)
	{
		if (ve_src.empty() == true)   //Ϊ��ֱ�Ӳ���
		{
			ve_src.push_back(insert_element);
			return 1;
		}

		vector<T>::iterator it_end = ve_src.end();
		for (vector<T>::iterator it = ve_src.begin(); it != it_end; ++it)
		{
			if (*it == insert_element)
				return 0;
			else if (it == it_end - 1)  //���һ��forѭ��
			{
				ve_src.push_back(insert_element);
				return 1;
			}
		}
	}
}

#endif // !REMOVE_DUPLICATION_

