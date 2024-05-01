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
 		printf("%s,%8.1f,%8.1f,%6d,%8s\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
 		p=p->next;
	 }
  } 
  void updateH(HLink &H, int beds, char *state)//�޸Ŀͷ���ס״̬
  {
  	HLink p;
  	p = H->next;
  	while(p)
  	{
  		if(p->Beds <= beds)
  		strcpy(p->State,state);
  		p = p->next;
	  }
  }
  int main()
  {
  	char a[7]; 
  	int b; 
  	HLink L; 
	Build(L);
	printf("��������\n");
	Exp(L); 
	printf("��������Ҫ���ô�λ��:") ;
	scanf("%d",&b);
	printf("\n");
	printf("��״̬����Ϊ:") ;
	scanf("%s",a);
	updateH(L,b,a);
	Exp(L);
	return 0;
   } 
