#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=60;
int n,f[maxn][maxn][2600],b[maxn],c[maxn];
int dp(int i,int j,int k)
{
	int &res=f[i][j][k];
	if(res) return res;
	if(i==j) return res=(c[i]+k)*(c[i]+k);
	res=dp(i,j-1,0)+(k+c[j])*(k+c[j]);
	for(int p=i;p<j;p++)
		if(b[p]==b[j]) res=max(res,dp(i,p,k+c[j])+dp(p+1,j-1,0));
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i][0]=c[i]*c[i];
	printf("%d\n",dp(1,n,0));
	return 0;
}