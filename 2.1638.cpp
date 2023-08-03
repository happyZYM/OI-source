#include<cstdio>
const int maxn=20;
long long d[maxn+1][maxn+1][maxn+1];
int i,j,k,T,n,L,R;
int main()
{
	d[1][1][1]=1;
	for(i=2;i<=maxn;i++)
		for(j=1;j<=i;j++)
			for(k=1;k<=i;k++)
			{
				d[i][j][k]=d[i-1][j][k]*(i-2);
				if(j>1) d[i][j][k]+=d[i-1][j-1][k];
				if(k>1) d[i][j][k]+=d[i-1][j][k-1];
			}
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%d",&n,&L,&R);
		printf("%lld\n",d[n][L][R]);
	}
	return 0;
}
