#include<cstdio>
#include<algorithm>
using namespace std;
int gcd[305][305];
int GCD(int a,int b)
{
	return b==0?a:GCD(b,a%b);
}
int n,m;
int a,b,c,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			gcd[i][j]=GCD(i,j);
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		res=0;
		for(a=1;a<=m;a++)
			for(b=1;b<=n;b++)
				if(gcd[a][b]==1)
				{
					c=max(0,m-2*a)*max(0,n-2*b);
					res+=(m-a)*(n-b)-c;
				}
		printf("%d\n",res*2);
	}
	return 0;
}
