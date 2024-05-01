#include<stdio.h> 
typedef struct  node{
	char data;
	struct node *lchild ,  *rchild;
}BinTNode, *BinTree;
int main()
{
	int i,j,x,pos;
	printf("\n");
	printf("\n");
	printf("菜单如下:\n");
	printf("\n");
	printf("***************************\n");
	printf("1--建立二叉树存储结构\n");
	printf("\n");
	printf("***************************\n");
	printf("2--求二叉树的先序遍历\n"); 
	printf("\n");
	printf("***************************\n");
	printf("3--求二叉树的中序遍历\n");
	printf("\n");
	printf("***************************\n");
	printf("4--求二叉树的后序遍历\n");
	printf("\n");
	printf("***************************\n");
	printf("5--求二叉树的层次遍历\n");
	printf("\n");
	printf("***************************\n");
	printf("6--求给定结点的路径\n");
	printf("\n");
	printf("***************************\n");
	printf("0--退出系统\n");
	printf("\n请选择菜单项目(输入 1-5)： ");
	scanf("%d",&x);
	while(x!=5)
	{
		switch(x)
		{
			case 1:
		 
			break;
			case 2:
			
			break;
			case 3:
			
			break;
			case 4:
			
			break;
			case 5:
			
			break; 
			default:
			printf("error!输入错误，请正确输入菜单数字（0-5）\n");
			break;
		}
			printf("\n是否继续进行操作，是：请输入（1-5），否：请输入（0）\n");
			scanf("%d",&x);
	}
	return 0;
}

