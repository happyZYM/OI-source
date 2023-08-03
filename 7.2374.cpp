#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define Lc (o<<1)
#define Rc (o<<1|1)
const int maxn=50005;
const int maxidx=200005;
int n,s,p[maxn][2],d[maxn][2],f[maxn][2];
int a[maxidx<<2],pl,pr,v;
inline void pushdown(int o) { a[Lc]=max(a[Lc],a[o]); a[Rc]=max(a[Rc],a[o]); }
void update(int o,int L,int R)
{
	if(pl<=L&&R<=pr) { a[o]=max(a[o],v); return; }
	pushdown(o);
	int M=(L+R)>>1;
	if(pl<=M)
		update(Lc,L,M);
	if(pr>M)
		update(Rc,M+1,R);
}
int query(int o,int L,int R,int p,int v)
{
	if(L==R) return max(v,a[o]);
	int M=(L+R)>>1;
	if(p<=M) return query(Lc,L,M,p,max(v,a[o]));
	else return query(Rc,M+1,R,p,max(v,a[o]));
}
inline void ckmin(int &a,int b) { a=min(a,b); }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	memset(f,0x3f,sizeof(f));
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i][0],&p[i][1]);
		p[i][0]+=100001; p[i][1]+=100001;
		d[i][0]=query(1,1,maxidx-5,p[i][0],0);
		d[i][1]=query(1,1,maxidx-5,p[i][1],0);
		// printf("i=%d %d %d\n",i,d[i][0],d[i][1]);
		v=i; pl=p[i][0]; pr=p[i][1];
		update(1,1,maxidx-5);
	}
	s+=100001;
	f[n][0]=abs(s-p[n][0]); f[n][1]=abs(s-p[n][1]);
	p[0][0]=p[0][1]=100001;
	for(int i=n;i>=1;i--)
		for(int j=0;j<=1;j++)
		{
			// printf("f[%d][%d]=%d\n",i,j,f[i][j]);
			int v=min(f[i][j],f[i][j^1]+abs(p[i][0]-p[i][1])),to=d[i][j];
			f[to][0]=min(f[to][0],v+abs(p[i][j]-p[to][0]));
			f[to][1]=min(f[to][1],v+abs(p[i][j]-p[to][1]));
		}
	printf("%d\n",f[0][0]);
	return 0;
}