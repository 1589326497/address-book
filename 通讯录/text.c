/*
	ͨѶ¼c������ϰ 2022��4��29�տ�ʼ 2022��5��3�����
*/
#include"contact.h"
//ͨѶ¼���1000����Ϣ
//ÿ���˵���Ϣ
//���� ���� �Ա� �绰 ��ַ
//ͨѶ¼�˳�ʱ ����Ϣд���ļ�
//ͨѶ¼��ʼ��ʱ ����Ϣ����
void menu()
{
	printf("*********************************\n");
	printf("*******  1.add   2.del  *********\n");//���� ɾ��
	printf("*******  3.search 4.modify ******\n");//���� ��
	printf("*******  5.sorrt  6.print *******\n");//���� ��ӡ��ʾ
	printf("*******  0.exit           *******\n");//�˳�
	printf("*********************************\n");
}
enum Option
{
	EXAT,
	ADD,
	DAL,
	SEARCH,
	MODIFY,
	SORRT,
	PRINT,
};
int main()
{
	int input = 0;
	Contact con;//ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:    
							//������ϵ��
			ADDContact(&con);
			break;
		case DAL:    
							//ɾ����ϵ��
			DALContact(&con);
			break;
		case SEARCH:	
							//������ϵ��
			SearchContact(&con);
			break;
		case MODIFY:	
							//�޸���ϵ��
			MODIFYContac(&con);
			break;
		case SORRT://������ϵ��
			break;
		case PRINT:  
			                //��ӡ��ϵ��
			PRINTContact(&con);
			break;
		case EXAT:         
			SzveContact(&con);
			                  //�˳�
			EXATContac(&con);       
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (1);
	return 0;
}