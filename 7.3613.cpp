#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cassert>
using namespace std;
const int oo=0x3f3f3f3f;
const int maxn=210;
int P,n,m,s,e,a[maxn],b[maxn],c[maxn],d[maxn][maxn],res[maxn][maxn],tmp[maxn][maxn];
map<int,int> hsh;
inline void cal(int a[maxn][maxn],int b[maxn][maxn],int c[maxn][maxn])
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		c[i][j]=oo;
		for(int k=1;k<=n;k++) c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
	}
}
void ksm(int a[maxn][maxn],int b,int c[maxn][maxn])
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=oo;
	for(int i=1;i<=n;i++) c[i][i]=0;
	for(;b;b>>=1)
	{
		if(b&1) { cal(a,c,tmp); memcpy(c,tmp,4*maxn*maxn); }
		cal(a,a,tmp);
		memcpy(a,tmp,4*maxn*maxn);
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d%d%d",&P,&m,&s,&e);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&c[i],&a[i],&b[i]);
	for(int i=1;i<=m;i++)
	{
		if(hsh[a[i]]==0) hsh[a[i]]=++n;
		if(hsh[b[i]]==0) hsh[b[i]]=++n;
	}
	if(hsh[s]==0||hsh[e]==0) return 1;
	memset(d,0x3f,sizeof(d));
	// printf("n=%d s=%d e=%d\n",n,hsh[s],hsh[e]);
	for(int i=1;i<=m;i++)
	{
		d[hsh[a[i]]][hsh[b[i]]]=d[hsh[b[i]]][hsh[a[i]]]=c[i];
		// printf("(%d,%d,%d)\n",hsh[a[i]],hsh[b[i]],c[i]);
	}
	ksm(d,P,res);
	printf("%d\n",res[hsh[s]][hsh[e]]);
	return 0;
}