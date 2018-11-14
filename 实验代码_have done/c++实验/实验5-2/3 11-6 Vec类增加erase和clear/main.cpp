#include "Vec.h"

#include <iostream>

using namespace std;

//�ָ���
void print_star();

//������Ϣ
template <class T>
istream& read_vec(istream& in, Vec<T>& vec);

int main(int argc, char const *argv[])
{
	Vec<int> a;

	cout << "�����������(��EOF����):" << endl;
	read_vec(cin, a);							//������Ϣ

	print_star();

	int pos;
	cout << "����Ҫɾ����Ԫ��λ��: ";
	cin >> pos;
	--pos;
	Vec<int>::iterator it = a.begin();

	//�ҵ�Ҫɾ����λ��
	for (size_t i = 0; i < pos && it != a.end(); i++)
	{
		++it;
	}

	//�ж�����λ���Ƿ�Խ��
	if (it == a.end())
	{
		print_star();
		cout << "��Ҫɾ����λ��Խ��!" << endl;
	}
	else
	{
		a.erase(it);									//ɾ����λ��Ԫ��

		print_star();

		cout << "ɾ�������е�Ԫ��Ϊ:" << endl;
		for (auto it : a)
		{
			cout << it << " ";
		}
	}

	print_star();

	cout << "�������:" << endl;
	a.clear();
	if (a.empty()) cout << "��ճɹ���" << endl;
	else cout << "���ʧ�ܣ�" << endl;

	return 0;
}

template <class T>
istream& read_vec(istream& in, Vec<T>& vec)
{
	if (in)
	{
		vec.clear();

		T tmp;
		while (in >> tmp)
			vec.push_back(tmp);
		in.clear();
	}
	return in;
}

void print_star()
{
	cout << endl << "********************************************************" << endl;
}