#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long double LD;
const int maxn=100005;
const double oo=0x3f3f3f3f,eps=0.000001;
struct Point
{
	int x,y; bool z;
}p[maxn*2];
inline bool operator<(const Point &a,const Point &b) { return a.x<b.x; }
int n;
inline double dis(const Point &a,const Point &b) { return a.z==b.z?oo:sqrt((LD)(a.x-b.x)*(a.x-b.x)+(LD)(a.y-b.y)*(a.y-b.y)); }
double f(int L,int R)
{
	if(L==R) return oo;
	if(L+1==R) return dis(p[L],p[R]);
	int M=(L+R)>>1;
	double res=min(f(L,M),f(M,R));
	for(int i=M-1;i>=L;i--)
	{
		if(p[M].x-p[i].x+eps>res) break;
		for(int j=M+1;j<=R;j++)
		{
			if(p[j].x-p[i].x+eps>res) break;
			res=min(res,dis(p[i],p[j]));
		}
	}
	return res;
}
inline void solve()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) { scanf("%d %d",&p[i].x,&p[i].y); p[i].z=0; }
	for(int i=n;i<(n<<1);i++) { scanf("%d %d",&p[i].x,&p[i].y); p[i].z=1; }
	sort(p,p+2*n);
	printf("%.3f\n",f(0,2*n-1));
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T; scanf("%d",&T);
	while(T-->0) solve();
	return 0;
}
