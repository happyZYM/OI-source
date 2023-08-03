#include<cstdio>
int f(int x)
{
	if(x==0) return printf("0");
	bool flag=false;
	for(int i=30;i>=0;i--)
		if(x&(1<<i))
		{
			if(flag) printf("+");
			flag=true;
			if(i==1) printf("2");
			else
			{
				printf("2(");
				f(i);
				printf(")");
			}
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	f(n);
	return 0;
}
