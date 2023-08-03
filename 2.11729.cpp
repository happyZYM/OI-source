#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int B,J;
	inline bool operator<(const node &b) const
	{ return J>b.J; }
};
int n,kase;
node v[1005];
int s,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++) scanf("%d%d",&v[i].B,&v[i].J);
		sort(v,v+n);
		s=res=0;
		for(int i=0;i<n;i++)
		{
			s+=v[i].B;
			res=max(res,s+v[i].J);
		}
		printf("Case %d: %d\n",++kase,res);
	}
	return 0;
}
