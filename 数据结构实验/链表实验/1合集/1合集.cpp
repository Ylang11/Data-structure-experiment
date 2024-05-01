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

void Build(HLink &H);//输入（客房名称、标准价格、床位数）
void Exp(HLink H);//输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态
int Find(HLink &H,char *roomN);//查找房间名称为roomN的客房
void updateH(HLink &H, int beds, char *state);//修改客房入住状态
void Add(HLink &H);//将该链表中未入住的客房入住价格均加价20%
void Delete(HLink &H,int a);//删除结点操作 
HLink FirstH(HLink &H);//返回入住价格最高的客房结点指针，返回前将该结点在链表中删除
void MoveK1(HLink &H, int k);//将单链表中倒数第k个结点移到第一个结点位置
void ReverseN2(HLink &H);//将单链表的正中间位置结点之后的全部结点倒置的功能
int Length(HLink H);//计算链表长度 
void SortPriceL(HLink &H);//升序排序 
void upBed(HLink &H,int beds);//创建新结点，并改变链表形态 

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
int Find(HLink &H,char *roomN)//查找房间名称为roomN的客房
  {
  	HLink p;
  	int b,c=0;
  	p = H->next;
  	printf("正在查询%s房间，请稍后...",roomN);
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
  void updateH(HLink &H, int beds, char *state)//修改客房入住状态
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
  void Add(HLink &H)//将该链表中未入住的客房入住价格均加价20%
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
 void Delete(HLink &H,int a)//删除结点操作 
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
  void MoveK1(HLink &H, int k)//将单链表中倒数第k个结点移到第一个结点位置
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
	 int Length(HLink H)//计算链表长度 
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
  void upBed(HLink &H,int beds)//创建新结点，并改变链表形态 
  {
  	int length,i;
  	HLink p,s,l,r,L;
  	p = (HLink)malloc(sizeof(HNode));
  	L = (HLink)malloc(sizeof(HNode));
  	L->next =NULL;
  	p->Beds = beds;
  	printf("请输入新房间的房间名：");
  	scanf("%s",p->roomN);
	printf("请输入新房间的标准价格：");
	scanf("%f",&p->Price);
	p->PriceL = p->Price*0.8; 
	printf("请输入新房间的入住状态：");
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
	printf("菜单如下:\n"); 
	printf("=======================================================================\n");
	printf("||                    请选择菜单项目(输入 1-9)：                     ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||1--输入（客房名称、标准价格、床位数）                              ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||2--查找房间名称为roomN的客房                                       ||\n"); 
	printf("||-------------------------------------------------------------------||\n");
	printf("||3--修改客房入住状态                                                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||4--返回入住价格最高的客房结点指针，返回前将该结点在链表中删除      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||5--将该链表中未入住的客房入住价格均加价                            ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||6--将单链表中倒数第k个结点移到第一个结点位置                       ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||7--将单链表的正中间位置结点之后的全部结点倒置的功能                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||8--升序排序                                                        ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||9--创建新结点，并改变链表形态                                      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||0--退出                                                            ||\n");
	printf("=======================================================================\n");
	scanf("%d",&z);
	while(z!=0)
	{
		switch(z)
		{
			case 1:
			printf("\n");
			Build(L);
			printf("请检查数据\n");
			Exp(L); 
			printf("\n");
			break;
			case 2:
			printf("\n");
			printf("请输入所需查找的房间号:");
			scanf("%s",y); 
			a = Find(L,y);
			printf("\n");
			printf("房间%s位于第%d号房",y,a);
			break;
			case 3:
			printf("\n");
			printf("请输入所要设置床位数:") ;
			scanf("%d",&b);
			printf("\n");
			printf("其状态设置为:") ;
			scanf("%s",x);
			updateH(L,b,x);
			Exp(L);
			break;
			case 4:
			printf("\n");
			printf("正在查找最高入住价格房间，请稍后...\n"); 
			p = FirstH(L);
			printf("%s%8.1f%8.1f%6d%8s\n\n",p->roomN,p->Price,p->PriceL,p->Beds,p->State);
			printf("房间已删除...\n");
			Exp(L); 
			break;
			case 5:
			printf("\n");
			printf("正在进行加价操作...\n");
			Add(L);
			Exp(L);
			break; 
			case 6:
			printf("\n");
			printf("请输入倒第几个结点需要移到第一个结点位置:");
			scanf("%d",&a);
			MoveK1(L,a);
			Exp(L);
 			printf("\n");
			break; 
			case 7:
			printf("\n");
			printf("已将中间结点以后的房间进行倒置\n");
			ReverseN2(L);
			Exp(L);
 			printf("\n");
			break; 
			case 8:
			printf("\n");
			printf("已将所有房间进行升序排序\n");
			SortPriceL(L);
			Exp(L);
 			printf("\n");
			break; 
			case 9:
			printf("\n");
			printf("请输入新房间的床位数：");
			scanf("%d",&i);
			upBed(L,i);
			Exp(L);
			printf("已完成房间分类操作请检查\n"); 
 			printf("\n");
			break; 
			default:
			printf("error!输入错误，请正确输入菜单数字（1-9）\n");
			break;
		}
	printf("\n");
	printf("菜单如下:\n");
	printf("=======================================================================\n");
	printf("||                    请选择菜单项目(输入 1-9)：                     ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||1--输入（客房名称、标准价格、床位数）                              ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||2--查找房间名称为roomN的客房                                       ||\n"); 
	printf("||-------------------------------------------------------------------||\n");
	printf("||3--修改客房入住状态                                                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||4--返回入住价格最高的客房结点指针，返回前将该结点在链表中删除      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||5--将该链表中未入住的客房入住价格均加价   						 ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||6--将单链表中倒数第k个结点移到第一个结点位置                       ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||7--将单链表的正中间位置结点之后的全部结点倒置的功能                ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||8--升序排序                                                        ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||9--创建新结点，并改变链表形态                                      ||\n");
	printf("||-------------------------------------------------------------------||\n");
	printf("||0--退出                                                            ||\n");
	printf("=======================================================================\n");
		scanf("%d",&z);
	}
	return 0;
   } 
