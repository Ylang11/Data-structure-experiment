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
  void upBed(HLink &H,int beds)
  {
  	int length,i;
  	HLink p,s,l,r,L;
  	p = (HLink)malloc(sizeof(HNode));
  	L = (HLink)malloc(sizeof(HNode));
  	L->next =NULL;
  	p->Beds = beds;
  	printf("�������·���ķ�������");
  	scanf("%s",p->roomN);
	printf("�������·���ı�׼�۸�");
	scanf("%f",&p->Price);
	p->PriceL = p->Price*0.8; 
	printf("�������·������ס״̬��");
	scanf("%s",p->State);
	p->next = H->next;
	H->next = p;
	length = Length(H);
	printf("����1\n");
	s = H->next;
	r = H;
	l = L;
	for(i = 0; i<length+1 && s != NULL; i++)
	{
		if (s->Beds > p->Beds)
		{
			r->next = s->next;
			s->next = NULL;
			l->next = s;
			l = s;
			s = r->next;
		}
		else
		{
			r = s;
			s = s->next;
		}
	}
	l->next = H->next;
	H->next = L->next;
	delete L; 
  }
  int main()
  {
  	int i; 
  	HLink L;
	Build(L);
	printf("��������\n");
	Exp(L);
	printf("�������·���Ĵ�λ����");
	scanf("%d",&i);
	upBed(L,i);
	Exp(L);
	return 0;
   } 
