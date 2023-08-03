#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k;
long long n;
long long d[105][105];
long long res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=1;i<=100;i++)
		for(int j=1;j<=63;j++)
			d[i][j]=d[i-1][j-1]+1+d[i][j-1];
	while(scanf("%d%lld",&k,&n)==2&&k&&n)
	{
		res=-1;
		for(int i=1;i<=63;i++)
			if(d[k][i]>=n){res=i;break;}
		if(res<0) printf("More than 63 trials needed.\n");
		else printf("%lld\n",res);
	}
	return 0;
}
