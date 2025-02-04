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
  int Length(HLink H)
  {
  	int length;
  	HLink p;
  	p = H->next;
  	while(p->next)
  	{
  		p = p->next;
  		length++;
	  }
	  return length;
  }
  void SortPriceL(HLink &H)//升序排序 
  {
	HLink p,r,s;
	int length,i,j;
	length = Length(H);
	for(i = 0; i<length; i++)
	{
		p = H->next;
		s = H;
		for(j = 0; j<length-i && p != NULL; j++)
		{
			r = p->next;
			if(p->next == NULL) continue;
			if(p->PriceL > r->PriceL && (strcmp(p->roomN,r->roomN)))
			{
				p->next = r->next;
				r->next = p;
				s->next = r;
				s = r;
			}
			else
			{
				s = p;
				p = p->next;
			}
		}
	}
  }
  int main()
  {
  	HLink L;
	Build(L);
	printf("请检查数据\n");
	Exp(L);
	SortPriceL(L);
	Exp(L);
	return 0;
   } 
