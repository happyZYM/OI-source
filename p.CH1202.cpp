//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1202%20%E8%9A%AF%E8%9A%93
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<queue>
#include<cassert>
using namespace std;
typedef long long LL;
const int maxn=1e5;
const int maxm=7e6;
int n,m,q,u,v,t; long double p;
LL x[maxn+5],res[maxn+maxm+5],delta,cnt;
queue<LL> a,b,c;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t); p=(long double)u/v;
	for(int i=0;i<n;i++) scanf("%lld",&x[i]);
	sort(x,x+n,greater<LL>());
	for(int i=0;i<n;i++) a.push(x[i]);
#define H(Q) ((!Q.empty())?Q.front():-LL(1e18))
	for(int i=1;i<=m;i++)
	{
		LL now=max(max(H(a),H(b)),H(c))+delta;
		if(i%t==0) printf("%lld ",now);
		if(H(a)>H(b))
		{
			if(H(a)>H(c)) a.pop();
			else c.pop();
		}
		else
		{
			if(H(b)>H(c)) b.pop();
			else c.pop();
		}
		delta+=q;
		b.push(LL(now*p)-delta);
		c.push(now-LL(now*p)-delta);
//		printf("%lld -> (%lld,%lld)\n",now,LL(now*p),now-LL(now*p));
	}
	puts("");
	a.size(); b.size(); c.size();
	while(!a.empty()) { res[cnt++]=delta+a.front(); a.pop(); }
	while(!b.empty()) { res[cnt++]=delta+b.front(); b.pop(); }
	while(!c.empty()) { res[cnt++]=delta+c.front(); c.pop(); }
	sort(res,res+n+m,greater<LL>());
	for(int i=1;i<=n+m;i++) if(i%t==0) printf("%lld ",res[i-1]);
	puts("");
	return 0;
}
