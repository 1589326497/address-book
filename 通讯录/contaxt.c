#include"contact.h"、
//静态版本
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态版本   默认空间3 之后以此开辟2

void InitContact(Contact* pc)
{
	pc->data = (Peoinfo*)malloc(DEFFAULT * sizeof(Peoinfo));
		if (pc->data == NULL)
		{
			perror("InitContact");
			return;
		}
	pc->sz = 0;
	pc->ca = DEFFAULT;
	//加载文件
	LoadContact(pc);
}
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contat.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		printf("通讯录为空\n");
		return;
	}
	//读文件
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pf))//fread的返回值是实际上读取的个数
	{
		CheakCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;  
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}


//静态版本
//void ADDContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录以满，无法添加\n");
//		return;
//	}
//	printf("输入名字：");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("输入年龄：");
//	scanf("%d", &pc->data[pc->sz].age);
//	printf("输入性别");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("输入电话");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("输入地址");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("增加成功");
//}

 //动态版本
 void CheakCapacity(Contact* pc)
{
	if (pc->sz == pc->ca)       //增容
	{
		Peoinfo* car = (Peoinfo*)realloc(pc->data, (pc->ca + INC) * sizeof(Peoinfo));
		if (car != NULL)
		{
			pc->data = car;
			pc->ca += INC;
		}
		else
		{
			perror("ADDContact");
			printf("增加联系人失败");
			return;
		}
	}
}
void ADDContact(Contact* pc)
{
	CheakCapacity(pc);
	printf("输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("输入性别");
	scanf("%s", pc->data[pc->sz].sex);
	printf("输入电话");
	scanf("%s", pc->data[pc->sz].tele);
	printf("输入地址");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加成功");
}


void PRINTContact(Contact* pc)
{
	printf("%20s %10s %10s %30s %20s\n", "名字", "年龄", "性别", "电话", "地址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%20s %10d %10s %30s %20s\n",
			pc->data[i].name,
			pc->data[i].age, 
			pc->data[i].sex, 
			pc->data[i].tele, 
			pc->data[i].addr );
	}
}
 static int FindByName(Contact* pc, char name[])//查找函数
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DALContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，不需要删除");
		return;
	}
	char name[MAX_NAME] = {0};
	printf("输入要查找的人：");
	scanf("%s", &name);
	//查找要删除的人
	int pos=FindByName(pc,name);
	if (pos == -1)
	{
		printf("没有查询到");
		return;
	}
	//删除
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功");
}
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("输入要查找的人：");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("没有查询到");
		return;
	}
	else
	{
		printf("%20s %10s %10s %30s %20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%20s %10d %10s %30s %20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr
		                          );
	}
}
void MODIFYContac(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("输入要修改的人：");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("没有查询到");
		return;
	}
	else
	{
		printf("输入名字：");
		scanf("%s", pc->data[pos].name);
		printf("输入年龄：");
		scanf("%d", &pc->data[pos].age);
		printf("输入性别");
		scanf("%s", pc->data[pos].sex);
		printf("输入电话");
		scanf("%s", pc->data[pos].tele);
		printf("输入地址");
		scanf("%s", pc->data[pos].addr);

	}
}
void EXATContac(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->ca = 0;
	printf("以退出");
}
void SzveContact(Contact* pc)
{
	FILE* pf=fopen("contat.dat", "w");
	if (pf == NULL)
	{
		perror("SzveContact");
		return 1;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(Peoinfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}