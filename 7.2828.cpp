#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,pos[maxn],val[maxn],res[maxn],a[maxn];
inline void add(int p,int v)
{
	for(;p<=n;p+=(p&-p)) a[p]+=v;
}
inline int sum(int p)
{
	int res=0;
	for(;p;p-=(p&-p)) res+=a[p];
	return res;
}
inline int query(int p)
{
	int L=1,R=n,M,res=R;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(sum(M)>=p) R=M-1,res=M;
		else L=M+1;
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++) { scanf("%d%d",&pos[i],&val[i]); pos[i]++; }
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) add(i,1);
		for(int i=n;i>=1;i--)
		{
			int p=query(pos[i]);
			res[p]=val[i];
			add(p,-1);
		}
		for(int i=1;i<=n;i++) printf("%d ",res[i]); puts("");
	}
	return 0;
}
