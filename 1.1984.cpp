#include<cstdio>
int n; double now,res;
int main()
{
	scanf("%d",&n);
	now=420000.0/n;
	for(int i=1;i<=n;i++)
	{
		res+=now;
		now*=(1-0.5/i);
	}
	printf("%.2lf\n",res);
	return 0;
}
