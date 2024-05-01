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
void Index_BF(Str &s,Str &t,int pos)//S=baaacbaaacbaaaacbaaaccbaaaacb  T=aaacbaaaccba
{
	int i,j,k,m;
	for(i=1; i<=300; ++i)
		t->time[i] = 0;	
	i = pos;
	j = k = 1;
	printf("\n��ϸƥ��������£�\n");
	while(i<=s->length && j<=t->length)
	{
		if(s->st[i]==t->st[j])
		{
			++i;
			++j;
			++(t->time[j]);
		}
		else
		{
			printf("��%d��ƥ��ʧ�ܣ�ʧ��λ���ڣ�i=%d,j=%d\n",k,i,j);
			i = i-j+2;
			j = 1;
			++k;
			printf("��%d��ƥ�俪ʼ��i=%d,j=%d\n",k,i,j);
		}
		printf("\n");
		printf("i=%d,j=%d\n",i,j);//�����ǰƥ�����
		for(m=1; m<=s->length; m++)
			printf("%c",s->st[m]);
		printf("\n");
		if(j==0)
			printf("%c",t->st[1]);
		for(m=1; m<i-j+1; m++)
			printf(" ");
		for(m=1; m<=j; m++)
			printf("%c",t->st[m]);
		printf("\n");
	}
		if (j > t->length)
	{
		printf("==ƥ��ɹ�==\n");
		printf("ƥ��λ��Ϊ%d\n",i-t->length);
		printf("ƥ���������Ϊ%d\n",k);
		printf("ģʽ���ĸ����ַ���ƥ���������\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
	else
	{
		printf("==ƥ��ʧ��==\n");
		printf("ƥ��λ��Ϊ%d\n",i-t->length);
		printf("ƥ���������Ϊ%d\n",k);
		printf("ģʽ���ĸ����ַ���ƥ���������\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
	for(i=1; i<=300; ++i)
		t->time[i] = 0;	
 } 
 void get_next(Str &t,int next[],int pos)
{
	int i,j,k;
	i = pos;
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
void get_nextval(Str &t, int nextval[], int pos)
{
	int i,j,k;
	i = pos;
	k = 1;
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
void Index_KMP(Str &s,Str &t,int pos,int next[])//S=baaacbaaacbaaaacbaaaccbaaaacb  T=aaacbaaaccba
{
	int i,j,k,m;
	i = pos;
	j = k = 1;
	for(m=1; m<=300; ++m)
		t->time[m] = 0;	
	printf("\n��ϸƥ��������£�\n");
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
			printf("��%d��ƥ��ʧ�ܣ�ʧ��λ���ڣ�i=%d,j=%d\n",k,i,j);
			j = next[j];
			++k;
			printf("j���ˣ���%d��ƥ�俪ʼ��i=%d,j=%d\n",k,i,j);
		}
		printf("\n");
		printf("i=%d,j=%d\n",i,j);//�����ǰƥ�����
		for(m=1; m<=s->length; m++)
			printf("%c",s->st[m]);
		printf("\n");
		if(j==0)
			printf("%c",t->st[1]);
		for(m=1; m<i-j+1; m++)
			printf(" ");
		for(m=1; m<=j; m++)
			printf("%c",t->st[m]);
		printf("\n");
	}
	if (j > t->length)
	{
		printf("==ƥ��ɹ�==\n");
		printf("ƥ��λ��Ϊ%d\n",i-t->length);
		printf("ƥ���������Ϊ%d\n",k);
		printf("ģʽ���ĸ����ַ���ƥ���������\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
	else
	{
		printf("==ƥ��ʧ��==\n");
		printf("ƥ��λ��Ϊ%d\n",i-t->length);
		printf("ƥ���������Ϊ%d\n",k);
		printf("ģʽ���ĸ����ַ���ƥ���������\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
}
int main()
{
	Str s,t;
	int i,j,x,pos;
	int next[100],nextval[100];
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
			printf("�������ʼƥ��λ�ã�1��\n");
			scanf("%d",&pos);
			Index_BF(s,t,pos);
			printf("\n");
			break;
			case 3:
			printf("�������ʼƥ��λ�ã�1��\n");
			scanf("%d",&pos);
			get_next(t,next,pos);
			Index_KMP(s,t,pos,next);
			printf("\n");
			break;
			case 4:
			printf("�������ʼƥ��λ�ã�1��\n");
			scanf("%d",&pos);
			get_nextval(t,nextval,pos);
			Index_KMP(s,t,pos,nextval);
			printf("\n");
			break;
			case 5:
			printf("�˳�\n");
			break; 
			default:
			printf("error!�����������ȷ����˵����֣�1-5��\n");
			break;
		}
	printf("\n�Ƿ�������в������ǣ������루1-4�����������루5��\n");
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
	}
	return 0;
}

