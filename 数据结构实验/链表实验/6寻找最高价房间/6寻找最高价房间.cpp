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
 void Delete(HLink &H,int a)//删除结点操作 
 {
 	HLink p,r;
 	p = H->next;
 	while(p->next)
 	{
 		if(p->next->PriceL == a)
		 {
		 	r = p->next;
 			p->next = r->next;
		 }
		else
		p = p->next;
	 }
	 printf("已删除价格最高的客房结点，内容如下...\n");
  } 
  HLink FirstH(HLink &H)//返回入住价格最高的客房结点指针，返回前将该结点在链表中删除
  {
  	HLink p,r;
  	int max = 0;
  	p = H->next;
  	while(p)
  	{
  		if(max <= p->PriceL)
		{
			max = p->PriceL;
			r = p;
		} 
  		p = p->next;
	}
	printf("其中入住价格最高为%d，正在进行删除操作...\n\n",max);
	Delete(H,max);
	return r;
  }
  int main()
  {
  	HLink L,p; 
	Build(L);
	printf("请检查数据\n");
	Exp(L); 
	p = FirstH(L);
	printf("%s%8.1f%8.1f%6d%8s\n\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
	Exp(L); 
	return 0;
   } 
