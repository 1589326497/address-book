#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFFAULT 3          //默认大小
#define INC 2               //空间不够时增加的大小

//定义类型
typedef struct Peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Peoinfo;


//通讯录
//typedef struct Contact
//{
//	Peoinfo data[MAX];//创建通讯录
//	int sz;//通讯录中的元素
//}Contact;


//动态版本 通讯录
typedef struct Contact
{
	Peoinfo* data;//记录动态内存的起始地址
	int sz;//记录当前通讯录的有效个数
	int ca;//记录动态内存的最大容量
 }Contact;


//初始化通讯录
void InitContact(Contact* pc);
//增加联系人
void ADDContact(Contact* pc);
//打印联系人信息
void PRINTContact(Contact* pc);
//删除联系人
void DALContact(Contact* pc);
//查找联系人
void SearchContact(Contact* pc);
//修改联系人
void MODIFYContac(Contact* pc);
//退出通讯录
void EXATContac(Contact* pc);
//保存通讯录信息到文件
void SzveContact(Contact* pc);
//加载文件
void LoadContact(Contact* pc);
//增加容量
void CheakCapacity(Contact* pc);