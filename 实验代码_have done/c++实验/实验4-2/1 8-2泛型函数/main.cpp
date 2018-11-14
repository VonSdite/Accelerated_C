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
	//��ȡ����̨���
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	//���Ե�vector����
	cout << "��������" << endl;
	cout << "BigVector���� { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1}\nSmallVector���� { 3, 4 }\n\n";
	vector<int> BigVector = { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1 };
	vector<int> SmallVector = { 3, 4 };

	//���Ե�list����
	cout << "BigList����{ 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1}\nSmallList���� { 3, 4 }\n\n\n";
	list<int> BigList = { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 1, 1 };
	list<int> SmallList = { 3, 4 };

//_search
	//�ı�������ɫ
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "_search�����Ĳ���(�ڴ�������в��ҵ�С�����У����ص�һ��ƥ�����������Ԫ�ص����������): \n\n";
	SetConsoleTextAttribute(handle, 0x07);

	cout << "vector�Ĳ���\n";
	//c++11���������ֱ��auto
	auto vec_it = _search(BigVector.begin(), BigVector.end(), SmallVector.begin(), SmallVector.end());
	if (vec_it != BigVector.end())
	{
		cout << "�ɹ��ҵ�" << endl;
		cout << "�ҵ�: " << *vec_it << endl;
		cout << "ǰһ��Ԫ����: " << *(vec_it - 1) << endl;
		cout << "��һ��Ԫ����: " << *(vec_it + 1) << endl;
	}
	else cout << "�Ҳ���\n";

	cout << "\nlist�Ĳ���\n";
	//c++11���������ֱ��auto
	auto lis_it = _search(BigList.begin(), BigList.end(), SmallList.begin(), SmallList.end());
	if (lis_it != BigList.end())
	{
		cout << "�ɹ��ҵ�" << endl;
		cout << "�ҵ�: " << *lis_it << endl;
		cout << "ǰһ��Ԫ����: " << *(--lis_it) << endl;
		cout << "��һ��Ԫ����: " << *(++++lis_it) << endl;
	}
	else cout << "�Ҳ���\n";

//_find_if
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_find_if�����Ĳ���(�ڴ��������ҵ���һ���������3��Ԫ��):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	cout << "vector�Ĳ���\n";
	vec_it = _find_if(BigVector.begin(), BigVector.end(), [](int &n) { return n > 3;});
	if (vec_it != BigVector.end())
	{
		cout << "�ɹ��ҵ�" << endl;
		cout << "�ҵ�: " << *vec_it << endl;
	}
	else cout << "�Ҳ���\n";

	cout << "\nlist�Ĳ���\n";
	lis_it = _find_if(BigList.begin(), BigList.end(), [](int &n) {return n > 3;});
	if (lis_it != BigList.end())
	{
		cout << "�ɹ��ҵ�" << endl;
		cout << "�ҵ�: " << *lis_it << endl;
	}
	else cout << "�Ҳ���\n";

//_copy
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_copy�����Ĳ���(�������и��Ƶ�һ��������):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	vector<int> vec_tmp;
	list<int> lis_tmp;

	cout << "vector�Ĳ���\n";
	_copy(BigVector.begin(), BigVector.end(), back_inserter(vec_tmp));
	for (auto w : vec_tmp)
	{
		cout << w << " ";
	}

	cout << "\n\nlist�Ĳ���\n";
	_copy(BigList.begin(), BigList.end(), back_inserter(lis_tmp));
	for (auto w : lis_tmp)
	{
		cout << w << " ";
	}
	cout << endl << endl;

//_remove_copy_if
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_remove_copy_if�����Ĳ���(����������С�ڵ���5��Ԫ�طŵ���һ��������):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	vec_tmp.clear();
	lis_tmp.clear();

	cout << "vector�Ĳ���\n";
	_remove_copy_if(BigVector.begin(), BigVector.end(), back_inserter(vec_tmp), [](int &n) { return n > 5; });
	for (auto w : vec_tmp)
	{
		cout << w << " ";
	}

	cout << "\n\nlist�Ĳ���\n";
	_remove_copy_if(BigList.begin(), BigList.end(), back_inserter(lis_tmp), [](int &n) { return n > 5; });
	for (auto w : lis_tmp)
	{
		cout << w << " ";
	}
	cout << endl << endl;

//_transform
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_transform�����Ĳ���(�ô�������ÿ��Ԫ�ؼ�1):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	vec_tmp.clear();
	lis_tmp.clear();

	cout << "vector�Ĳ���\n";
	_transform(BigVector.begin(), BigVector.end(), back_inserter(vec_tmp), [](int m) { return ++m; });
	for (auto w : vec_tmp)
	{
		cout << w << " ";
	}

	cout << "\n\nlist�Ĳ���\n";
	_transform(BigList.begin(), BigList.end(), back_inserter(lis_tmp), [](int m) { return ++m; });
	for (auto w : lis_tmp)
	{
		cout << w << " ";
	}
	cout << endl << endl;

//_partition
	SetConsoleTextAttribute(handle, 0x0F);
	cout << "\n_partition�����Ĳ���(�ô������е���1��Ԫ�طŵ�����ǰ��):\n\n";
	SetConsoleTextAttribute(handle, 0x07);

	cout << "vector�Ĳ���\n";
	_partition(BigVector.begin(), BigVector.end(), [](int m) {return m == 1;});
	for (auto w : BigVector)
	{
		cout << w << " ";
	}

	cout << "\n\nlist�Ĳ���\n";
	_partition(BigList.begin(), BigList.end(), [](int m) {return m == 1;});
	for (auto w : BigList)
	{
		cout << w << " ";
	}
	cout << endl << endl;
	return 0;
}