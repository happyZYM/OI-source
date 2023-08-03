#include<cstdio>
#include<cstring>
const int maxn=100005;
int T,n,r;
int a[maxn],b[maxn];
int lowbit(int x) { return x&-x; }
inline int sum(int x)
{
	int res=0;
	while(x>0)
	{
		res=res+b[x];
		x-=lowbit(x);
	}
	return res;
}
inline void add(int x,int d)
{
	a[x]=a[x]+d;
	while(x<=r)
	{
		b[x]=b[x]+d;
		x+=lowbit(x);
	}
}
inline void set(int x,int d) { add(x,d-a[x]); }
int v[maxn],x[maxn],y[maxn];
long long res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		r=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			if(v[i]>r) r=v[i];
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			set(v[i],1);
			x[i]=sum(v[i]-1);
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=n;i>=1;i--)
		{
			set(v[i],1);
			y[i]=sum(v[i]-1);
		}
		res=0;
		for(int i=2;i<=n-1;i++) res=res
									+(long long)x[i]*(n-i-y[i])
									+(long long)(i-x[i]-1)*y[i];
		printf("%lld\n",res);
	}
	return 0;
}
