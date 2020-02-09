#include<stdio.h>
#include<math.h>
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
	int n,a;
	scanf("%d",&n);
	if(n<0)
	{
		printf("��");
		n=abs(n);
	}
	while(n)
	{
		if(n<10)
		{
			puts(inter[n]);
			return 0;
		}
		else if(n<100)
		{
			printf("%s",inter[n/10]);
			printf("ʮ");
			n%=10;
		}
		else if(n>=100)
		{
			printf("%s",inter[n/100]);
			printf("��");
			if( n%100 < 10 && n%100 != 0)
				printf("��");
			n%=100;
		}	
	}
	printf("\n");
}