#include<cstdio>
int n;
char s[2005];
void solve()
{
	int a=0,b=n-1,sum=0;
	while(a<=b)
	{
		bool left=0;
		for(int i=0;a+i<=b;i++)
		{
			if(s[a+i]<s[b-i])
			{
				left=1;
				break;
			}
			else if(s[a+i]>s[b-i])
			{
				left=0;
				break;
			}
		}
		if(left) putchar(s[a++]);
		else putchar(s[b--]);
		sum++;
		if(sum%80==0) putchar('\n');
	}
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		getchar();
		s[i]=getchar();
	}
}
int main()
{
	init();
	solve();
	return 0;
}
