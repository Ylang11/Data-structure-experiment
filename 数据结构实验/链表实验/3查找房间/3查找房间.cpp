#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
typedef struct HNode
{
	char roomN[7];
	float Price;
	float PriceL;
	int Beds;
	char State[5];
	struct HNode *next;
}Hotel,*HLink;

void Build(HLink &H);//输入（客房名称、标准价格、床位数）
void Exp(HLink H);//输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态
int Find(HLink &H, char *roomN);//查找房间名称为roomN的客房

void Build(HLink &H)//输入（客房名称、标准价格、床位数）
{
	HLink p;
	HLink r;
	H = (HLink)malloc(sizeof(HNode));
	H->next = NULL;
	r = H;
	FILE *fp = fopen("ROOM.txt","r");
	printf("读取客房数据中...\n");
	while(!feof(fp))
	{
		p = (HLink)malloc(sizeof(HNode));
		fscanf(fp,"%s%f%d",p->roomN,&p->Price,&p->Beds);
		strcpy(p->State,"空闲"); 
		p->PriceL = p->Price*0.8;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	fclose(fp);
 } 
 void Exp(HLink H)//输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态
 {
 	HLink p;
 	p = H->next;
 	printf("客房信息如下：\n");
 	while(p)
 	{
 		printf("%s,%8.1f,%8.1f,%6d,%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
 		p = p->next;
	 }
  } 
  int Find(HLink &H,char *roomN)//查找房间名称为roomN的客房
  {
  	HLink p;
  	int b,c=0;
  	p = H->next;
  	printf("正在查询%s房间，请稍后...",roomN);
  	while(p)
  	{
  		b = strcmp(roomN,p->roomN);
  		p = p->next;
  		c++;
  		if(b == 0)
  		break;
	  }
	  if(c >= 1) 
	  return c;
	  else
	  return 0;
  }
  int main()
  {
  	int a;
	char x[7]; 
  	HLink L; 
	Build(L);
	printf("请检查数据\n");
	Exp(L);
	printf("请输入所需查找的房间号:");
	scanf("%s",x); 
	a = Find(L,x);
	printf("\n");
	printf("房间%s位于第%d号房",x,a);
	return 0;
   } 
