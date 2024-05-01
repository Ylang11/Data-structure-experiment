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
   void ReverseN2(HLink &H)//������������м�λ�ý��֮���ȫ����㵹�õĹ���
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
	printf("��������\n");
	Exp(L); 
	ReverseN2(L);
	Exp(L);
	return 0;
   } 
