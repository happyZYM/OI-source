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
int cmd,x,y,k,last;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&last);
	add(1,last);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		add(i,x-last);
		last=x;
	}
	while(m-->0)
	{
		scanf("%d%d",&cmd,&x);
		if(cmd==1)
		{
			scanf("%d%d",&y,&k);
			add(x,k);
			add(y+1,-k);
		}
		else printf("%d\n",sum(x));
	}
	return 0;
}
