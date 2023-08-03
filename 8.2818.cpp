#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e7+5;
int n,p[maxn],v[maxn],phi[maxn],cnt;
LL s[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) v[i]=i;
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(v[i]==i) { p[cnt++]=i; phi[i]=i-1; }
		for(int j=0;j<cnt&&(LL)p[j]*i<=n&&p[j]<=v[i];j++)
		{
			v[p[j]*i]=p[j];
			phi[p[j]*i]=phi[i]*(p[j]<v[i]?p[j]-1:p[j]);
		}
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]+phi[i];
	long long res=0;
	for(int i=0;i<cnt;i++) res+=2*s[n/p[i]]-1;
	printf("%lld\n",res);
	return 0;
}
