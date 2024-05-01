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
int Find(HLink &H,char *roomN);//���ҷ�������ΪroomN�Ŀͷ�
void updateH(HLink &H, int beds, char *state);//�޸Ŀͷ���ס״̬
void Add(HLink &H);//����������δ��ס�Ŀͷ���ס�۸���Ӽ�20%
void Delete(HLink &H,int a);//ɾ�������� 
HLink FirstH(HLink &H);//������ס�۸���ߵĿͷ����ָ�룬����ǰ���ý����������ɾ��
void MoveK1(HLink &H, int k);//���������е�����k������Ƶ���һ�����λ��
void ReverseN2(HLink &H);//������������м�λ�ý��֮���ȫ����㵹�õĹ���
int Length(HLink H);//���������� 
void SortPriceL(HLink &H);//�������� 
void upBed(HLink &H,int beds);//�����½�㣬���ı�������̬ 

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
  void Add(HLink &H)//����������δ��ס�Ŀͷ���ס�۸���Ӽ�20%
  {
  	HLink p;
  	p = H->next;
  	while(p)
  	{
  		if(p->Beds == 4)
  		p->Price = p->Price*(1+0.2);
  		p->PriceL = p->Price*0.8;
  		p = p->next;
	  }
  }
 void Delete(HLink &H,int a)//ɾ�������� 
 {
 	HLink p,pre;
 	pre = H->next;
 	while(pre->next)
 	{
 		if(pre->next->PriceL == a)
		 {
		 	p = pre->next;
 			pre->next = p->next;
		 }
		else
		pre = pre->next;
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
  void MoveK1(HLink &H, int k)//���������е�����k������Ƶ���һ�����λ��
  {
  	HLink p,r,s;
  	p = H->next;
  	r = H->next;
  	s = H;
  	k=--k; 
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
	 int Length(HLink H)//���������� 
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
  void SortPriceL(HLink &H)//�������� 
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
  void upBed(HLink &H,int beds)//�����½�㣬���ı�������̬ 
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
  	char x[7],y[7]; 
  	int a,b,i; 
  	HLink L,p; 
	int z; 
	printf("�˵�����:\n"); 
	printf("=======================================================================\n");
	printf("||                    ��ѡ��˵���Ŀ(���� 1-9)��                     ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||1--���루�ͷ����ơ���׼�۸񡢴�λ����                              ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||2--���ҷ�������ΪroomN�Ŀͷ�                                       ||\n"); 
	printf("||-------------------------------------------------------------------||\n");
	printf("||3--�޸Ŀͷ���ס״̬                                                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||4--������ס�۸���ߵĿͷ����ָ�룬����ǰ���ý����������ɾ��      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||5--����������δ��ס�Ŀͷ���ס�۸���Ӽ�                            ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||6--���������е�����k������Ƶ���һ�����λ��                       ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||7--������������м�λ�ý��֮���ȫ����㵹�õĹ���                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||8--��������                                                        ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||9--�����½�㣬���ı�������̬                                      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||0--�˳�                                                            ||\n");
	printf("=======================================================================\n");
	scanf("%d",&z);
	while(z!=0)
	{
		switch(z)
		{
			case 1:
			printf("\n");
			Build(L);
			printf("��������\n");
			Exp(L); 
			printf("\n");
			break;
			case 2:
			printf("\n");
			printf("������������ҵķ����:");
			scanf("%s",y); 
			a = Find(L,y);
			printf("\n");
			printf("����%sλ�ڵ�%d�ŷ�",y,a);
			break;
			case 3:
			printf("\n");
			printf("��������Ҫ���ô�λ��:") ;
			scanf("%d",&b);
			printf("\n");
			printf("��״̬����Ϊ:") ;
			scanf("%s",x);
			updateH(L,b,x);
			Exp(L);
			break;
			case 4:
			printf("\n");
			printf("���ڲ��������ס�۸񷿼䣬���Ժ�...\n"); 
			p = FirstH(L);
			printf("%s%8.1f%8.1f%6d%8s\n\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
			printf("������ɾ��...\n");
			Exp(L); 
			break;
			case 5:
			printf("\n");
			printf("���ڽ��мӼ۲���...\n");
			Add(L);
			Exp(L);
			break; 
			case 6:
			printf("\n");
			printf("�����뵹�ڼ��������Ҫ�Ƶ���һ�����λ��:");
			scanf("%d",&a);
			MoveK1(L,a);
			Exp(L);
 			printf("\n");
			break; 
			case 7:
			printf("\n");
			printf("�ѽ��м����Ժ�ķ�����е���\n");
			ReverseN2(L);
			Exp(L);
 			printf("\n");
			break; 
			case 8:
			printf("\n");
			printf("�ѽ����з��������������\n");
			SortPriceL(L);
			Exp(L);
 			printf("\n");
			break; 
			case 9:
			printf("\n");
			printf("�������·���Ĵ�λ����");
			scanf("%d",&i);
			upBed(L,i);
			Exp(L);
			printf("����ɷ�������������\n"); 
 			printf("\n");
			break; 
			default:
			printf("error!�����������ȷ����˵����֣�1-9��\n");
			break;
		}
	printf("\n");
	printf("�˵�����:\n");
	printf("=======================================================================\n");
	printf("||                    ��ѡ��˵���Ŀ(���� 1-9)��                     ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||1--���루�ͷ����ơ���׼�۸񡢴�λ����                              ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||2--���ҷ�������ΪroomN�Ŀͷ�                                       ||\n"); 
	printf("||-------------------------------------------------------------------||\n");
	printf("||3--�޸Ŀͷ���ס״̬                                                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||4--������ס�۸���ߵĿͷ����ָ�룬����ǰ���ý����������ɾ��      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||5--����������δ��ס�Ŀͷ���ס�۸���Ӽ�   						 ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||6--���������е�����k������Ƶ���һ�����λ��                       ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||7--������������м�λ�ý��֮���ȫ����㵹�õĹ���                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||8--��������                                                        ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||9--�����½�㣬���ı�������̬                                      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||0--�˳�                                                            ||\n");
	printf("=======================================================================\n");
		scanf("%d",&z);
	}
	return 0;
   } 
