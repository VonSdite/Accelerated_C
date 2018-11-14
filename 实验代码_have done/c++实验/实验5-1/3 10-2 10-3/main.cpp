#include <iostream>
#include <vector>
#include <list>

#include "median.h"

using namespace std;

int main()
{
	int test_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };			//测试数组

	//vector测试
	cout << "vector测试:" << endl;
	vector<int> test_vec(test_arr, test_arr + 10);						//测试向量

	cout << "调用前: ";									//调用median函数前
	for (auto it : test_vec)
	{
		cout << it << " ";
	}

	cout << endl;

	cout << "中位数: " << median<int>(test_vec.begin(), test_vec.end()) << endl;

	cout << "调用后: ";									//调用median函数后
	for (auto it : test_vec)
	{
		cout << it << " ";
	}

	cout << endl;
	cout << endl;

	//数组测试
	cout << "数组测试:" << endl;

	cout << "调用前: ";									//调用median函数前
	for (int i = 0; i < 10; ++i)
		cout << test_arr[i] << " ";

	cout << endl;

	cout << "中位数: " << median<int>(test_arr, test_arr + 10) << endl;

	cout << "调用后: ";									//调用median函数后
	for (int i = 0; i < 10; ++i)
		cout << test_arr[i] << " ";

	cout << endl;
	cout << endl;

	//list测试
	cout << "list测试:" << endl;
	list<int> test_lis(test_arr, test_arr + 10);						//测试list

	cout << "调用前: ";									//调用median函数前
	for (auto it : test_lis)
	{
		cout << it << " ";
	}

	cout << endl;

	cout << "中位数: " << median<int>(test_lis.begin(), test_lis.end()) << endl;

	cout << "调用后: ";									//调用median函数后
	for (auto it : test_lis)
	{
		cout << it << " ";
	}

	cout << endl;
	cout << endl;

	return 0;
}
