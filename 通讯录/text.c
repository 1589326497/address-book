/*
	通讯录c语言练习 2022年4月29日开始 2022年5月3日完成
*/
#include"contact.h"
//通讯录存放1000个信息
//每个人的信息
//名字 年龄 性别 电话 地址
//通讯录退出时 把信息写到文件
//通讯录初始化时 吧信息加载
void menu()
{
	printf("*********************************\n");
	printf("*******  1.add   2.del  *********\n");//增加 删除
	printf("*******  3.search 4.modify ******\n");//查找 改
	printf("*******  5.sorrt  6.print *******\n");//排序 打印显示
	printf("*******  0.exit           *******\n");//退出
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
	Contact con;//通讯录
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:    
							//增加联系人
			ADDContact(&con);
			break;
		case DAL:    
							//删除联系人
			DALContact(&con);
			break;
		case SEARCH:	
							//查找联系人
			SearchContact(&con);
			break;
		case MODIFY:	
							//修改联系人
			MODIFYContac(&con);
			break;
		case SORRT://排序联系人
			break;
		case PRINT:  
			                //打印联系人
			PRINTContact(&con);
			break;
		case EXAT:         
			SzveContact(&con);
			                  //退出
			EXATContac(&con);       
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (1);
	return 0;
}