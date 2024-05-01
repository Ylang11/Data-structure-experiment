#include<stdio.h>
#include<string.h>	
typedef struct String
{
	char st[300];
	int length;
	int time[300]; 
}String,*Str;

void Bulid(Str &s);//串的创建 
void Output(Str &s);//输出串 
void Index_BF(Str &s,Str &t,int pos);//朴素的模式匹配算法（BF算法）
void get_next(Str &t,int next[],int pos);//next[]数组求值函数 
void Index_KMPnext(Str &s,Str &t,int pos);//KMP改进算法(Next[ ]) 
void get_nextval(Str &t, int nextval[], int pos);//nextval[]数组求值函数 
void Index_KMPnextval(Str &s,Str &t,int pos);//KMP改进算法(NextVal[ ]) 

void Bulid(Str &s)//串的创建 主串S=baaacbaaacbaaaacbaaaccbaaaacb  模式串T=aaacbaaaccba
{
	int i;
	scanf("%s",(s->st)+1);
	s->length = strlen((s->st)+1);
	for(i=1; i<=300; ++i)
		s->time[i] = 0;	
}
void Output(Str &s)//输出串 
{
	int i = 1;
	printf("输入完成请检查...\n");
	printf("串的内容：");
	for(i; i<=s->length; i++)
		printf("%c",s->st[i]); 
	printf("\n");
}
void Index_BF(Str &s,Str &t,int pos)//朴素的模式匹配算法（BF算法）
{
	int i,j,k,m;
	for(i=1; i<=300; ++i)
		t->time[i] = 0;	
	i = pos;
	j = k = 1;
	printf("\n详细匹配过程如下：\n");
	while(i<=s->length && j<=t->length)
	{
		for(m=1; m<=s->length; m++)
			printf("%c",s->st[m]);
		printf("\n");
		if(s->st[i]==t->st[j])
		{
			++i;
			++j;
			++(t->time[j]);
		}
		else
		{
			i = i-j+2;
			j = 1;
			++k;
		}
	for(m=1; m<i-j+1; m++)
		printf(" ");
	for(m=1; m<=j; m++)
		printf("%c",t->st[m]);
	printf("\n");
	}
		if (j > t->length)
	{
		printf("==匹配成功==\n");
		printf("匹配位置为%d\n",i-t->length);
		printf("匹配的总趟数为%d\n",k);
		printf("模式串的各个字符及匹配次数如下\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
	else
	{
		printf("==匹配失败==\n");
		printf("匹配位置为%d\n",i-t->length);
		printf("匹配的总趟数为%d\n",k);
		printf("模式串的各个字符及匹配次数如下\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
 } 
void get_next(Str &t,int next[],int pos)//next[]数组求值函数 
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
void Index_KMPnext(Str &s,Str &t,int pos)//KMP改进算法(Next[ ])
{
	int i,j,k,m;
	int next[100];
	for(i=1; i<=300; ++i)
		t->time[i] = 0;	
	i = pos;
	j = k = 1;
	get_next(t,next,pos);
	printf("\n详细匹配过程如下：\n");
	while(i<s->length && j<=t->length)
	{ 
		for(m=1; m<=s->length; m++)
			printf("%c",s->st[m]);
		printf("\n");
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
		printf("==匹配成功==\n");
		printf("匹配位置为%d\n",i-t->length);
		printf("匹配的总趟数为%d\n",k);
		printf("模式串的各个字符及匹配次数如下\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
	else
	{
		printf("==匹配失败==\n");
		printf("匹配位置为%d\n",i-t->length);
		printf("匹配的总趟数为%d\n",k);
		printf("模式串的各个字符及匹配次数如下\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
}
void get_nextval(Str &t, int nextval[], int pos)//nextval[]数组求值函数 
{
	int i,j,k;
	i = pos;
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
	for(k=1; k<=t->length; k++)
		printf("%d ",nextval[k]);
	printf("\n");
}
void Index_KMPnextval(Str &s,Str &t,int pos)//KMP改进算法(NextVal[ ]) 
{
	int i,j,k,m;
	int nextval[100];
	for(i=1; i<=300; ++i)
		t->time[i] = 0;	
	i = pos;
	j = k = 1;
	get_nextval(t,nextval,pos);
	printf("\n详细匹配过程如下：\n");
	while(i<s->length && j<=t->length)
	{
		for(m=1; m<=s->length; m++)
			printf("%c",s->st[m]);
		printf("\n");
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
		if(j==0)
			printf("%c",t->st[1]);
		for(m=1; m<i-j+1; m++)
			printf(" ");
		for(m=1; m<=j; m++)
			printf("%c",t->st[m]);
		printf("\n");
	}
if (j >= t->length)
	{
		printf("==匹配成功==\n");
		printf("匹配位置为%d\n",i-t->length);
		printf("匹配的总趟数为%d\n",k);
		printf("模式串的各个字符及匹配次数如下\n");
		for(m=1; m<=t->length; m++)
			printf("%c ",t->st[m]); 
		printf("\n");
		for(m=1; m<=t->length; m++)
			printf("%d ",t->time[m]);
		printf("\n");
	}
	else
	{
		printf("==匹配失败==\n");
		printf("匹配位置为%d\n",i-t->length);
		printf("匹配的总趟数为%d\n",k);
		printf("模式串的各个字符及匹配次数如下\n");
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
	s = new String; 
	t = new String; 
	printf("菜单如下:\n");
	printf("=========================================\n");
	printf("||     请选择菜单项目(输入 1-5)：      ||\n");
	printf("||-------------------------------------||\n");
	printf("||1--输入主串、子串和匹配起始位置      ||\n");
	printf("||-------------------------------------||\n");
	printf("||2--朴素的模式匹配算法（BF算法）      ||\n"); 
	printf("||-------------------------------------||\n");
	printf("||3--KMP改进算法(Next[ ])              ||\n");
	printf("||-------------------------------------||\n");
	printf("||4--KMP改进算法(NextVal[ ])           ||\n");
	printf("||-------------------------------------||\n");
	printf("||5--退出菜单系统                      ||\n");
	printf("=========================================\n");
	scanf("%d",&x);
	while(x!=5)
	{
		switch(x)
		{
			case 1:
			printf("即将使用XX算法进行模式匹配\n");
			printf("请输入主串：");
			Bulid(s);
			Output(s);
			printf("\n");
			printf("请输入模式串：");
			Bulid(t);
			Output(t);
			break;
			case 2:
			printf("请输入初始匹配位置（1）\n");
			scanf("%d",&pos);
			Index_BF(s,t,pos);
			printf("\n");
			break;
			case 3:
			printf("请输入初始匹配位置（1）\n");
			scanf("%d",&pos);
			Index_KMPnext(s,t,pos);
			printf("\n");
			break;
			case 4:
			printf("请输入初始匹配位置（1）\n");
			scanf("%d",&pos);
			Index_KMPnextval(s,t,pos);
			printf("\n");
			break;
			case 5:
			printf("退出\n");
			break; 
			default:
			printf("error!输入错误，请正确输入菜单数字（1-5）\n");
			break;
		}
	printf("\n是否继续进行操作，是：请输入（1-4），否：请输入（5）\n");
	printf("=========================================\n");
	printf("||     请选择菜单项目(输入 1-5)：      ||\n");
	printf("||-------------------------------------||\n");
	printf("||1--输入主串、子串和匹配起始位置      ||\n");
	printf("||-------------------------------------||\n");
	printf("||2--朴素的模式匹配算法（BF算法）      ||\n"); 
	printf("||-------------------------------------||\n");
	printf("||3--KMP改进算法(Next[ ])              ||\n");
	printf("||-------------------------------------||\n");
	printf("||4--KMP改进算法(NextVal[ ])           ||\n");
	printf("||-------------------------------------||\n");
	printf("||5--退出菜单系统                      ||\n");
	printf("=========================================\n");
	scanf("%d",&x);
	}
	return 0;
}

