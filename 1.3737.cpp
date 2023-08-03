#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=105;
struct Node { double L,R; };
inline bool operator<(const Node &a,const Node &b) { return a.L<b.L; }
int n,R,res;
Node a[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&R);
	for(int i=0;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		double t=sqrt(R*R-y*y);
		a[i].L=x-t; a[i].R=x+t;
	}
	sort(a,a+n);
	int q[maxn],cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt>0&&a[q[cnt-1]].R>=a[i].R) cnt--;
		q[cnt++]=i;
	}
	double last=-10000000;
	for(int i=0;i<cnt;i++)
		if(a[q[i]].L>last)
		{
			res++;
			last=a[q[i]].R;
		}
	printf("%d\n",res);
	return 0;
}
