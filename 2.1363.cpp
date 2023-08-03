#include<cstdio>
#include<algorithm>
using namespace std;
inline long long sum(int a,int d,int n)
{
	return (2ll*a-n*d)*(n+1)/2;
}
int n,k,i,q,p,cnt;
long long res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
	while(scanf("%d%d",&n,&k)==2)
	{
		i=1;
		res=0;
		while(i<=n)
		{
			q=k%i;
			p=k/i;
			cnt=n-i;
			if(p>0) cnt=min(cnt,q/p);
			res+=sum(q,p,cnt);
			i+=cnt+1;
		}
		printf("%lld\n",res);
	}
	return 0;
}
