#include<cstdio>
const int maxn=50000;
int n,i,j,phi[maxn+5],sum[maxn+5];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	phi[1]=1;
	for(i=2;i<=maxn;i++)
		if(!phi[i])
			for(j=i;j<=maxn;j+=i)
			{
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
	for(i=1;i<=maxn;i++) sum[i]=sum[i-1]+phi[i];
	while(scanf("%d",&n)==1&&n) printf("%d\n",2*(sum[n]-1)+1);
	return 0;
}
