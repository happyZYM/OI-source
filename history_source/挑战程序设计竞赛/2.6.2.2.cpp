#include<cstdio>
#include<cstring>
int n;
bool isp[1000005];
void solve()
{
	int p=0,i,j;
	for(i=2;i<=n;i++)
		if(isp[i])
		{
			p++;
			for(j=2;j*i<=n;j++) isp[j*i]=0;
		}
	printf("%d\n",p);
}
void init()
{
	scanf("%d",&n);
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;
}
int main()
{
	init();
	solve();
	return 0;
}
