#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<math.h>
#define De(a) printf("%d ",a);
using namespace std;
const int N = 3005;
typedef struct node{
	char data;	//������
	struct node *lchild,*rchild;  //���Һ���ָ��
}BiTNode, *BiTree;   //���н������
char Origin_input[N];
int siz = 0;
void CreateBiTree(BiTree &T){
	char ch;
	cin >> ch;
	Origin_input[++siz] = ch; 
	if(ch=='\n') return;
	if(ch=='#') T = NULL;//�ݹ������������
	else
	{
		T = new BiTNode;
		T->data = ch;//���ɸ��ڵ�
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
		printf("��ѡ����\n");
		printf("1�������������洢�ṹ\n");
		printf("2������������������\n");
		printf("3������������������\n");
		printf("4����������ĺ������\n");
		printf("5����������Ĳ�α���\n");
		printf("6�����������·��\n");
		printf("0���˳�����ϵͳ\n");
		scanf("%d",&op);

		if(op == 1)
		{
			printf("������������������У�ÿ���������ĸ��ʾ���ս����#��ʾ\n");
			siz = 0;
			CreateBiTree(T);
		}
		else if(op == 2)
		{
			printf("�������Ϊ��");
			PreOrderTraverse(T);
			cout << '\n';
		}
		else if(op == 3)
		{
			printf("�������Ϊ��");
			InOrderTraverse(T);
			cout << '\n';
		}
		else if(op == 4)
		{
			printf("�������Ϊ��");
			PostOrderTraverse(T);
			cout << '\n';
		}
		else if(op == 5)
		{
			printf("��α���Ϊ��");
			FloorTraverse(T);
			cout << '\n';
		}
		else if(op == 6)
		{
			printf("�����������ҵĽ�㣺");
			char x;
			scanf("\n%c",&x);
			int flag = 0;
			for(int i=1;i<=siz;i++)
				flag |= (Origin_input[i]==x);
			if(!flag) 
			{
				printf("����һ���Ϸ���㣡\n");
				continue;
			}
			printf("����·��Ϊ��");
			FindPath(T,x,path,1);
			printf("\n");
		}
		else if(op == 0)
			break;
		else 
			printf("��������ȷָ�\n");
	}	
	return 0;
}
