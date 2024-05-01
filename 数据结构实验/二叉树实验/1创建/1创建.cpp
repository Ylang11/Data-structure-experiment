#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  node{
	char data;
	struct node *lchild ,  *rchild;
}BinTNode, *BinTree;

void CreateBiTree(BinTree &tree);//�����������洢�ṹ
void PreOrderTraverse(BinTree &tree);//����������������
void InOrderTraverse(BinTree &tree);//����������������
void PostOrderTraverse(BinTree &tree);//��������ĺ������
void LevelOrderTraverse(BinTree &tree);//��������Ĳ�α���
void Search(BinTree &tree,char p,char path[100],int depth);//���������·��

void CreateBiTree(BinTree &tree)//�����������洢�ṹ ������:ABC##DE#G##F###
{
	char t; 
	char T[100]; 
	int i = 0;
	scanf("%c",&t);
	T[++i] = t;
	if(t == '\n')
		return;
	if(t == '#')
		tree = NULL;
	else
	{
		tree = (BinTree)malloc(sizeof(node));
		tree->data = t;
		CreateBiTree(tree->lchild);
		CreateBiTree(tree->rchild);
	} 
}
void PreOrderTraverse(BinTree &tree)//����������������
{
	if(tree == NULL) 
		return;
	else
	{
		printf("%c",tree->data);
		PreOrderTraverse(tree->lchild);
		PreOrderTraverse(tree->rchild);
	}
}
void InOrderTraverse(BinTree &tree)//����������������
{
	if(tree == NULL)
		return;
	else
	{
		InOrderTraverse(tree->lchild);
		printf("%c",tree->data);
		InOrderTraverse(tree->rchild);
	}
}
void PostOrderTraverse(BinTree &tree)//��������ĺ������
{
	if(tree == NULL)
		return;
	else
	{
		PreOrderTraverse(tree->lchild);
		PreOrderTraverse(tree->rchild);
		printf("%c",tree->data);
	}
}
void LevelOrderTraverse(BinTree &tree)//��������Ĳ�α���
{
	BinTree *Queue = new BinTree[256];
	int f,r;
	f = r = 0;
	Queue[r++] = tree;
	while(r!=f)
	{
		tree = Queue[f];
		printf("%c",tree->data);
		f++;
		if(tree->lchild!=NULL)
			Queue[r++] = tree->lchild;
		if(tree->rchild!=NULL)
			Queue[r++] = tree->rchild;
	}
}
void Search(BinTree &tree,char p,char path[100],int depth)//���������·��
{
    int i;
    path[depth] = tree->data;
    if(p == tree->data)
    {
          for(int i=1;i<depth;i++)
            printf("%c -> ",path[i]);
        printf("%c",path[depth]);
        printf("\n");
        return;
    }
    if(tree->lchild)
        Search(tree->lchild,p,path,++depth);
    if(tree->rchild)
        Search(tree->rchild,p,path,++depth);
}
int main()
{
	BinTree tree;
	int x; 
	printf("�˵�����:\n");
	printf("=================================\n");
	printf("||  ��ѡ��˵���Ŀ(���� 1-7)�� ||\n");
	printf("||-----------------------------||\n");
	printf("||1--�����������洢�ṹ        ||\n");
	printf("||-----------------------------||\n");
	printf("||2--����������������        ||\n"); 
	printf("||-----------------------------||\n");
	printf("||3--����������������        ||\n");
	printf("||-----------------------------||\n");
	printf("||4--��������ĺ������        ||\n");
	printf("||-----------------------------||\n");
	printf("||5--��������Ĳ�α���        ||\n");
	printf("||-----------------------------||\n");
	printf("||6--���������·��          ||\n");
	printf("||-----------------------------||\n");
	printf("||7--�˳�ϵͳ                  ||\n");
	printf("=================================\n");
	scanf("%d",&x);
	while(x!=7)
	{
		switch(x)
		{
			case 1:
			printf("�����������������:");
			scanf("\n"); 
			CreateBiTree(tree);
			break;
			case 2:
			printf("\n");
			printf("��������������:"); 
			PreOrderTraverse(tree);
			break;
			case 3:
			printf("\n");
			printf("��������������:"); 
			InOrderTraverse(tree); 
			break;
			case 4:
			printf("\n");
			printf("��������������:"); 
			PostOrderTraverse(tree);
			break;
			case 5:
			printf("\n");
			printf("��α����������:");
			LevelOrderTraverse(tree); 
			break; 
			case 6:
			printf("\n");
			char p;
            int depth;
            char path[100];
 			printf("��������Ҫ���ҵĽ��:");
 			scanf("\n%c",&p);
 			printf("\n");
			depth = 1;
			printf("����·������:");
 			Search(tree,p,path,depth);
 			printf("\n");
			break; 
			case 7:
			printf("�˳�\n");
			break; 
			default:
			printf("error!�����������ȷ����˵����֣�1-7��\n");
			break;
		}
		printf("\n�Ƿ�������в������ǣ������루1-7�����������루7��\n");
		printf("=================================\n");
		printf("||  ��ѡ��˵���Ŀ(���� 1-7)�� ||\n");
		printf("||-----------------------------||\n");
		printf("||1--�����������洢�ṹ        ||\n");
		printf("||-----------------------------||\n");
		printf("||2--����������������        ||\n"); 
		printf("||-----------------------------||\n");
		printf("||3--����������������        ||\n");
		printf("||-----------------------------||\n");
		printf("||4--��������ĺ������        ||\n");
		printf("||-----------------------------||\n");
		printf("||5--��������Ĳ�α���        ||\n");
		printf("||-----------------------------||\n");
		printf("||6--���������·��          ||\n");
		printf("||-----------------------------||\n");
		printf("||7--�˳�ϵͳ                  ||\n");
		printf("=================================\n");
		scanf("%d",&x);
	}
	return 0;
}
