#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=2005;
const LL oo=0x3f3f3f3f3f3f3f3fll;
int n,m,w;
LL res,ap[maxn],bp[maxn],as[maxn],bs[maxn],f[maxn][maxn];
int que[maxn],L,R;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld%lld",&ap[i],&bp[i],&as[i],&bs[i]);
	for(int i=1;i<=m;i++) f[0][i]=-oo;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) f[i][j]=f[i-1][j];
		for(int j=0;j<=as[i];j++) f[i][j]=max(f[i][j],-j*ap[i]);
		if(i-w-1<0) continue;
		que[L=R=1]=0;
		for(int j=1;j<=m;j++)
		{
			while(L<=R&&j-que[L]>as[i]) L++;
			if(L<=R) { int k=que[L]; f[i][j]=max(f[i][j],f[i-w-1][k]-(j-k)*ap[i]); }
			while(L<=R&&f[i-w-1][j]+j*ap[i]>=f[i-w-1][que[R]]+que[R]*ap[i]) R--;
			que[++R]=j;
		}
		que[L=R=1]=m;
		for(int j=m-1;j>=0;j--)
		{
			while(L<=R&&que[L]-j>bs[i]) L++;
			if(L<=R) { int k=que[L]; f[i][j]=max(f[i][j],f[i-w-1][k]+(k-j)*bp[i]); }
			while(L<=R&&f[i-w-1][j]+j*bp[i]>=f[i-w-1][que[R]]+que[R]*bp[i]) R--;
			que[++R]=j;
		}
		for(int j=0;j<=m;j++) res=max(res,f[i][j]);
	}
	printf("%lld\n",res);
	return 0;
}