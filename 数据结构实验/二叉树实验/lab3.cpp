#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<math.h>
#define De(a) printf("%d ",a);
using namespace std;
const int N = 3005;
typedef struct node{
	char data;	//数据域
	struct node *lchild,*rchild;  //左右孩子指针
}BiTNode, *BiTree;   //树中结点类型
char Origin_input[N];
int siz = 0;
void CreateBiTree(BiTree &T){
	char ch;
	cin >> ch;
	Origin_input[++siz] = ch; 
	if(ch=='\n') return;
	if(ch=='#') T = NULL;//递归结束，建空树
	else
	{
		T = new BiTNode;
		T->data = ch;//生成根节点
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void PreOrderTraverse(BiTree &T)
{
	if(T==NULL) return;
	else
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree &T)
{
	if(T==NULL) return;
	else
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree &T)
{
	if(T==NULL) return;
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
}
void FloorTraverse(BiTree T)
{
	BiTree *queue = new BiTree[256];
	int front = 0, rear = 0;
	queue[rear++] = T;
	while(rear!=front)
	{
		T = queue[front];
		printf("%c",T->data);
		front++;
		if(T->lchild!=NULL) queue[rear++] = T->lchild;
		if(T->rchild!=NULL) queue[rear++] = T->rchild;
	}
	
}
void FindPath(BiTree T,char target_val,char (&path)[],int depth)
{
	path[depth] = T->data;
	if(target_val == T->data)
	{
		for(int i=1;i<=depth;i++)
			cout<<path[i];			
		cout << '\n';
		return;
	}
	if(T->lchild) FindPath(T->lchild,target_val,path,depth+1); 
	if(T->rchild) FindPath(T->rchild,target_val,path,depth+1); 
}
void debug()
{
	
}
int main()
{
	//debug();	
	//ABC##DE#G##F###
	int op;
	BiTree T;
	char path[300];
	while(1)
	{
		printf("请选择功能\n");
		printf("1．建立二叉树存储结构\n");
		printf("2．求二叉树的先序遍历\n");
		printf("3．求二叉树的中序遍历\n");
		printf("4．求二叉树的后序遍历\n");
		printf("5．求二叉树的层次遍历\n");
		printf("6．求给定结点的路径\n");
		printf("0．退出管理系统\n");
		scanf("%d",&op);

		if(op == 1)
		{
			printf("请输入二叉树先序序列，每个结点用字母表示，空结点用#表示\n");
			siz = 0;
			CreateBiTree(T);
		}
		else if(op == 2)
		{
			printf("先序遍历为：");
			PreOrderTraverse(T);
			cout << '\n';
		}
		else if(op == 3)
		{
			printf("中序遍历为：");
			InOrderTraverse(T);
			cout << '\n';
		}
		else if(op == 4)
		{
			printf("后序遍历为：");
			PostOrderTraverse(T);
			cout << '\n';
		}
		else if(op == 5)
		{
			printf("层次遍历为：");
			FloorTraverse(T);
			cout << '\n';
		}
		else if(op == 6)
		{
			printf("请输入欲查找的结点：");
			char x;
			scanf("\n%c",&x);
			int flag = 0;
			for(int i=1;i<=siz;i++)
				flag |= (Origin_input[i]==x);
			if(!flag) 
			{
				printf("不是一个合法结点！\n");
				continue;
			}
			printf("所求路径为：");
			FindPath(T,x,path,1);
			printf("\n");
		}
		else if(op == 0)
			break;
		else 
			printf("请输入正确指令！\n");
	}	
	return 0;
}
