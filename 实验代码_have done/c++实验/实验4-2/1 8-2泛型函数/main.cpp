#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <windows.h>
#include <iterator>

#include "8-2.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//获取控制台句柄
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	//测试的vector序列
	cout << "测试序列" << endl;
	cout << "BigVector序列 { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1}\nSmallVector序列 { 3, 4 }\n\n";
	vector<int> BigVector = { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1 };
	vector<int> SmallVector = { 3, 4 };

	//测试的list序列
	cout << "BigList序列{ 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1}\nSmallList序列 { 3, 4 }\n\n\n";
	list<int> BigList = { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1 };
	list<int> SmallList = { 3, 4 };

//_search
	//改变字体颜色
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "_search函数的测试(在大的序列中查找到小的序列，返回第一个匹配的于序列首元素的正向迭代器): \n\n";
	SetConsoleTextAttribute(handle, 0x07);

	cout << "vector的测试\n";
	//c++11迭代器类别直接auto
	auto vec_it = _search(BigVector.begin(), BigVector.end(), SmallVector.begin(), SmallVector.end());
	if (vec_it != BigVector.end())
	{
		cout << "成功找到" << endl;
		cout << "找到: " << *vec_it << endl;
		cout << "前一个元素是: " << *(vec_it - 1) << endl;
		cout << "后一个元素是: " << *(vec_it + 1) << endl;
	}
	else cout << "找不到\n";

	cout << "\nlist的测试\n";
	//c++11迭代器类别直接auto
	auto lis_it = _search(BigList.begin(), BigList.end(), SmallList.begin(), SmallList.end());
	if (lis_it != BigList.end())
	{
		cout << "成功找到" << endl;
		cout << "找到: " << *lis_it << endl;
		cout << "前一个元素是: " << *(--lis_it) << endl;
		cout << "后一个元素是: " << *(++++lis_it) << endl;
	}
	else cout << "找不到\n";

//_find_if
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_find_if函数的测试(在大序列中找到第一个满足大于3的元素):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	cout << "vector的测试\n";
	vec_it = _find_if(BigVector.begin(), BigVector.end(), [](int &n) { return n > 3;});
	if (vec_it != BigVector.end())
	{
		cout << "成功找到" << endl;
		cout << "找到: " << *vec_it << endl;
	}
	else cout << "找不到\n";

	cout << "\nlist的测试\n";
	lis_it = _find_if(BigList.begin(), BigList.end(), [](int &n) {return n > 3;});
	if (lis_it != BigList.end())
	{
		cout << "成功找到" << endl;
		cout << "找到: " << *lis_it << endl;
	}
	else cout << "找不到\n";

//_copy
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_copy函数的测试(将大序列复制到一个容器中):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	vector<int> vec_tmp;
	list<int> lis_tmp;

	cout << "vector的测试\n";
	_copy(BigVector.begin(), BigVector.end(), back_inserter(vec_tmp));
	for (auto w : vec_tmp)
	{
		cout << w << " ";
	}

	cout << "\n\nlist的测试\n";
	_copy(BigList.begin(), BigList.end(), back_inserter(lis_tmp));
	for (auto w : lis_tmp)
	{
		cout << w << " ";
	}
	cout << endl << endl;

//_remove_copy_if
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_remove_copy_if函数的测试(将大序列中小于等于5的元素放到另一个容器内):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	vec_tmp.clear();
	lis_tmp.clear();

	cout << "vector的测试\n";
	_remove_copy_if(BigVector.begin(), BigVector.end(), back_inserter(vec_tmp), [](int &n) { return n > 5; });
	for (auto w : vec_tmp)
	{
		cout << w << " ";
	}

	cout << "\n\nlist的测试\n";
	_remove_copy_if(BigList.begin(), BigList.end(), back_inserter(lis_tmp), [](int &n) { return n > 5; });
	for (auto w : lis_tmp)
	{
		cout << w << " ";
	}
	cout << endl << endl;

//_transform
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_transform函数的测试(让大序列中每个元素加1):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	vec_tmp.clear();
	lis_tmp.clear();

	cout << "vector的测试\n";
	_transform(BigVector.begin(), BigVector.end(), back_inserter(vec_tmp), [](int m) { return ++m; });
	for (auto w : vec_tmp)
	{
		cout << w << " ";
	}

	cout << "\n\nlist的测试\n";
	_transform(BigList.begin(), BigList.end(), back_inserter(lis_tmp), [](int m) { return ++m; });
	for (auto w : lis_tmp)
	{
		cout << w << " ";
	}
	cout << endl << endl;

//_partition
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_partition函数的测试(让大序列中等于1的元素放到序列前面):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	cout << "vector的测试\n";
	_partition(BigVector.begin(), BigVector.end(), [](int m) {return m == 1;});
	for (auto w : BigVector)
	{
		cout << w << " ";
	}

	cout << "\n\nlist的测试\n";
	_partition(BigList.begin(), BigList.end(), [](int m) {return m == 1;});
	for (auto w : BigList)
	{
		cout << w << " ";
	}
	cout << endl << endl;
	return 0;
}