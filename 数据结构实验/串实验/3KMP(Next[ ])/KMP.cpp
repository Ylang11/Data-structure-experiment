#include<stdio.h>
#include<string.h>	
typedef struct String
{
	char st[300];
	int length;
	int time[300]; 
}String,*Str;
void Bulid(Str &s)
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
	printf("输入完成请检查...\n");
	printf("串的内容：");
	for(i; i<=s->length; i++)
		printf("%c",s->st[i]); 
	printf("\n");
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
int Index_KMP(Str &s,Str &t)
{
	int i,j,k,m;
	int next[100];
	i = j = 1;
	k = 0;
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
		printf("匹配失败，模式串返回位置%d\n",next[j]);
	}
	printf("匹配的总趟数为%d\n",k);
	printf("模式串的各个字符及匹配次数如下\n");
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
	int i,j,pos;
	s = new String; 
	t = new String; 
	printf("即将使用KMP算法进行模式匹配\n");
	printf("请输入主串：");
	Bulid(s);
	Output(s);
	printf("\n");
	printf("请输入模式串：");
	Bulid(t);
	Output(t);
	pos = Index_KMP(s,t);
	printf("\n");
	printf("匹配地址为%d\n",pos+1);
 	return 0;
 }
