#include"stdafx.h"
#include<stdio.h>
#include"iostream"
using namespace std;
#include<stdlib.h>
#define MAX_SIZE 100
#define FLASE 0;
#define TRUE 1;
typedef struct Lnode
{
	struct  Lnode *next;/*��ʾnextΪָ��struct Node�������͵����ݵ�ָ�� ����int*next��ʾnextָ��int���͵�����һ��*/
	int x;

}LNode;
LNode*create_LinkList(void)/* ͷ���뷨����������,�����ͷ���head��Ϊ����ֵ*/
{
	int data, n;
	LNode*head, *p;
	head = (LNode*)malloc(sizeof(LNode*));
	head->next = NULL;
	cout << "please input number" << endl;
	cin >> n;
	cout << "please input value" << endl;
	for (int i = 0; i < n; i++)
	{   
		cin >> data;
		if (data == 32767)  break;
		p = (LNode*)malloc(sizeof(LNode*));
		p->x = data;
		p->next = head->next;
		head->next = p;
	}


	return 0;
}
int main()
{
	
	LNode*create_LinkList(void);
	system("pause");
	return 0;

}