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
	printf("�˵�����:\n");
	printf("\n");
	printf("***************************\n");
	printf("1--�����������洢�ṹ\n");
	printf("\n");
	printf("***************************\n");
	printf("2--����������������\n"); 
	printf("\n");
	printf("***************************\n");
	printf("3--����������������\n");
	printf("\n");
	printf("***************************\n");
	printf("4--��������ĺ������\n");
	printf("\n");
	printf("***************************\n");
	printf("5--��������Ĳ�α���\n");
	printf("\n");
	printf("***************************\n");
	printf("6--���������·��\n");
	printf("\n");
	printf("***************************\n");
	printf("0--�˳�ϵͳ\n");
	printf("\n��ѡ��˵���Ŀ(���� 1-5)�� ");
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
			printf("error!�����������ȷ����˵����֣�0-5��\n");
			break;
		}
			printf("\n�Ƿ�������в������ǣ������루1-5�����������루0��\n");
			scanf("%d",&x);
	}
	return 0;
}

