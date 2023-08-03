#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
struct Point
{
	LL x,y;
	Point(LL xx=0,LL yy=0):x(xx),y(yy) { }
};
int T;
LL n,S,D;
Point f(int n,LL m)
{
	if(n==0) return Point(0,0);
	LL len=1<<(n-1),blo=1<<(2*n-2);
	Point p=f(n-1,m%blo);
	int z=m/blo;
	if(z==0) return Point(p.y,p.x);
	if(z==1) return Point(p.x,p.y+len);
	if(z==2) return Point(p.x+len,p.y+len);
	if(z==3) return Point(2*len-p.y-1,len-p.x-1);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%I64d%I64d%I64d",&n,&S,&D);
		S--; D--;
		Point a=f(n,S),b=f(n,D);
		LL dx=a.x-b.x,dy=a.y-b.y;
		printf("%.0f\n",sqrt(dx*dx+dy*dy)*10);
	}
	return 0;
}
