#include<cstdio>
#include<algorithm>
using namespace std;
const int MN=300000;
const int MX=15000000;
int a[MN+5],u[MX+5],p[MX+5],pn,s[MX+5];
int gcd(int a,int b) { return b?gcd(b,a%b):a; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n,i,j,g,x,ans=0;
	for(i=2;i<=MX;++i)
	{
		if(!u[i]) u[i]=p[++pn]=i;
		for(j=1;i*p[j]<=MX;++j) { u[i*p[j]]=p[j]; if(i%p[j]==0) break; }
	}
	scanf("%d",&n);
	for(g=0,i=1;i<=n;++i) scanf("%d",&a[i]),g=gcd(g,a[i]);
	for(i=1;i<=n;++i) for(j=a[i]/g;j>1;) for(++s[x=u[j]];u[j]==x;) j/=u[j];
	for(i=1;i<=MX;++i) ans=max(ans,s[i]);
	printf("%d",ans?n-ans:-1);
	return 0;
}
