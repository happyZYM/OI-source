#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int128 LLL;
const int maxn=81;
int n,m;
int a[maxn];
LLL res,p[maxn],val[maxn][maxn];
bool vis[maxn][maxn];
LLL dp(int L,int R)
{
	LLL &res=val[L][R];
	if(vis[L][R]) return res;
	int k=m-(R-L); vis[L][R]=true;
	if(R-L+1>=2) res=max(a[L]*p[k]+dp(L+1,R),dp(L,R-1)+a[R]*p[k]);
	else res=a[L]*p[k];
	return res;
}
void print(LLL x)
{
	if(!x) return;
	print(x/10);
	putchar(x%10+'0');
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	p[0]=1;
	for(int i=1;i<=m;i++) p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) scanf("%d",&a[j]);
		memset(vis,0,sizeof(vis));
		res+=dp(1,m);
	}
	if(!res) puts("0");
	else print(res),puts("");
	return 0;
}
