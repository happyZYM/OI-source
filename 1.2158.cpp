#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=40005;
int n,res;
bool isp[maxn];
int p[maxn],cnt,phi[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	if(n==1) { puts("0"); return 0; }
	phi[1]=1;
	memset(isp,true,sizeof(isp));
	isp[1]=false;
	for(int i=2;i<=n-1;i++)
	{
		if(isp[i]) { p[cnt++]=i; phi[i]=i-1; }
		for(int j=0;j<cnt&&i*p[j]<=n-1;j++)
		{
			isp[i*p[j]]=false;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<=n-1;i++) res+=phi[i];
	printf("%d\n",res*2+1);
	return 0;
}
