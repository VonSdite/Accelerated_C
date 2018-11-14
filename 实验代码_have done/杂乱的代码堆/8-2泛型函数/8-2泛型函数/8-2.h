#ifndef __8_2_H__ 
#define __8_2_H__  

#include <algorithm>

template <typename ForwardIterator1, typename ForwardIterator2>
//�ú������������������b��e�綨�������в��������������b2��e2�綨��������
//����ָ���һ��ƥ�����������Ԫ�ص����������
//������������������ɴ����ʵ�ε�������
ForwardIterator1 _search(ForwardIterator1 b, ForwardIterator1 e,
	ForwardIterator2 b2, ForwardIterator2 e2)
{
	for (;b != e; ++b) if (equal(b2, e2, b)) return b;
	return e;
}

template <typename InputIterator, typename Predicate>
//�ú������������������b��e�綨�������в����״�����p���ʽ��Ԫ��
//������ҵ�������ָ�����Ԫ�صĵ����������򷵻�e
//������������������ɴ����ʵ�ε�������
InputIterator _find_if(InputIterator b, InputIterator e, Predicate p)
{
	for (;b != e; ++b) if (p(*b)) return b;
	return e;
}

template <typename InputIterator, typename OutputIterator>
//�ú������������������b��e�綨�������е�ֵ���Ƶ�Ŀ��������
//Ŀ�����������������dָ��
//�ú����ٶ���Ŀ�����������㹻�Ŀռ�洢���ƹ�����ֵ
//����һ��ֵָ��Ŀ������ĩԪ�غ���һ��Ԫ��
//���������ɴ����ʵ�����;���
OutputIterator _copy(InputIterator b, InputIterator e, OutputIterator d)
{
	for (;b != e; ++b) *d++ = *b;
	return d;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
//�ú�������ʹ����pΪ�ٵ�Ԫ�ظ��Ƶ����������dָ���Ŀ��������
//����һ��ָ��Ŀ������ĩԪ�غ���һ��Ԫ�صĵ�����
//�ú����ٶ�Ŀ���������㹻��Ŀռ�
//���������ɴ����ʵ�����;���
OutputIterator _remove_copy_if(InputIterator b, InputIterator e,
	OutputIterator d, Predicate p)
{
	for (;b != e; ++b) if (!p(*b)) *d++ = *b;
	return d;
}

template <typename InputIterator, typename OutputIterator, typename Function>
//f�����������һ������������_transform����ʱ�ȵ���f����
//f�����������������b��e�綨�����е�Ԫ��Ϊ����
//transform���������ɽ�����д洢�����������dָ����Ŀ�������У�
//����һ��ָ��Ŀ������ĩԪ�غ�һ��Ԫ�صĵ�����
//�ú����ٶ�Ŀ�������㹻��
//���������ɴ����ʵ�����;���
OutputIterator _transform(InputIterator b, InputIterator e,
	OutputIterator d, Function f)
{
	for (;b != e; ++b) *d++ = f(*b);
	return d;
}

template <typename ForwardIterator, typename Predicate>
//����˫�������b��e�綨�����зֳ������֣��Ὣ������ʽpΪ���Ԫ�ط���������ǰ��
//������pΪ���Ԫ�ط��������ĺ���
//���ص�һ��������pΪ���Ԫ�صĵ�����
//�������Ԫ�ض�ʹpΪ�棬�򷵻�e
//���������ɴ����ʵ�����;���
ForwardIterator _partition(ForwardIterator b, ForwardIterator e,
	Predicate p)
{
	ForwardIterator first_fail = b;
	for (;b != e; ++b) if (p(*b)) swap(*first_fail++, *b);
	return first_fail;
}

#endif 