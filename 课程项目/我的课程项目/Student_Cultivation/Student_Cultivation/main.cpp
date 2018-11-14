#include "save_load.h"
#include "Read_Config.h"
#include "students_query.h"

int main(int argc, char *argv[])
{
	//system("Judge1.bat");	//�ж�֮ǰ�Ƿ��д浵���д浵����ʾ�Ƿ����

	if (Configure::read_conf(argv[1]))					//��ȡ��ʼ�������ļ�
	{
		return 1;										//�ļ���ʧ��ʱ�������򣬷��ش���ֵ
	}

	Dorm dorm;											//����һ������
	Instruction instructions;							//���ڴ洢ָ����Ϣ
	Students students;									//���ڴ洢ȫ��ѧ����Ϣ
	Students quit_stu;									//���ڴ洢��ѧѧ������Ϣ

	std::ifstream load(Configure::configure["SAVE_FILE_NAME"]);	//�򿪴浵
	
	//�浵������Ӵ浵��
	if (load)
	{
		if (load_info(dorm, students, load))
		{
			return 1;
		}
		load.close();
	}
	//���浵������ʱ�����ȡ��ʼ�ļ�
	else
	{
		if (read_stu(dorm, students, argv[2]))			//��ȡѧ������
		{
			return 1;									//�ļ���ʧ��ʱ�������򣬷��ش���ֵ
		}
	}

	if (read_instructions(instructions, argv[3]))		//��ȡ��Ӧָ��
	{
		return 1;										//�ļ���ʧ��ʱ�������򣬷��ش���ֵ
	}

	run_instructions(instructions, dorm, students, quit_stu);	//����ָ��


	students_query(dorm, students, quit_stu);			//��ʾ�û�����

	std::ofstream save(Configure::configure["SAVE_FILE_NAME"]); //�浵�ļ�
	save_info(dorm, students, save);					//�浵
	
	//system("Judge2.bat");		//�ж��Ƿ�Ҫ�浵�����浵�����ϴδ浵��Ϣ����ά�ֿ�
	return 0;
}
