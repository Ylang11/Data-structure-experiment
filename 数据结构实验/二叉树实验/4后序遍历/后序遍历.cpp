#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  node{
	char data;
	struct node *lchild ,  *rchild;
}BinTNode, *BinTree;
void PostOrderTraverse(BinTree &tree)
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
