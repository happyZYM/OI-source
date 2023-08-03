#include<cstdio>
#include<cstring>
int k,n[6];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d",&k)==1&&k)
	{
		memset(n,0,sizeof(n));
		for(int i=1;i<=k;i++) scanf("%d",&n[i]);
		long long f[n[1]+1][n[2]+1][n[3]+1][n[4]+1][n[5]+1];
		memset(f,0,sizeof(f));
		f[0][0][0][0][0]=1;
		for(int a1=0;a1<=n[1];a1++)
			for(int a2=0;a2<=n[2];a2++)
				for(int a3=0;a3<=n[3];a3++)
					for(int a4=0;a4<=n[4];a4++)
						for(int a5=0;a5<=n[5];a5++)
						{
							long long t=f[a1][a2][a3][a4][a5];
							if(a1<n[1]) f[a1+1][a2][a3][a4][a5]+=t;
							if(a2<n[2]&&a1>a2) f[a1][a2+1][a3][a4][a5]+=t;
							if(a3<n[3]&&a2>a3) f[a1][a2][a3+1][a4][a5]+=t;
							if(a4<n[4]&&a3>a4) f[a1][a2][a3][a4+1][a5]+=t;
							if(a5<n[5]&&a4>a5) f[a1][a2][a3][a4][a5+1]+=t;
						}
		printf("%lld\n",f[n[1]][n[2]][n[3]][n[4]][n[5]]);
	}
	return 0;
}