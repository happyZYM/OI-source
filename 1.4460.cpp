#include<cstdio>
using namespace std;
inline int max(const int &a,const int &b) { return a>b?a:b; }
inline int min(const int &a,const int &b) { return a<b?a:b; }
const int maxn=21;
const int mod=100000007;
int n,x[maxn],y[maxn],p[maxn][maxn],f[maxn][1<<maxn];
inline bool on(int u,int a,int b)
{
	if(x[u]<min(x[a],x[b])||x[u]>max(x[a],x[b])||y[u]<min(y[a],y[b])||y[u]>max(y[a],y[b])) return 0;
	return (x[u]-x[a])*(y[b]-y[a])==(x[b]-x[a])*(y[u]-y[a]);
}
inline bool ok(int x,int u,int st) { return (p[x][u]&st)==p[x][u]; }
int ct[1<<maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	ct[0]=0; ct[1]=1;
	for(int i=1;i<n;i++)
	{
		int v=1<<i;
		for(int j=0;j<v;j++) ct[v|j]=ct[j]+1;
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j)
		for(int k=0;k<n;k++) if(k!=i&&k!=j&&on(k,i,j))
			p[i][j]|=1<<k;
	int res=0;
	for(int i=0;i<n;i++) f[i][1<<i]=1;
	for(int st=0;st<(1<<n);st++) for(int u=0;u<n;u++)
	{
		if(!f[u][st]) continue;
		if(ct[st]>=4) (res+=f[u][st])%=mod;
		for(register int i=0,j=1;i<n;i++,j<<=1) if(!(st&j))
		{
			if(!ok(i,u,st)) continue;
			(f[i][st|j]+=f[u][st])%=mod;
		}
	}
	printf("%d\n",res);
	return 0;
}
