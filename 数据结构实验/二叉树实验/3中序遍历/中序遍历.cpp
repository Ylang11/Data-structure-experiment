#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  node{
	char data;
	struct node *lchild ,  *rchild;
}BinTNode, *BinTree;
void InOrderTraverse(BinTree &tree)
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
