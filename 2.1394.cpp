#include<cstdio>
int n,k,m,f;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d%d",&n,&k,&m)==3&&n)
	{
		f=0;
		for(int i=2;i<=n;i++) f=(f+k)%i;
		int res=(m-k+1+f)%n;
		if(res<=0) res+=n;
		printf("%d\n",res);
	}
	return 0;
}
