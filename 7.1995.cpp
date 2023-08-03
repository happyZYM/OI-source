#include<cstdio>
typedef long long LL;
inline LL ksm(LL a,LL b,LL p)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p) b&1?res=res*a%p:0;
	return res;
}
int T;
LL M,N,a,b,tot;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%lld%lld",&M,&N);
		tot=0;
		for(int i=0;i<N;i++)
		{
			scanf("%lld%lld",&a,&b);
			tot=(tot+ksm(a,b,M))%M;
		}
		printf("%lld\n",tot);
	}
	return 0;
}
