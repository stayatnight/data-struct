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
	struct  Lnode *next;/*表示next为指向struct Node数据类型的数据的指针 就像int*next表示next指向int类型的数据一样*/
	int x;

}LNode;
LNode*create_LinkList(void)/* 头插入法创建单链表,链表的头结点head作为返回值*/
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