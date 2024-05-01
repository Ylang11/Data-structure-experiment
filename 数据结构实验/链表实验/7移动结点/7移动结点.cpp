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
void Build(HLink &H)//���루�ͷ����ơ���׼�۸񡢴�λ����
{
	HLink p;
	HLink r;
	H = (HLink)malloc(sizeof(HNode));
	H->next = NULL;
	r = H;
	FILE *fp = fopen("ROOM.txt","r");
	printf("��ȡ�ͷ�������...\n");
	while(!feof(fp))
	{
		p = (HLink)malloc(sizeof(HNode));
		fscanf(fp,"%s%f%d",p->roomN,&p->Price,&p->Beds);
		strcpy(p->State,"����"); 
		p->PriceL = p->Price*0.8;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	fclose(fp);
 } 
 void Exp(HLink H)//������пͷ��Ŀͷ����ơ���׼�۸���ס�۸񡢴�λ������ס״̬
 {
 	HLink p;
 	p = H->next;
 	printf("�ͷ���Ϣ���£�\n");
 	while(p)
 	{
 		printf("%s%8.1f%8.1f%6d%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
 		p=p->next;
	 }
  } 
  void MoveK1(HLink &H, int k)//���������е�����k������Ƶ���һ�����λ��
  {
  	HLink p,r,s;
  	p = H->next;
  	r = H->next;
  	s = H;
  	while(k--)
  	p = p->next;
  	while(p->next)
  	{
  		p = p->next;
  		r = r->next;
  		s = s->next; 			
  		if(!(p->next))
  		{
  			s->next = r->next;
  			r->next = H->next;
  			H->next = r;
		  }
	  }
  }
  int main()
  {
  	int a;
  	HLink L; 
	Build(L);
	printf("��������\n");
	Exp(L); 
	printf("�����뵹�ڼ��������Ҫ�Ƶ���һ�����λ��:");
	scanf("%d",&a);
	MoveK1(L,a);
	Exp(L);
	return 0;
   } 
