#include<cstdio>
#include<algorithm>
using namespace std;
int n,s1,v1,s2,v2;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T=0,cnt=0;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%d%d%d",&n,&s1,&v1,&s2,&v2);
		if(s1<s2)
		{
			swap(s1,s2);
			swap(v1,v2);
		}
		long long res=0;
		if(n/s1<=65536)
			for(long long i=n/s1;i>=0;i--) res=max(res,i*v1+(n-i*s1)/s2*v2);
		else
		{
			for(long long i=0;i<=s1;i++)
				res=max(res,v2*i+(n-i*s2)/s1*v1);
			for(long long i=0;i<=s2;i++)
				res=max(res,v1*i+(n-i*s1)/s2*v2);
		}
		printf("Case #%d: %lld\n",++cnt,res);
	}
	return 0;
}
