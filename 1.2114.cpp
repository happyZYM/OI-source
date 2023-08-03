#include<cstdio>
int main()
{
	int bool1=0x7fffffff,bool0=0;
	char s[10];
	int n,m,t;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s%d",s,&t);
		switch(s[0])
		{
			case 'A':
				bool1&=t;
				bool0&=t;
				break;
			case 'O':
				bool1|=t;
				bool0|=t;
				break;
			case 'X':
				bool1^=t;
				bool0^=t;
				break;
		}
	}
	int res=0;
	for(int i=30;i>=0;i--)
	{
		if(bool0&(1<<i))
			res|=1<<i;
		else if(m>=(1<<i)&&(bool1&(1<<i)))
		{
			m-=1<<i;
			res|=1<<i;
		}
	}
	printf("%d\n",res);
	return 0;
}
