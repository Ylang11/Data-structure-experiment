#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  node{
	char data;
	struct node *lchild ,  *rchild;
}BinTNode, *BinTree;
void PreOrderTraverse(BinTree &tree)
{
	if(tree = NULL)
		return 1;
	else
	{
		printf("%c",tree->data);
		PreOrderTraverse(tree->lchild);
		PreOrderTraverse(tree->rchild);
	}
}
