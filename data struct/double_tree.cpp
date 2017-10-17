#include "stdafx.h"

#include <iostream>
using namespace std;


//-----------------------
#define ELEM char

typedef struct tNode
{
	ELEM data;
	tNode* left;
	tNode* right;
}tNode;

typedef tNode *pTree, *pNode;
//------------------------

/* �����ȸ�������˳��������롣�򵥵����õݹ鷽ʽʵ�֡�*/

pTree createTree(pTree t)
{
	cout << "���ǰ����������˳�� ����������ڵ�" << endl;
	ELEM a;
	cin >> a;

	// �������#��Ϊ��
	if (a != '#')//�����Ϊ�գ�������ڴ棬����ʼ��
	{
		t = new tNode;//����ڵ�ռ�
		t->data = a;//��ʼ���ڵ�
		t->left = NULL;
		t->right = NULL;

		t->left = createTree(t->left);	//����������//=======ע����t->left ���ܷ���ָ��
		t->right = createTree(t->right);//����������

	}

	return t;
}



//==========  �ݹ���ʽ�ģ����ֱ�������  =================

/*�����ȸ����������з���*/
inline void visit(pTree t) { cout << t->data << "   "; }

void preOrder(pTree t)
{
	//�ж�t �Ƿ�Ϊ�գ����Ϊ�գ����أ������Ϊ�գ�����
	if (NULL == t)
	{
		return;
	}
	else
	{
		visit(t);//���ʸ�Ԫ��
		preOrder(t->left);//�������������
		preOrder(t->right);//�������������
	}
}


void inOrder(pTree t)
{
	//�ж�t�Ƿ�Ϊ��
	if (t == NULL)
	{
		return;
	}
	else
	{
		inOrder(t->left);
		visit(t);
		inOrder(t->right);
	}

}

void postOrder(pTree t)
{
	//�ж�t�Ƿ�Ϊ��
	if (t == NULL)
	{
		return;
	}
	else
	{
		postOrder(t->left);
		postOrder(t->right);
		visit(t);
	}
}
//===========================================


/************************************************************************/
/* �ǵݹ���ʽ����������
*/
/*�ǵݹ������������ȷ��ʸ��ڵ㣬Ȼ������֦һֱ�ߣ�һ����һ�߷��ʽڵ�,ֱ��������������
���ڴ˹����У���������ڵ������������Ҳ�Ϊ�գ�������ջ�����������ڵ�û������ʱ����ջ����
�����Ϸ�ʽ���б���,ֱ��ջΪ��*/
void preOrder2(pTree t)
{
	pTree stackTree[100];//���ڴ洢��������ָ��
	pTree p = t;

	int num = -1;//ջ��

	do
	{
		/*������֦��һֱ���ʣ���䣬������������Ϊ�յľͽ�վ*/

		while (p)
		{

			visit(p);// ���ʽڵ�


			if (p->right)// ������������Ϊ�գ���վ
			{
				stackTree[++num] = p->right;//��������վ

			}
			p = p->left;// �ƶ���������

		}

		/*��ջ����������������*/

		if (num >= 0)
		{
			p = stackTree[num--];
		}

	} while (p || num >= 0);// ֻҪ�������ǿգ�����ջ���нڵ㣬������ѭ������
							//++++++++++++ while (p );//????ΪʲôҪ�ڴ˼���


							// delete stackTree; //+++++++++++++????����ͷž�̬����

}

/*�ǵݹ��������˼�룺
������֦��һֱ�ߣ����ѽڵ���ջ��ֱ�������սڵ㡣���ڵ��ջ�����з��ʣ������մ˲��跴������������
ֱ��ջ�������ݡ�*/
void inOrder2(pTree t)
{
	pTree strackTree[100];//���ڴ洢�ڵ�
	int  top = -1;//ջ��

	pTree p = t;// ����ʱ������ȥ�޸ĸ��ڵ㡣
	do
	{
		/*������֦��һֱ�ߣ������ڵ�ͽ�վ��ֱ�������սڵ�*/
		while (p)
		{
			strackTree[++top] = p;//�ڵ��վ
			p = p->left;//

		}

		if (top >= 0)
		{
			p = strackTree[top--];//������Ϊ�գ���ջ
			visit(p);//���ʳ�ջ�Ľڵ�
			p = p->right;
		}


	} while (p || top >= 0);//����������Ϊ�գ����� ջ�л������ݣ��ͽ���ѭ��



}
/************************************************************************/


int main(int argc, char* argv[])
{
	printf("ͬѧ�Ǻã� ����һ����������¹������ܼ� :\n");

	
	pTree a;
	pTree b;
	pTree c;

	a = new tNode;
	b = new tNode;
	c = new tNode;

	a->data = 'a';
	b->data = 'b';
	c->data = 'c';

	a->left  = NULL;
	a->right = b;
	b->left =c;
	b->right = NULL;
	c->left = NULL;
	c->right = NULL;
	
	pTree t = NULL;

	
	

	//---------  �ݹ��㷨���б���  ---------------
	cout << endl << endl << "------>������� ��" << endl;

	preOrder(a);
	//------------------------
	cout << endl << "------>������� ��" << endl;

	inOrder(a);
	//------------------------
	cout << endl << "------>������� ��" << endl;

	postOrder(a);

	//------------------------
	cout << endl << "----->������� ��" << endl;

	preOrder2(a);
	//------------------------
	cout << endl << "------>������� ��" << endl;

	inOrder2(a);


	system("pause");

	return 0;
}