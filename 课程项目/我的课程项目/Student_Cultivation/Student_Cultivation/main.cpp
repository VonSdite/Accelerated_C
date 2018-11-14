#include "save_load.h"
#include "Read_Config.h"
#include "students_query.h"

int main(int argc, char *argv[])
{
	//system("Judge1.bat");	//判断之前是否有存档，有存档则提示是否读档

	if (Configure::read_conf(argv[1]))					//读取初始化配置文件
	{
		return 1;										//文件打开失败时结束程序，返回错误值
	}

	Dorm dorm;											//创建一个宿舍
	Instruction instructions;							//用于存储指令信息
	Students students;									//用于存储全部学生信息
	Students quit_stu;									//用于存储退学学生的信息

	std::ifstream load(Configure::configure["SAVE_FILE_NAME"]);	//打开存档
	
	//存档存在则从存档读
	if (load)
	{
		if (load_info(dorm, students, load))
		{
			return 1;
		}
		load.close();
	}
	//当存档不存在时，则读取初始文件
	else
	{
		if (read_stu(dorm, students, argv[2]))			//读取学生数据
		{
			return 1;									//文件打开失败时结束程序，返回错误值
		}
	}

	if (read_instructions(instructions, argv[3]))		//读取对应指令
	{
		return 1;										//文件打开失败时结束程序，返回错误值
	}

	run_instructions(instructions, dorm, students, quit_stu);	//运行指令


	students_query(dorm, students, quit_stu);			//显示用户界面

	std::ofstream save(Configure::configure["SAVE_FILE_NAME"]); //存档文件
	save_info(dorm, students, save);					//存档
	
	//system("Judge2.bat");		//判断是否要存档，不存档则保留上次存档信息或者维持空
	return 0;
}
