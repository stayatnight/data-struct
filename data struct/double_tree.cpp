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

/* 利用先根遍历的顺序进行输入。简单的利用递归方式实现。*/

pTree createTree(pTree t)
{
	cout << "我们按先序遍历的顺序 输入二叉树节点" << endl;
	ELEM a;
	cin >> a;

	// 如果遇到#树为空
	if (a != '#')//如果不为空，则分配内存，并初始化
	{
		t = new tNode;//分配节点空间
		t->data = a;//初始化节点
		t->left = NULL;
		t->right = NULL;

		t->left = createTree(t->left);	//建立左子树//=======注意用t->left 接受返回指针
		t->right = createTree(t->right);//建立右子树

	}

	return t;
}



//==========  递归形式的，各种遍历方法  =================

/*利用先根遍历，进行访问*/
inline void visit(pTree t) { cout << t->data << "   "; }

void preOrder(pTree t)
{
	//判断t 是否为空，如果为空，返回；如果不为空，访问
	if (NULL == t)
	{
		return;
	}
	else
	{
		visit(t);//访问根元素
		preOrder(t->left);//先序遍历左子树
		preOrder(t->right);//先序遍历右子树
	}
}


void inOrder(pTree t)
{
	//判断t是否为空
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
	//判断t是否为空
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
/* 非递归形式遍历二叉树
*/
/*非递归的先序遍历，先访问根节点，然后沿左枝一直走，一边走一边访问节点,直到遇到空子树。
（在此过程中，如果遇到节点有右子树，且不为空，进行入栈）。但遇到节点没有左孩子时，出栈，按
照以上方式进行遍历,直到栈为空*/
void preOrder2(pTree t)
{
	pTree stackTree[100];//用于存储右子树的指针
	pTree p = t;

	int num = -1;//栈顶

	do
	{
		/*沿着左枝，一直访问，其间，遇到右子树不为空的就进站*/

		while (p)
		{

			visit(p);// 访问节点


			if (p->right)// 遇到右子树不为空，进站
			{
				stackTree[++num] = p->right;//右子树进站

			}
			p = p->left;// 移动到左子树

		}

		/*出栈，进行右子树遍历*/

		if (num >= 0)
		{
			p = stackTree[num--];
		}

	} while (p || num >= 0);// 只要左子树非空，或者栈中有节点，就满足循环条件
							//++++++++++++ while (p );//????为什么要在此加上


							// delete stackTree; //+++++++++++++????如何释放静态数组

}

/*非递归中序遍历思想：
沿着左枝，一直走，并把节点入栈，直到遇到空节点。将节点出栈，进行访问，并按照此步骤反问其右子树。
直到栈中无数据。*/
void inOrder2(pTree t)
{
	pTree strackTree[100];//用于存储节点
	int  top = -1;//栈顶

	pTree p = t;// 遍历时，不能去修改根节点。
	do
	{
		/*沿着左枝，一直走，遇到节点就进站，直到遇到空节点*/
		while (p)
		{
			strackTree[++top] = p;//节点进站
			p = p->left;//

		}

		if (top >= 0)
		{
			p = strackTree[top--];//左子树为空，出栈
			visit(p);//反问出栈的节点
			p = p->right;
		}


	} while (p || top >= 0);//当左子树不为空，或者 栈中还有数据，就进行循环



}
/************************************************************************/


int main(int argc, char* argv[])
{
	printf("同学们好！ 我们一起来完成以下工作，很简单 :\n");

	
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

	
	

	//---------  递归算法进行遍历  ---------------
	cout << endl << endl << "------>先序遍历 ：" << endl;

	preOrder(a);
	//------------------------
	cout << endl << "------>中序遍历 ：" << endl;

	inOrder(a);
	//------------------------
	cout << endl << "------>后序遍历 ：" << endl;

	postOrder(a);

	//------------------------
	cout << endl << "----->先序遍历 ：" << endl;

	preOrder2(a);
	//------------------------
	cout << endl << "------>中序遍历 ：" << endl;

	inOrder2(a);


	system("pause");

	return 0;
}