#ifndef __8_2_H__ 
#define __8_2_H__  

#include <algorithm>

template <typename ForwardIterator1, typename ForwardIterator2>
//该函数用于由正向迭代器b和e界定的序列中查找由正向迭代器b2和e2界定的子序列
//返回指向第一个匹配的于序列首元素的正向迭代器
//迭代器参数所属类别由传入的实参的类别决定
ForwardIterator1 _search(ForwardIterator1 b, ForwardIterator1 e,
	ForwardIterator2 b2, ForwardIterator2 e2)
{
	for (;b != e; ++b) if (equal(b2, e2, b)) return b;
	return e;
}

template <typename InputIterator, typename Predicate>
//该函数用于由正向迭代器b和e界定的序列中查找首次满足p表达式的元素
//如果查找到，返回指向这个元素的迭代器，否则返回e
//迭代器参数所属类别由传入的实参的类别决定
InputIterator _find_if(InputIterator b, InputIterator e, Predicate p)
{
	for (;b != e; ++b) if (p(*b)) return b;
	return e;
}

template <typename InputIterator, typename OutputIterator>
//该函数用于由输入迭代器b和e界定的序列中的值复制到目标容器中
//目标容器由输出迭代器d指定
//该函数假定在目标容器中有足够的空间存储复制过来的值
//返回一个值指向目标容器末元素后面一个元素
//参数类型由传入的实参类型决定
OutputIterator _copy(InputIterator b, InputIterator e, OutputIterator d)
{
	for (;b != e; ++b) *d++ = *b;
	return d;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
//该函数用于使条件p为假的元素复制到输出迭代器d指向的目标容器中
//返回一个指向目标容器末元素后面一个元素的迭代器
//该函数假定目标容器有足够大的空间
//参数类型由传入的实参类型决定
OutputIterator _remove_copy_if(InputIterator b, InputIterator e,
	OutputIterator d, Predicate p)
{
	for (;b != e; ++b) if (!p(*b)) *d++ = *b;
	return d;
}

template <typename InputIterator, typename OutputIterator, typename Function>
//f函数必须带有一个参数，调用_transform函数时先调用f函数
//f函数以由输入迭代器b和e界定的序列的元素为参数
//transform函数将生成结果序列存储到输出迭代器d指定的目标容器中，
//返回一个指向目标容器末元素后一个元素的迭代器
//该函数假定目标容器足够大
//参数类型由传入的实参类型决定
OutputIterator _transform(InputIterator b, InputIterator e,
	OutputIterator d, Function f)
{
	for (;b != e; ++b) *d++ = f(*b);
	return d;
}

template <typename ForwardIterator, typename Predicate>
//将由双向迭代器b和e界定的序列分成两部分，会将满足表达式p为真的元素放在容器的前面
//不满足p为真的元素放在容器的后面
//返回第一个不满足p为真的元素的迭代器
//如果所有元素都使p为真，则返回e
//参数类型由传入的实参类型决定
ForwardIterator _partition(ForwardIterator b, ForwardIterator e,
	Predicate p)
{
	ForwardIterator first_fail = b;
	for (;b != e; ++b) if (p(*b)) swap(*first_fail++, *b);
	return first_fail;
}

#endif 