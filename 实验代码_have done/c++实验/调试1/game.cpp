/* ����Ĵ����ʵ��һ����ȭ��Ϸ����������ԶԾ���
** �����ȭͷ�����Լ������������������ȭ������ж�ʤ����
** �f�������}��Դ�ԾW�ϣ�����Ҫ�������_���a����Ҫ����debug�޸Ĵ��a���������ˣ�춼����棿
*/
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//ԭȱ��time.hͷ�ļ�

#define True 1//ԭTrue�޶���

void judge(int*);
char toUpper(char);//ԭ����toUpper����������

int main()
{
	char gamer;  // ��ҳ�ȭ
	int computer;  // ���Գ�ȭ
	int* result = (int*)malloc(sizeof(int));  

	// ԭ����ָ��δǿ��ת��Ϊint*��
	
	// Ϊ�˱�����һ����Ϸ���˳����򣬽��������ѭ����
	while (True) {
		printf("����һ����ȭ��С��Ϸ����������Ҫ����ȭͷ��\n");
		printf("A:����\nB:ʯͷ\nC:��\nD:������\n");
		scanf("%c", &gamer);

		int flag=1;
		//��Ϊ��ǣ����û������a,b,c,d,A,B,C,D���������ʱ������Ӧ�����½��У����������¼�������
		//flag==0ʱ����ʾ���½���
		//flag==1ʱ����ʾ�������½���
	

		switch (toUpper(gamer)) { 
		// toUpper ������춌�С����ĸ�D�Q�����ĸ
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
			//�����û���С�İ��س���ʱ����֡����ѡ��Ϊ %c ѡ�����,�����˳�...��
			//�����ǽ��س��ų�����


			default:
				printf("���ѡ��Ϊ %c ѡ�����,�����˳�...\n", gamer);


				flag=0;
				//�������ʱ������Ϊ0��������������������

				fflush(stdin);
				//��������������û��������һ���ַ�����"gaaa"ʱ
				//֮���"aaa"���������룬�������

				getchar();//��Ϊ��ͣ����

				// �˾���������������̨�ڵ��������֣��˾��޴��󣬲�Ҫ�޸�
				system("cls"); 

				break;
		}
		fflush(stdin);
		//��������������û��������һ���ַ�����"aaabb"ʱ
		//֮���"aabb"���������룬�������

		if(flag==1)
		{
			srand((unsigned)time(NULL));  // �Ե�ǰʱ��Ϊ��������ӣ��Ա�֤�����������㹻���
			computer = rand() % 3;  // �����������ȡ�࣬�õ����Գ�ȭ
			//ֻ������ѡ�� Ӧ�� ��3

			*result = gamer + computer;

			printf("���Գ���");
			switch (computer)
			{
				case 0:printf("����\n"); break; //4
				case 1:printf("ʯͷ\n"); break; //7
				case 2:printf("��\n"); break;   //10
			}

			printf("�����");
			switch (gamer)
			{
				case 4:printf("����\n"); break;
				case 7:printf("ʯͷ\n"); break;
				case 10:printf("��\n"); break;
			}

			judge(result);//������� ָ��
			
			system("pause>nul && cls");  // ��ͣ���������˾�o�e��
		}

	} // end of while

	return 0;
}

// ͨ�^�Д�result��ֵ��ɵõ���ؓ�Y��
// ������呟�debug���ܣ�������result��ֵ���Д��K��ȫ�����_��Ո�ҳ������e�`���޸�
void judge(int* result)
{
	//�޸�Ϊ ��ȷ�� result ���
	if (*result == 6 || *result == 7 || *result == 11)
		printf("��Ӯ��!\n");	
	else if (*result == 5 || *result == 9 || *result == 10)
		printf("����Ӯ��!\n");
	else
		printf("ƽ��\n");
}

char toUpper(char gamer)
{
//�ԭ����ȱ�ĺ���

	if(gamer>='a'&&gamer<='z') gamer-=32;
	return gamer;
}