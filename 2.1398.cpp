#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int T,w,h,n,e;
struct Event
{
	double x;
	int type;
	inline bool operator<(const Event &b) const
	{ return x<b.x||(x==b.x&&type>b.type); }
} events[maxn*2];
void update(int x,int a,int w,double &L,double &R)
{
	if(a==0) { if(x<=0||x>=w) R=L-1; }
	else if(a>0)
	{
		L=max(L,-(double)x/a);
		R=min(R,(double)(w-x)/a);
	}
	else
	{
		L=max(L,(double)(w-x)/a);
		R=min(R,-(double)x/a);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		e=0;
		scanf("%d%d%d",&w,&h,&n);
		for(int i=0;i<n;i++)
		{
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			double L=0,R=1e9;
			update(x,a,w,L,R);
			update(y,b,h,L,R);
			if(R>L)
			{
				events[e++]=(Event){L,0};
				events[e++]=(Event){R,1};
			}
		}
		sort(events,events+e);
		int cnt=0,res=0;
		for(int i=0;i<e;i++)
		{
			if(events[i].type==0) res=max(res,++cnt);
			else cnt--;
		}
		printf("%d\n",res);
	}
	return 0;
}
