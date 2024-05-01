#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  node{
    char data;
    struct node *lchild ,  *rchild;
}BinTNode, *BinTree;
void  CreateBiTree(BinTree &tree)//ABC##DE#G##F###
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
void Search(BinTree &tree,char p,char path[100],int depth)
{
    int i;
    path[depth] = tree->data;
    if(p == tree->data)
    {
        for(i=1;i<=depth;i++)
            printf("%c",path[i]);        
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
            printf("请输入二叉树的内容:");
            CreateBiTree(tree);
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
 return 0;
} 
