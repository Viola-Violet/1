#include<stdio.h>
#include<string.h>
struct people
{
	char name[10];
	int n;
}peop[5];
char inter[11][5]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
int i,j,k,x=0;
char s[1001];
int number(char *num)
{
	for(i=0;i<11;i++)
		if ( strcmp(inter[i],num)==0 )
			return i;
}
int look(char *na)
{
	for(i=0;i<5;i++)
		if( strcmp(peop[i].name,na)==0 ) return i;
}
void disp(char *p)
{
	char str1[2][50]={0};
	p=strstr(p,"����");
	for(i=0,j=0;j<2;i++)
		if(p[i]!=' ')
		{
			k=i;
			while( p[i]!=' '&&p[i]!='\0' ) i++;
			strncpy(str1[j++],p+k,i-k);
		}
	if(str1[1][0]!='"')
	{
		k=look(str1[1]);
		puts(inter[peop[k].n]);
		return ;
	}
	for(i=1;str1[1][i]!='"';i++)
		printf("%c",str1[1][i]);
	printf("\n");
}
void fun(char *p)
{
	char str1[10][50]={0};
	for(i=0,j=0;p[i];i++)
		if(p[i]!=' ')
		{
			k=i;
			while( p[i]!=' '&&p[i]!='\0' ) i++;
			strncpy(str1[j++],p+k,i-k);
		}
	if ( strcmp(str1[1],"��")==0 )
		return ;
	else if ( strcmp(str1[1],"����")==0 )
			disp(p);
	else if ( strcmp(str1[2],"����")==0 )
	{
		k=look(str1[1]);
		peop[k].n=peop[k].n+number(str1[3]);
	}
    else if ( strcmp(str1[2],"����")==0 )
	{
		k=look(str1[1]);
		peop[k].n=peop[k].n-number(str1[3]);
	}
}

int main()
{
	int t=5,len;
	char v[10],*p;
	while(t--)
	{
		char str[15][50]={0};
		gets(s);
		for(i=0,j=0;s[i]!='\0';i++)
			if(s[i]!=' ')
			{
				k=i;
				while( s[i]!=' '&&s[i]!='\0' ) i++;
			    strncpy(str[j++],s+k,i-k);
			}
		if ( strcmp(str[0],"����")==0 )  //�����ַ������ʱ��strcmp����0
		{
			strcpy(peop[x].name, str[1]);
			peop[x].n=number(str[3]);
			x++;
		}
	    else if ( strcmp(str[0],"����")==0 )
			disp(s);
	    else if ( strcmp(str[1],"����")==0 )
		{
			k=look(str[0]);
		    peop[k].n=peop[k].n+number(str[2]);
		}
		else if ( strcmp(str[1],"����")==0 )
		{
			k=look(str[0]);
		    peop[k].n=peop[k].n-number(str[2]);
		}
		else if ( strcmp(str[0],"���")==0 )
		{
			k=look(str[1]);
			if( (strcmp(str[2],"����")==0 && peop[k].n>number(str[3])) ||  (strcmp(str[2],"С��")==0 && peop[k].n<number(str[3]))  || (strcmp(str[2],"���ڵ���")==0 && peop[k].n>=number(str[3])) || (strcmp(str[2],"С�ڵ���")==0 && peop[k].n<=number(str[3])) || (strcmp(str[2],"����")==0 && peop[k].n==number(str[3])) )
				fun(strstr(s,"��"));
			else
			    fun(strstr(s,"����"));
		}
	}
}
