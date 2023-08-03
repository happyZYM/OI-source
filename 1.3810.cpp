#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,c[maxn*2],res[maxn],cnt;
struct Data { int a,b,c,w,f; } e[maxn],t[maxn];
bool cmp(const Data &x,const Data &y)
{
	if(x.a!=y.a) return x.a<y.a;
	if(x.b!=y.b) return x.b<y.b;
	return x.c<y.c;
}
inline void add(int p,int v)
{
	for(;p<=m;p+=(p&-p)) c[p]+=v;
}
inline int sum(int p)
{
	int res=0;
	for(;p;p-=(p&-p)) res+=c[p];
	return res;
}
void CDQ(int L,int R)
{
	if(L==R) return;
	int M=(L+R)>>1;
	CDQ(L,M); CDQ(M+1,R);
	int p=L,q=M+1,tot=L;
	while(p<=M&&q<=R)
	{
		if(e[p].b<=e[q].b) { add(e[p].c,e[p].w); t[tot++]=e[p++]; }
		else { e[q].f+=sum(e[q].c); t[tot++]=e[q++]; }
	}
	while(p<=M) { add(e[p].c,e[p].w); t[tot++]=e[p++]; }
	while(q<=R) { e[q].f+=sum(e[q].c); t[tot++]=e[q++]; }
	for(int i=L;i<=M;i++) add(e[i].c,-e[i].w);
	for(int i=L;i<=R;i++) e[i]=t[i];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) { cin>>e[i].a>>e[i].b>>e[i].c; e[i].w=1; }
	sort(e+1,e+n+1,cmp);
	cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(e[i].a==e[cnt].a&&e[i].b==e[cnt].b&&e[i].c==e[cnt].c) e[cnt].w++;
		else e[++cnt]=e[i];
	}
	CDQ(1,cnt);
	for(int i=1;i<=cnt;i++) res[e[i].f+e[i].w-1]+=e[i].w;
	for(int i=0;i<n;i++) cout<<res[i]<<'\n';
	return 0;
}
