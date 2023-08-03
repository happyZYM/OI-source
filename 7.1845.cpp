#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,m,res=1,mod=9901;
int p[20],c[20];
void fj(int n)
{
	m=0;
	for(int i=2;i*i<=n;i++) if(n%i==0)
	{
		p[++m]=i; c[m]=0;
		while(n%i==0) n/=i,c[m]++;
	}
	if(n>1) p[++m]=n,c[m]=1;
}
inline int ksm(int a,long long b)
{
	int res=1; a%=mod;
	for(;b;b>>=1,a=a*a%mod) b&1?res=res*a%mod:0;
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&a,&b);
	fj(a);
	for(int i=1;i<=m;i++)
	{
		if((p[i]-1)%mod==0)
		{
			res=((long long)b*c[i]+1)%mod*res%mod;
			continue;
		}
		int x=ksm(p[i],(long long)b*c[i]+1);
		x=(x-1+mod)%mod;
		int y=p[i]-1;
		y=ksm(y,mod-2);
		res=(long long)res*x%mod*y%mod;
	}
	printf("%d\n",res);
	return 0;
}
/*
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int mod=9901;
LL A,B,res=1;
vector<pair<LL,LL> > p;
inline LL ksm(LL a,LL b)
{
	LL res=1;
	a%=mod;
	for(;b;b>>=1,a=a*a%mod) b&1?res=res*a%mod:0;
	return res;
}
LL sum(LL p,LL c)
{
	if(!p) return 0;
	if(!c) return 1;
	if(c&1) return (1+ksm(p,(c+1)/2))*sum(p,c/2)%mod;
	else return ((1+ksm(p,c/2))*sum(p,c/2-1)+ksm(p,c))%mod;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&A,&B);
	for(int i=2;i*i<=A;i++) if(A%i==0)
	{
		int cnt=0;
		while(A%i==0) A/=i,cnt++;
		p.push_back(make_pair(i,cnt));
	}
	if(A!=1) p.push_back(make_pair(A,1));
	for(int i=0;i<p.size();i++) res=res*sum(p[i].first,p[i].second*B)%mod;
	printf("%lld\n",res);
	return 0;
}
*/
