#include <iostream>
#include <vector>
#include <list>

#include "median.h"

using namespace std;

int main()
{
	int test_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };			//��������

	//vector����
	cout << "vector����:" << endl;
	vector<int> test_vec(test_arr, test_arr + 10);						//��������

	cout << "����ǰ: ";									//����median����ǰ
	for (auto it : test_vec)
	{
		cout << it << " ";
	}

	cout << endl;

	cout << "��λ��: " << median<int>(test_vec.begin(), test_vec.end()) << endl;

	cout << "���ú�: ";									//����median������
	for (auto it : test_vec)
	{
		cout << it << " ";
	}

	cout << endl;
	cout << endl;

	//�������
	cout << "�������:" << endl;

	cout << "����ǰ: ";									//����median����ǰ
	for (int i = 0; i < 10; ++i)
		cout << test_arr[i] << " ";

	cout << endl;

	cout << "��λ��: " << median<int>(test_arr, test_arr + 10) << endl;

	cout << "���ú�: ";									//����median������
	for (int i = 0; i < 10; ++i)
		cout << test_arr[i] << " ";

	cout << endl;
	cout << endl;

	//list����
	cout << "list����:" << endl;
	list<int> test_lis(test_arr, test_arr + 10);						//����list

	cout << "����ǰ: ";									//����median����ǰ
	for (auto it : test_lis)
	{
		cout << it << " ";
	}

	cout << endl;

	cout << "��λ��: " << median<int>(test_lis.begin(), test_lis.end()) << endl;

	cout << "���ú�: ";									//����median������
	for (auto it : test_lis)
	{
		cout << it << " ";
	}

	cout << endl;
	cout << endl;

	return 0;
}
