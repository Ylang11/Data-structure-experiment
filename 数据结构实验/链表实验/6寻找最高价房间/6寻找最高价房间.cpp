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
 void Delete(HLink &H,int a)//ɾ�������� 
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
	 printf("��ɾ���۸���ߵĿͷ���㣬��������...\n");
  } 
  HLink FirstH(HLink &H)//������ס�۸���ߵĿͷ����ָ�룬����ǰ���ý����������ɾ��
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
	printf("������ס�۸����Ϊ%d�����ڽ���ɾ������...\n\n",max);
	Delete(H,max);
	return r;
  }
  int main()
  {
  	HLink L,p; 
	Build(L);
	printf("��������\n");
	Exp(L); 
	p = FirstH(L);
	printf("%s%8.1f%8.1f%6d%8s\n\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
	Exp(L); 
	return 0;
   } 
