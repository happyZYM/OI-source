#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,x;
double p;
double dp[2][(1<<15)+1];
void init()
{
	scanf("%d%lf%d",&m,&p,&x);
}
void solve()
{
	int n=1<<m;
	double *prv=dp[0],*nxt=dp[1];
	memset(prv,0,sizeof(double)*(n+1));
	prv[n]=1.0;
	for(int r=0;r<m;r++)
	{
		for(int i=0;i<=n;i++)
		{
			int jub=min(i,n-i);
			double t=0.0;
			for(int j=0;j<=jub;j++)
				t=max(t,p*prv[i+j]+(1-p)*prv[i-j]);
			nxt[i]=t;
		}
		swap(prv,nxt);
	}
	int i=(long long)x*n/1000000;
	printf("%.6lf\n",prv[i]);
}
int main()
{
	init();
	solve();
	return 0;
}
