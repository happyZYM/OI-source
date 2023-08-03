#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=100000+10;
set<ll> st;
int maxed;
bool ok;
ll v[maxn],res[maxn];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
inline ll get_first(ll a,ll b){return b/a+1;}
bool better(int d)
{
	for(int i=d;i>=0;i--)
		if(res[i]!=v[i])
			return res[i]==-1||v[i]<res[i];
	return false;
}
void dfs(int pos,ll from,ll a,ll b)
{
	if(pos==maxed)
	{
		if(b%a||st.count(b/a)) return;
		v[pos]=b;
		if(better(pos)) memcpy(res,v,(pos+1)<<3);
		ok=true;
		return;
	}
	from=max(from,get_first(a,b));
	for(int i=from;;i++)
	{
		if(a*i>=b*(maxed-pos+1)) return;
		if(st.count(i)) continue;
		v[pos]=i;
		ll t1=a*i-b,t2=b*i;
		ll g=gcd(t1,t2);
		dfs(pos+1,i+1,t1/g,t2/g);
	}
	return;
}
ll a,b,x;
int n,T,kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--)
	{
		st.clear();
		scanf("%lld %lld %d",&a,&b,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			st.insert(x);
		}
		ok=false;
		for(maxed=1;;maxed++)
		{
			memset(res,-1,sizeof(res));
			dfs(0,get_first(a,b),a,b);
			if(ok) break;
		}
		printf("Case %d: %lld/%lld=",++kase,a,b);
		printf("1/%lld",res[0]);
		for(int i=1;i<=maxed;i++) printf("+1/%lld",res[i]);
		puts("");
	}
	return 0;
}
