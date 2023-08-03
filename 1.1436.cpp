#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int oo=0x3f3f3f3f;
int n,a[20][20],s[20][20],vis[20][20][20][20][20];
int f[20][20][20][20][20],tot;
int dp(int R1,int C1,int R2,int C2,int tot)
{
	int &res=f[R1][C1][R2][C2][tot];
	if(vis[R1][C1][R2][C2][tot]) return res;
	vis[R1][C1][R2][C2][tot]=1;
	if(tot>(R2-R1+1)*(C2-C1+1)) return res=oo;
	if(tot==1)
	{
		double v=s[R2][C2]-s[R2][C1-1]-s[R1-1][C2]+s[R1-1][C1-1];
		return res=v*v;
	}
	res=oo;
	for(int R=R1;R<R2;R++)
	{
		int t=1;
		res=min(res,dp(R1,C1,R,C2,t)+dp(R+1,C1,R2,C2,tot-t));
		t=tot-1;
		res=min(res,dp(R1,C1,R,C2,t)+dp(R+1,C1,R2,C2,tot-t));
	}
	for(int C=C1;C<C2;C++)
	{
		int t=1;
		res=min(res,dp(R1,C1,R2,C,t)+dp(R1,C+1,R2,C2,tot-t));
		t=tot-1;
		res=min(res,dp(R1,C1,R2,C,t)+dp(R1,C+1,R2,C2,tot-t));
	}
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) { scanf("%d",&a[i][j]); tot+=a[i][j]; }
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	printf("%d\n",dp(1,1,8,8,n));
	return 0;
}