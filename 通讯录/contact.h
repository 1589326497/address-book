#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFFAULT 3          //Ĭ�ϴ�С
#define INC 2               //�ռ䲻��ʱ���ӵĴ�С

//��������
typedef struct Peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Peoinfo;


//ͨѶ¼
//typedef struct Contact
//{
//	Peoinfo data[MAX];//����ͨѶ¼
//	int sz;//ͨѶ¼�е�Ԫ��
//}Contact;


//��̬�汾 ͨѶ¼
typedef struct Contact
{
	Peoinfo* data;//��¼��̬�ڴ����ʼ��ַ
	int sz;//��¼��ǰͨѶ¼����Ч����
	int ca;//��¼��̬�ڴ���������
 }Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//������ϵ��
void ADDContact(Contact* pc);
//��ӡ��ϵ����Ϣ
void PRINTContact(Contact* pc);
//ɾ����ϵ��
void DALContact(Contact* pc);
//������ϵ��
void SearchContact(Contact* pc);
//�޸���ϵ��
void MODIFYContac(Contact* pc);
//�˳�ͨѶ¼
void EXATContac(Contact* pc);
//����ͨѶ¼��Ϣ���ļ�
void SzveContact(Contact* pc);
//�����ļ�
void LoadContact(Contact* pc);
//��������
void CheakCapacity(Contact* pc);