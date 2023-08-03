#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2005;
int T,m,n,a[105][maxn],buf[maxn],*x,*y;
struct ST { int i,j,flg; };
struct cmp
{
	inline bool operator()(const ST &a,const ST &b) { return x[a.i]+y[a.j]>x[b.i]+y[b.j]; }
};
inline void merge(int *a,int *b,int *c)
{
	x=a; y=b;
	priority_queue<ST,vector<ST>,cmp> Q;
	Q.push((ST){0,0,0});
	for(int k=0;k<n;k++)
	{
		ST u=Q.top(); Q.pop(); c[k]=a[u.i]+b[u.j];
		Q.push((ST){u.i,u.j+1,1});
		if(!u.flg) Q.push((ST){u.i+1,u.j,0});
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
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
			sort(a[i],a[i]+n);
		}
		memcpy(buf,a[0],n<<2);
		for(int i=1;i<m;i++)
		{
			merge(a[i-1],a[i],buf);
			memcpy(a[i],buf,n<<2);
		}
		for(int i=0;i<n;i++) printf("%d ",buf[i]); puts("");
	}
	return 0;
}
