#include<stdio.h>
#include<string.h>	
typedef struct String
{
	char st[300];
	int length;
	int time[300]; 
}String,*Str;
void Bulid(Str &s)//S=baaacbaaacbaaaacbaaaccbaaaacb  T=aaacbaaaccba 
{
	int i;
	scanf("%s",(s->st)+1);
	s->length = strlen((s->st)+1);
	for(i=1; i<=300; ++i)
		s->time[i] = 0;	
}
void Output(Str &s)
{
	int i = 1;
	printf("�����������...\n");
	printf("�������ݣ�");
	for(i; i<=s->length; i++)
		printf("%c",s->st[i]); 
	printf("\n");
}
int Index_BF(Str &s,Str &t,int pos)
{
	int i,j;
	i = 1;
	j = 1;
	while(i<=s->length && j<=t->length)
	{
		if(s->st[i]==t->st[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i-j+2;
			j = 1;
		}
	}
	if(j>t->length)
	return i-t->length;
	else return 0;
 } 
 void get_next(Str &t,int next[])
{
	int i,j,k;
	i = 1;
	j = 0;
	next[1] = 0;
	while(i<t->length)
	{
		if(j==0||t->st[i] == t->st[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
	printf("next[]:");
	for(k=1; k<=t->length; k++)
		printf("%d ",next[k]);
	printf("\n");
}
int Index_KMPnext(Str &s,Str &t,int pos)
{
	int i,j,k,m;
	int next[100];
	i = pos;
	j = k = 1;
	get_next(t,next);
	while(i<s->length && j<=t->length)
	{
		if(j==0||s->st[i] == t->st[j])
		{
			++i;
			++j;
			++(t->time[j]);
		}
		else 
		{
			j = next[j];
			++k;
		}
		if(j<=t->length)
			printf("ƥ��ʧ�ܣ�ģʽ������λ��%d\n",next[j]);
	}
	printf("ƥ���������Ϊ%d\n",k);
	printf("ģʽ���ĸ����ַ���ƥ���������\n");
	for(m=1; m<=t->length; m++)
		printf("%c ",t->st[m]); 
	printf("\n");
	for(m=1; m<=t->length; m++)
		printf("%d ",t->time[m]);
	printf("\n");
	if(j>=t->length-1)
	return i-t->length;
	else return 0; 
}
void get_nextval(Str &t, int nextval[])
{
	int i,j,k;
	i = k = 1;
	j = 0;
	nextval[1] = 0;
	while(i<t->length)
	{
		if(j==0||t->st[i] == t->st[j])
		{
			++i;
			++j;
			if(t->st[i] != t->st[j])
			nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	 } 
	printf("nextval[]:");
	for(k; k<=t->length; k++)
		printf("%d ",nextval[k]);
	printf("\n");
}
int Index_KMPnextval(Str &s,Str &t,int pos)
{
	int i,j,k,m;
	int nextval[100];
	i = pos;
	j = k = 1;
	get_nextval(t,nextval);
	while(i<s->length && j<=t->length)
	{
		if(j==0||s->st[i] == t->st[j])
		{
			++i;
			++j;
			++(t->time[j]);
		}
		else 
		{
			j = nextval[j];
			++k;
		}
		if(j<=t->length) 
			printf("ƥ��ʧ�ܣ�ģʽ������λ��%d\n",nextval[j]);
	}
	printf("ƥ���������Ϊ%d\n",k);
	printf("ģʽ���ĸ����ַ���ƥ���������\n");
	for(m=1; m<=t->length; m++)
		printf("%c ",t->st[m]); 
	printf("\n");
	for(m=1; m<=t->length; m++)
		printf("%d ",t->time[m]);
	printf("\n");
	if(j>=t->length-1)
	return i-t->length;
	else return 0; 
}
int main()
{
	Str s,t;
	int i,j,x,pos;
	s = new String; 
	t = new String; 
	printf("�˵�����:\n");
	printf("=========================================\n");
	printf("||     ��ѡ��˵���Ŀ(���� 1-5)��      ||\n");
	printf("||-------------------------------------||\n");
	printf("||1--�����������Ӵ���ƥ����ʼλ��      ||\n");
	printf("||-------------------------------------||\n");
	printf("||2--���ص�ģʽƥ���㷨��BF�㷨��      ||\n"); 
	printf("||-------------------------------------||\n");
	printf("||3--KMP�Ľ��㷨(Next[ ])              ||\n");
	printf("||-------------------------------------||\n");
	printf("||4--KMP�Ľ��㷨(NextVal[ ])           ||\n");
	printf("||-------------------------------------||\n");
	printf("||5--�˳��˵�ϵͳ                      ||\n");
	printf("=========================================\n");
	scanf("%d",&x);
	while(x!=5)
	{
		switch(x)
		{
			case 1:
			printf("����ʹ��XX�㷨����ģʽƥ��\n");
			printf("������������");
			Bulid(s);
			Output(s);
			printf("\n");
			printf("������ģʽ����");
			Bulid(t);
			Output(t);
			break;
			case 2:
			printf("�������ʼƥ��λ��\n");
			scanf("%d",&pos);
			pos = Index_BF(s,t,pos);
			printf("\n");
			printf("ƥ���ַΪ%d\n",pos);
			break;
			case 3:
			printf("�������ʼƥ��λ��\n");
			scanf("%d",&pos);
			pos = Index_KMPnext(s,t,pos);
			printf("\n");
			printf("ƥ���ַΪ%d\n",pos);
			break;
			case 4:
			printf("�������ʼƥ��λ��\n");
			scanf("%d",&pos);
			pos = Index_KMPnextval(s,t,pos);
			printf("\n");
			printf("ƥ���ַΪ%d\n",pos);
			break;
			case 5:
			printf("�˳�\n");
			break; 
			default:
			printf("error!�����������ȷ����˵����֣�1-5��\n");
			break;
		}
			printf("\n�Ƿ�������в������ǣ������루1-4�����������루5��\n");
			scanf("%d",&x);
	}
	return 0;
}

