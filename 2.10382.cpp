#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
struct Circle
{
	double p,r,d;
};
int n;
double l,w;
Circle c[maxn];
bool cmp(const Circle &a,const Circle &b)
{ return a.p-a.d<b.p-b.d; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%lf%lf",&n,&l,&w)==3)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&c[i].p,&c[i].r);
			if(w/2>=c[i].r)
			{
				n--;
				i--;
				continue;
			}
			c[i].d=sqrt(c[i].r*c[i].r-w*w/4);
		}
		sort(c,c+n,cmp);
		double now=0.0,maxd;
		int res=0,p=0;
		while(now<l&&p<n)
		{
			maxd=now;
			while(p<n&&c[p].p-c[p].d<=now)
				maxd=max(maxd,c[p].p+c[p].d),p++;
			res++;
			if(maxd>now) now=maxd;
			else break;
		}
		if(now<l) res=-1;
		printf("%d\n",res);
	}
	return 0;
}
