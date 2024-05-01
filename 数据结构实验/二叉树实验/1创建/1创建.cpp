#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  node{
	char data;
	struct node *lchild ,  *rchild;
}BinTNode, *BinTree;

void CreateBiTree(BinTree &tree);//建立二叉树存储结构
void PreOrderTraverse(BinTree &tree);//求二叉树的先序遍历
void InOrderTraverse(BinTree &tree);//求二叉树的中序遍历
void PostOrderTraverse(BinTree &tree);//求二叉树的后序遍历
void LevelOrderTraverse(BinTree &tree);//求二叉树的层次遍历
void Search(BinTree &tree,char p,char path[100],int depth);//求给定结点的路径

void CreateBiTree(BinTree &tree)//建立二叉树存储结构 二叉树:ABC##DE#G##F###
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
void PreOrderTraverse(BinTree &tree)//求二叉树的先序遍历
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
void InOrderTraverse(BinTree &tree)//求二叉树的中序遍历
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
void PostOrderTraverse(BinTree &tree)//求二叉树的后序遍历
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
void LevelOrderTraverse(BinTree &tree)//求二叉树的层次遍历
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
void Search(BinTree &tree,char p,char path[100],int depth)//求给定结点的路径
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
	printf("菜单如下:\n");
	printf("=================================\n");
	printf("||  请选择菜单项目(输入 1-7)： ||\n");
	printf("||-----------------------------||\n");
	printf("||1--建立二叉树存储结构        ||\n");
	printf("||-----------------------------||\n");
	printf("||2--求二叉树的先序遍历        ||\n"); 
	printf("||-----------------------------||\n");
	printf("||3--求二叉树的中序遍历        ||\n");
	printf("||-----------------------------||\n");
	printf("||4--求二叉树的后序遍历        ||\n");
	printf("||-----------------------------||\n");
	printf("||5--求二叉树的层次遍历        ||\n");
	printf("||-----------------------------||\n");
	printf("||6--求给定结点的路径          ||\n");
	printf("||-----------------------------||\n");
	printf("||7--退出系统                  ||\n");
	printf("=================================\n");
	scanf("%d",&x);
	while(x!=7)
	{
		switch(x)
		{
			case 1:
			printf("请输入二叉树的内容:");
			scanf("\n"); 
			CreateBiTree(tree);
			break;
			case 2:
			printf("\n");
			printf("先序遍历结果如下:"); 
			PreOrderTraverse(tree);
			break;
			case 3:
			printf("\n");
			printf("中序遍历结果如下:"); 
			InOrderTraverse(tree); 
			break;
			case 4:
			printf("\n");
			printf("后序遍历结果如下:"); 
			PostOrderTraverse(tree);
			break;
			case 5:
			printf("\n");
			printf("层次遍历结果如下:");
			LevelOrderTraverse(tree); 
			break; 
			case 6:
			printf("\n");
			char p;
            int depth;
            char path[100];
 			printf("请输入需要查找的结点:");
 			scanf("\n%c",&p);
 			printf("\n");
			depth = 1;
			printf("查找路径如下:");
 			Search(tree,p,path,depth);
 			printf("\n");
			break; 
			case 7:
			printf("退出\n");
			break; 
			default:
			printf("error!输入错误，请正确输入菜单数字（1-7）\n");
			break;
		}
		printf("\n是否继续进行操作，是：请输入（1-7），否：请输入（7）\n");
		printf("=================================\n");
		printf("||  请选择菜单项目(输入 1-7)： ||\n");
		printf("||-----------------------------||\n");
		printf("||1--建立二叉树存储结构        ||\n");
		printf("||-----------------------------||\n");
		printf("||2--求二叉树的先序遍历        ||\n"); 
		printf("||-----------------------------||\n");
		printf("||3--求二叉树的中序遍历        ||\n");
		printf("||-----------------------------||\n");
		printf("||4--求二叉树的后序遍历        ||\n");
		printf("||-----------------------------||\n");
		printf("||5--求二叉树的层次遍历        ||\n");
		printf("||-----------------------------||\n");
		printf("||6--求给定结点的路径          ||\n");
		printf("||-----------------------------||\n");
		printf("||7--退出系统                  ||\n");
		printf("=================================\n");
		scanf("%d",&x);
	}
	return 0;
}
