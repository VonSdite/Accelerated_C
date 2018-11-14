#include "hello_screen.h"

void start()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("mode con cols=110 lines=30");		//设置显示窗口的列数和行数

	const vector<string> citiao =
	{
		"神啊，请承认这个事实，请输入(\"I am God\"): ",
		"你可是尊敬的神呢，请输入(\"I am God\"): ",
		"神啊，事到如今，你不愿意看看你的子民变成什么样子了吗！请输入(\"I am God\"): ",
		"尊敬的神，我词条不多，别欺负我， 请输入(\"I am God\"): ",
		"求您乖乖输入了， 请输入(\"I am God\"): ",
		"来吧， 输入之(\"I am God\"): "
	};
	const string greeting = "亲爱的上帝，\
			\n\n你将用上帝的视角观察着学生的信息，\
			\n\n用你的魔法打开这个神奇的系统吧！\
			\n\n请输入(I am God): ";
	char ch;

	cout << "按\"回车键\"直接跳过显示\"" << endl << endl;

	SetConsoleTextAttribute(handle, 0x0F);
	for (size_t i = 0; i < greeting.length(); i++)
	{
		cout << greeting[i];
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 13)
			{
				for (size_t j = i + 1; j < greeting.length(); ++j)
				{
					cout << greeting[j];
				}
				break;
			}
		}
		Sleep(100);
	}
	SetConsoleTextAttribute(handle, 0x07);

	string tmp;
	srand((unsigned)time(NULL));
	unsigned int cnt = citiao.size();

	while (1)
	{
		SetConsoleTextAttribute(handle, 0x0c);
		getline(cin, tmp);
		SetConsoleTextAttribute(handle, 0x07);
		if ("I am God" != tmp)
		{
			SetConsoleTextAttribute(handle, 0x0F);
			cout << endl << citiao[rand() % cnt] << endl;
			SetConsoleTextAttribute(handle, 0x07);
		}
		else break;
		cin.clear();
	}
}


void choose_start()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	cout << endl;
	print_line();
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "┃" << string(46, '>') << "┃" << endl;
	cout << "┃" << string(46, ' ') << "┃" << endl;
	cout << "┃                                              ┃" << endl;
	cout << "┃                ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "学生之养成系统";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "                ┃" << endl;
	cout << "┃             ";
	SetConsoleTextAttribute(handle, 0x0b);
	cout << "Students ESimulation";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "             ┃" << endl;
	cout << "┃                                              ┃" << endl;
	cout << "┃" << string(46, ' ') << "┃" << endl;
	cout << "┃";
	SetConsoleTextAttribute(handle, 0x0f);
	cout << "         >>> Press Enter To Start <<<         ";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "┃" << endl;
	cout << "┃                                              ┃" << endl;
	cout << "┃                                              ┃" << endl;
	cout << "┃";
	SetConsoleTextAttribute(handle, 0x0c);
	cout << "              Press ESC To Quit               ";
	SetConsoleTextAttribute(handle, 0x07);
	cout << "┃" << endl;
	cout << "┃" << string(46, ' ') << "┃" << endl;
	cout << "┃" << string(46, '<') << "┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	print_line();
}

void cover_guangbiao()
{
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = 1;					//这个设置光标的大小,值为1-100
	cci.bVisible = FALSE;			//这个设置光标是否显示

	HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOL bResult = SetConsoleCursorInfo(hOutputHandle, &cci); //设置光标信息
}

void see_guangbiao()
{
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = 25;					//这个设置光标的大小,值为1-100
	cci.bVisible = TRUE;			//这个设置光标是否显示

	HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOL bResult = SetConsoleCursorInfo(hOutputHandle, &cci); //设置光标信息
}

int show_hello_screen()
{
	char ch;
	choose_start();
	cover_guangbiao();
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 27:
				cout << endl;
				return 1;
			case 13:
				return 0;
				break;
			}
		}
	}
	return 0;
}