// luogu-judger-enable-o2
#include<cstdio>
const int maxn=500005;
inline int lowbit(int x) { return x&-x; }
int n,m;
int a[maxn];
inline void add(int x,int v)
{
	while(x<=n)
	{
		a[x]+=v;
		x+=lowbit(x);
	}
}
inline int sum(int x)
{
	int res=0;
	while(x>0)
	{
		res+=a[x];
		x-=lowbit(x);
	}
	return res;
}
int cmd,x,y;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(i,x);
	}
	while(m-->0)
	{
		scanf("%d%d%d",&cmd,&x,&y);
		if(cmd==1) add(x,y);
		else printf("%d\n",sum(y)-sum(x-1));
	}
	return 0;
}
