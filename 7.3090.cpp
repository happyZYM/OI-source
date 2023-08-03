#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,kase,n,v[maxn],p[maxn],cnt,phi[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=1;i<maxn;i++) v[i]=i;
	for(int i=2;i<maxn;i++)
	{
		if(v[i]==i) { p[cnt++]=i; phi[i]=i-1; }
		for(int j=0;j<cnt&&p[j]*i<maxn;j++)
		{
			if(p[j]>v[i]) break;
			v[p[j]*i]=p[j];
			phi[p[j]*i]=phi[i]*(p[j]<v[i]?p[j]-1:p[j]);
		}
	}
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		int res=3;
		for(int i=2;i<=n;i++) res+=phi[i]*2;
		printf("%d %d %d\n",++kase,n,res);
	}
	return 0;
}
