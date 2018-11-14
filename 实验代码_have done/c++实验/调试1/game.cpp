/* 下面的代码会实现一个猜拳游戏，让你与电脑对决。
** 你出的拳头由你自己决定，电脑则随机出拳，最后判断胜负。
** 說明：此題來源自網上，但不要搜索正確代碼，而要依靠debug修改代碼，自欺欺人，於己何益？
*/
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//原缺少time.h头文件

#define True 1//原True无定义

void judge(int*);
char toUpper(char);//原函数toUpper无声明定义

int main()
{
	char gamer;  // 玩家出拳
	int computer;  // 电脑出拳
	int* result = (int*)malloc(sizeof(int));  

	// 原创建指针未强制转化为int*型
	
	// 为了避免玩一次游戏就退出程序，将代码放在循环中
	while (True) {
		printf("这是一个猜拳的小游戏，请输入你要出的拳头：\n");
		printf("A:剪刀\nB:石头\nC:布\nD:不玩了\n");
		scanf("%c", &gamer);

		int flag=1;
		//作为标记，当用户输入除a,b,c,d,A,B,C,D以外的数据时，程序应该重新进行，不继续向下继续运行
		//flag==0时，表示重新进行
		//flag==1时，表示继续向下进行
	

		switch (toUpper(gamer)) { 
		// toUpper 函數用於將小寫字母轉換為大寫字母
			case 'A': 
				gamer = 4;
				break;

			case 'B':
				gamer = 7;
				break;

			case 'C':
				gamer = 10;
				break;

			case 'D':
				return 0;


			case '\n': system("cls"); flag=0;break;
			//避免用户不小心按回车的时候出现“你的选择为 %c 选择错误,程序退出...”
			//作用是将回车排除在外


			default:
				printf("你的选择为 %c 选择错误,程序退出...\n", gamer);


				flag=0;
				//输出错误时，更改为0，避免程序继续向下运行

				fflush(stdin);
				//清除缓冲区，当用户输入多于一个字符，如"gaaa"时
				//之后的"aaa"是无用输入，将其清除

				getchar();//作为暂停作用

				// 此句的作用是清除控制台内的所有文字，此句无错误，不要修改
				system("cls"); 

				break;
		}
		fflush(stdin);
		//清除缓冲区，当用户输入多于一个字符，如"aaabb"时
		//之后的"aabb"是无用输入，将其清除

		if(flag==1)
		{
			srand((unsigned)time(NULL));  // 以当前时间为随机数种子，以保证产生的数字足够随机
			computer = rand() % 3;  // 产生随机数并取余，得到电脑出拳
			//只有三种选择， 应该 余3

			*result = gamer + computer;

			printf("电脑出了");
			switch (computer)
			{
				case 0:printf("剪刀\n"); break; //4
				case 1:printf("石头\n"); break; //7
				case 2:printf("布\n"); break;   //10
			}

			printf("你出了");
			switch (gamer)
			{
				case 4:printf("剪刀\n"); break;
				case 7:printf("石头\n"); break;
				case 10:printf("布\n"); break;
			}

			judge(result);//传入的是 指针
			
			system("pause>nul && cls");  // 暂停并清屏，此句無錯。
		}

	} // end of while

	return 0;
}

// 通過判斷result的值便可得到勝負結果
// 但爲了鍛煉debug技能，函數中result的值的判斷並不全部正確，請找出其中錯誤并修改
void judge(int* result)
{
	//修改为 正确的 result 结果
	if (*result == 6 || *result == 7 || *result == 11)
		printf("你赢了!\n");	
	else if (*result == 5 || *result == 9 || *result == 10)
		printf("电脑赢了!\n");
	else
		printf("平手\n");
}

char toUpper(char gamer)
{
//填补原来空缺的函数

	if(gamer>='a'&&gamer<='z') gamer-=32;
	return gamer;
}