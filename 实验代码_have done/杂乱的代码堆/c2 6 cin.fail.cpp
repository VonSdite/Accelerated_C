
// //二、cin.ignore(a,ch)
//     从输入流（cin）中提取字符，提取的字符被忽略（ignore），不被使用。每抛弃一个字符，它都要计数和比较字符：如果计数值达到a或者被抛弃的字符是ch，则cin.ignore()函数执行终止；否则，它继续等待。
// 它的一个常用功能就是用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响。
// 比如可以这么用：
// cin.ignore(1024,'\n')，通常把第一个参数设置得足够大，这样实际上总是只有第二个参数'\n'起作用，所以这一句就是把回车（包括回车）之前的所以字符从输入缓冲（流）中清除出去。
/*三、cin.sync()和cin.ignore()的比较
    sync()的作用就是清除输入缓冲区。成功时返回0，失败时badbit会置位，函数返回-1.
另外，对于绑定了输出的输入流，调用sync()，还会刷新输出缓冲区。

但由于程序运行时并不总是知道外部输入的进度，很难控制是不是全部清除输入缓冲区的内容。通常我们有可能只是希望放弃输入缓冲区中的一部分，而不是全部。比如清除掉当前行、或者清除掉行尾的换行符等等。但要是缓冲区中已经有了下一行的内容，这部分可能是我们想保留的。这个时候最好不要用sync()。可以考虑用ignore函数代替。
*/

#include <iostream>
#include "limits"
using namespace std;
int main( void )
{
    int number;

    // while(1) {
    //     cin >> number;
    //     if ( cin.fail() ) {
    //         cin.clear();
    //         cin.ignore(numeric_limits<int>::max(),'\n');
    //         // string c;//也可用字符串来获取这个错误， 让其能正确
    //         // cin>>c;
    //         // cout << "fail,the input char is:" << c << endl;
    //         cout << "and now number is :" << number << endl;
    //     } else {
    //         cout << "Your input is:" << number << endl;
    //     }
    // }
    while (1)
    {
        while (cin >> number)
        {
            cout << number << endl;
        }
        if (cin.fail())
        {
            if (!cin.eof())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                cout << "jaja" << endl;
            }
            else
            {
                cin.clear();
                cout << "asha" << endl;
            }
        }
    }
    return 0;
}