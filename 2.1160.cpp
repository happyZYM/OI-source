#include<cstdio>
const int maxn=100010;
int x,y,fa[maxn];
int ff(int x)
{
	return fa[x]!=x?fa[x]=ff(fa[x]):x;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&x)==1)
	{
		for(int i=0;i<maxn;i++) fa[i]=i;
		int res=0;
		while(x!=-1)
		{
			scanf("%d",&y);
			x=ff(x);y=ff(y);
			if(x==y) ++res;
			else fa[x]=y;
			scanf("%d",&x);
		}
		printf("%d\n",res);
	}
	return 0;
}
