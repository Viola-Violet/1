#include<stdio.h>
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
	char s[50],num[5];
	int i,sum=0,m=0;
	gets(s);
	for(i=0;s[i];i+=2)
	{
		strncpy(num,s+i,2);
		num[2]='\0';
		if ( strcmp(num,"ʮ")==0 )
			if(sum==0) sum=10;
			else sum*=10;
		else if ( strcmp(num,"��")==0 )
		{
			m=sum*100;
			sum=0;
		}
		else
			sum+=number(num);
	}
	printf("sum=%d\n",sum+m);
}