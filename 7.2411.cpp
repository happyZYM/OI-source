#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long f[12][1<<11];
bool in_s[1<<11];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=0;i<(1<<m);i++)
		{
			bool cnt=0,ho=0;
			for(int j=0;j<m;j++)
				if(i>>j&1) ho|=cnt,cnt=0;
				else cnt^=1;
			in_s[i]=ho|cnt?0:1;
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<(1<<m);j++)
			{
				f[i][j]=0;
				for(int k=0;k<(1<<m);k++)
					if((j&k)==0&&in_s[j|k])
						f[i][j]+=f[i-1][k];
			}
		printf("%lld\n",f[n][0]);
	}
	return 0;
}