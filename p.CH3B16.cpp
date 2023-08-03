//http://contest-hunter.org:83/contest/0x3B%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E7%BB%83%E4%B9%A0/3B16%20%E9%AD%94%E6%B3%95%E7%8F%A0
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,f[maxn];
void fj(int n,int *a,int &tot)
{
	tot=a[1]=1;
	for(int i=2;i*i<=n;i++) if(n%i==0)
	{
		a[++tot]=i;
		if(i*i!=n) a[++tot]=n/i;
	}
}
int SG(int x)
{
	if(f[x]!=-1) return f[x];
	int &res=f[x]; res=0;
	int tot,a[maxn]; bool v[maxn]={0};
	fj(x,a,tot);
	for(int i=1;i<=tot;i++)//È¥µôi
	{
		int k=0;
		for(int j=1;j<=tot;j++) if(i!=j) k^=SG(a[j]);
		v[k]=1;
	}
	while(v[res]) res++;
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	memset(f,-1,sizeof(f));
	f[1]=0;
	while(scanf("%d",&n)==1)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int x; scanf("%d",&x);
			res^=SG(x);
		}
		printf("%s\n",res?"freda":"rainbow");
	}
	return 0;
}
