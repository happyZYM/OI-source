#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int left[maxn],right[maxn];
int n,m,kase;
inline int link(int a,int b)
{
	right[a]=b;
	left[b]=a;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=n;i++)
		{
			left[i]=i-1;
			right[i]=(i+1)%(n+1);
		}
		right[0]=1;left[0]=n;
		int op,X,Y,inv=0;
		while(m-->0)
		{
			scanf("%d",&op);
			if(op==4) inv=!inv;
			else
			{
				scanf("%d%d",&X,&Y);
				if(op==3&&right[Y]==X) swap(X,Y);
				if(op!=3&&inv) op=3-op;
				if(op==1&&X==left[Y]) continue;
				if(op==2&&X==right[Y]) continue;
				int LX=left[X],RX=right[X],LY=left[Y],RY=right[Y];
				if(op==1) link(LX,RX),link(LY,X),link(X,Y);
				if(op==2) link(LX,RX),link(Y,X),link(X,RY);
				if(op==3)
				{
					if(right[X]==Y) link(LX,Y),link(Y,X),link(X,RY);
					else link(LX,Y),link(Y,RX),link(LY,X),link(X,RY);
				}
			}
		}
		int b=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			b=right[b];
			if(i&1) ans+=b;
		}
		if(inv&&!(n&1)) ans=(long long)n*(n+1)/2-ans;
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
