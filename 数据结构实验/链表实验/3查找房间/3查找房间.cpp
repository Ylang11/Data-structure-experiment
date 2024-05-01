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

void Build(HLink &H);//���루�ͷ����ơ���׼�۸񡢴�λ����
void Exp(HLink H);//������пͷ��Ŀͷ����ơ���׼�۸���ס�۸񡢴�λ������ס״̬
int Find(HLink &H, char *roomN);//���ҷ�������ΪroomN�Ŀͷ�

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
 		printf("%s,%8.1f,%8.1f,%6d,%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
 		p = p->next;
	 }
  } 
  int Find(HLink &H,char *roomN)//���ҷ�������ΪroomN�Ŀͷ�
  {
  	HLink p;
  	int b,c=0;
  	p = H->next;
  	printf("���ڲ�ѯ%s���䣬���Ժ�...",roomN);
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
	printf("��������\n");
	Exp(L);
	printf("������������ҵķ����:");
	scanf("%s",x); 
	a = Find(L,x);
	printf("\n");
	printf("����%sλ�ڵ�%d�ŷ�",x,a);
	return 0;
   } 
