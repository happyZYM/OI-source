#include<cstdio>
#include<cstring>
#include<cmath>
const int maxn=10000000;
const int maxsize=maxn/log(maxn)*1.2;
bool isp[maxn+5];
int p[maxsize],cnt;
int main()
{
	memset(isp,true,sizeof(isp));
	for(int i=2;i<=maxn;i++)
	{
		if(isp[i]) p[cnt++]=i;
		for(int j=0;j<cnt&&i*p[j]<=maxn;j++)
		{
			isp[i*p[j]]=false;
			if(i%p[j]==0) break;
		}
	}
	int n,m,x;
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		scanf("%d",&x);
		printf("%s\n",(x>1&&isp[x])?"Yes":"No");
	}
	return 0;
}
