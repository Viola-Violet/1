#include<stdio.h>
#include<string.h>
char inter[11][5]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
int number(char *num)
{
	int i;
	for(i=0;i<11;i++)
		if ( strcmp(inter[i],num)==0 )
			return i;
}
int main()
{
	int i,j,k,t=5,n,len;
	char str[101][50]={0},s[1001],v[10];
	while(t--)
	{
		//char str[101][50]={0};
		gets(s);
		for(i=0,j=0;s[i]!='\0';i++)
			if(s[i]!=' ')
			{
				k=i;
				while( s[i]!=' '&&s[i]!='\0' ) i++;
			    strncpy(str[j],s+k,i-k);
				str[j++][i-k]='\0';
			}
		if ( strcmp(str[0],"����")==0 )  //�����ַ������ʱ��strcmp����0
		{
			strcpy(v, str[1]);
			n=number(str[3]);
		}
	    else if ( strcmp(str[0],"����")==0 )
		{
			puts(inter[n]);
		}
	    else if ( strcmp(str[0],"���")==0 )
		{
			if ( strcmp(str[2],"����")==0 )
				if(n>number(str[3])) strcpy(s, str[6]);
				else strcpy(s, str[9]);
			else if ( strcmp(str[2],"С��")==0 )
				if(n<number(str[3])) strcpy(s, str[6]);
				else strcpy(s, str[9]);
			len=strlen(s);
			strncpy(s,s+1,len-2);
			s[len-2]='\0';
			puts(s);
		}
	    else
			if ( strcmp(str[1],"����")==0 )
				n=n+number(str[2]);
			else if ( strcmp(str[1],"����")==0 )
				n=n-number(str[2]);
	}
}
