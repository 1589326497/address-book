#include"contact.h"��
//��̬�汾
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬�汾   Ĭ�Ͽռ�3 ֮���Դ˿���2

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
	//�����ļ�
	LoadContact(pc);
}
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contat.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	//���ļ�
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, pf))//fread�ķ���ֵ��ʵ���϶�ȡ�ĸ���
	{
		CheakCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;  
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


//��̬�汾
//void ADDContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	printf("�������֣�");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("�������䣺");
//	scanf("%d", &pc->data[pc->sz].age);
//	printf("�����Ա�");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("����绰");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�����ַ");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("���ӳɹ�");
//}

 //��̬�汾
 void CheakCapacity(Contact* pc)
{
	if (pc->sz == pc->ca)       //����
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
			printf("������ϵ��ʧ��");
			return;
		}
	}
}
void ADDContact(Contact* pc)
{
	CheakCapacity(pc);
	printf("�������֣�");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������䣺");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�����Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����绰");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�����ַ");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ�");
}


void PRINTContact(Contact* pc)
{
	printf("%20s %10s %10s %30s %20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
 static int FindByName(Contact* pc, char name[])//���Һ���
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
		printf("ͨѶ¼Ϊ�գ�����Ҫɾ��");
		return;
	}
	char name[MAX_NAME] = {0};
	printf("����Ҫ���ҵ��ˣ�");
	scanf("%s", &name);
	//����Ҫɾ������
	int pos=FindByName(pc,name);
	if (pos == -1)
	{
		printf("û�в�ѯ��");
		return;
	}
	//ɾ��
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�");
}
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("����Ҫ���ҵ��ˣ�");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("û�в�ѯ��");
		return;
	}
	else
	{
		printf("%20s %10s %10s %30s %20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("����Ҫ�޸ĵ��ˣ�");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("û�в�ѯ��");
		return;
	}
	else
	{
		printf("�������֣�");
		scanf("%s", pc->data[pos].name);
		printf("�������䣺");
		scanf("%d", &pc->data[pos].age);
		printf("�����Ա�");
		scanf("%s", pc->data[pos].sex);
		printf("����绰");
		scanf("%s", pc->data[pos].tele);
		printf("�����ַ");
		scanf("%s", pc->data[pos].addr);

	}
}
void EXATContac(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->ca = 0;
	printf("���˳�");
}
void SzveContact(Contact* pc)
{
	FILE* pf=fopen("contat.dat", "w");
	if (pf == NULL)
	{
		perror("SzveContact");
		return 1;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(Peoinfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}