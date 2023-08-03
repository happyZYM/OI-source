#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d,kase;
struct Is { double L,R; };
inline bool operator<(const Is &a,const Is &b) { return a.L<b.L; }
Is isl[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&d)==2&&!(n==0&&d==0))
	{
		bool flg=false;
		for(int i=0;i<n;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			if(y>d) flg=true;
			double dt=sqrt(d*d-y*y);
			isl[i]=(Is){x-dt,x+dt};
		}
		sort(isl,isl+n);
		int res=0; double pos=-1e10;
		for(int i=0;i<n;i++)
			if(isl[i].L>pos) { res++; pos=isl[i].R; }
			else pos=min(pos,isl[i].R);
		printf("Case %d: %d\n",++kase,flg?-1:res);
	}
	return 0;
}
