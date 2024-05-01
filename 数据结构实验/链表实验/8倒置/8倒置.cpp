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
 		printf("%s%8.1f%8.1f%6d%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
 		p=p->next;
	 }
  } 
   void ReverseN2(HLink &H)//将单链表的正中间位置结点之后的全部结点倒置的功能
  {
  	HLink p,r,s,t,u;
  	p = H->next;
  	r = H->next;
	u = H;	
  	while(p && p->next)
  	{
  		p = p->next->next;
  		r = r->next;
  		u = u->next;
	 }
	 s = r->next;
	 while(r->next)
	 {
	 	t = u->next;
	 	r->next = s->next;
	 	s->next = t;
        u->next = s;
        s = r->next;
	 }
	}
  int main()
  {
  	HLink L; 
	Build(L);
	printf("请检查数据\n");
	Exp(L); 
	ReverseN2(L);
	Exp(L);
	return 0;
   } 
