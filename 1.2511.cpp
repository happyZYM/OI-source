#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=10007;
const int maxn=50005;
int n,m,a[maxn],len,s[maxn],f[maxn],le[maxn],tot;
bool check(int len)
{
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(tot+a[i]<=len) tot+=a[i];
		else { cnt++; tot=a[i]; }
	}
	return cnt<=m;
}
void cal()
{
	int L=0,R=0,M;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		L=max(L,a[i]);
		R+=a[i];
	}
	len=R;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(check(M)) len=M,R=M-1;
		else L=M+1;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	cal();
	for(int i=2;i<=n;i++) a[i]+=a[i-1];
	int now=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[now]>len) now++;
		le[i]=now;
	}
	fill(s,s+n+1,1);
	for(int i=1;i<=m+1;i++)
	{
		for(int j=1;j<=n;j++)
			f[j]=(s[j-1]-s[le[j]-1])%mod;
		s[0]=0;
		for(int j=1;j<=n;j++)
			s[j]=f[j]+s[j-1];
		tot=(tot+f[n])%mod;
	}
	printf("%d %d\n",len,tot);
	return 0;
}
