#include<cstdio>
typedef long long LL;
int main()
{
	LL n;
    scanf("%lld",&n);
    LL ans=n,i;
    for(i=2;i*i<=n;++i)
		if(n%i==0)
		{
	        int b=0;
	        while(n%i==0) ++b,n/=i;
	        ans/=i;
	        ans*=b*i-b+i;
	    }
	if(n>1) ans/=n,ans*=n+n-1; 
    printf("%lld\n",ans);
    return 0;
}
