#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod=1e9;
const int maxn=305;
int n; char s[maxn]; LL f[maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if(s[i]!=s[j]) continue;
			for(int k=i+2;k<=j-2;k++) (f[i][j]+=f[i+1][k-1]*f[k][j])%=mod;
			(f[i][j]+=f[i+1][j-1])%=mod;
		}
	printf("%lld\n",f[1][n]);
	return 0;
}