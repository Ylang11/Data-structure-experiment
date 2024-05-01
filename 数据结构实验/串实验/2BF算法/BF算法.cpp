#include<stdio.h>
#include<string.h>	
typedef struct String
{
	char st[300];
	int length;
}String,*Str;
void Bulid(Str &s)
{
	int i,j,k;
	char x[300];
	scanf("%s",&x);
	j = strlen(x);
	i = 0;
	s->length = 0;
	while(j)
	{ 
		s->st[i] = x[i];
		s->length++; 
		i++;
		j--;
	}
}
void Output(Str &s)
{
	int i = 0;
	printf("输入完成请检查...\n");
	printf("串的内容：");
	for(i; i<=s->length; i++)
		printf("%c",s->st[i]); 
	printf("\n");
}
int Index_BF(Str &s,Str &t)
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
 int main()
 {
	Str s,t;
	int i,j,pos;
	s = new String; 
	t = new String; 
	printf("即将使用BF算法进行模式匹配\n");
	printf("请输入主串：");
	Bulid(s);
	Output(s);
	printf("\n");
	printf("请输入模式串：");
	Bulid(t);
	Output(t);
	pos = Index_BF(s,t);
	printf("\n");
	printf("匹配地址为%d\n",pos);
 	return 0;
 }
