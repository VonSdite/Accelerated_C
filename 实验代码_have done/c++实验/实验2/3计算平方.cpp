#include "iostream"
#include "iomanip"
#include "cmath"

using namespace std;

//计算最小所需设置的宽度
int get_width(double max)
{
	return log10(max)+1;
}

int main(int argc, char const *argv[])
{
	//请求输入并读入I值
	cout<<"Please enter the number I(integer): ";
	double I;
	cin>>I;

	//设置左对齐，设置保留两位小数
	cout<<setiosflags(ios::left)<<setiosflags(ios::fixed)<<setprecision(2);

	//输出
	for (double i = 1; i <= I; ++i)
	{
		cout<<setw(get_width(I)+3)
		<<i
		<<' '
		<<setw(get_width(I*I)+3)//这行可不要
		<<pow(i,2)
		<<endl;
	}
	return 0;
}