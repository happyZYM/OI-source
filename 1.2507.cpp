#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
const LL oo=100000000005ll;
int n,a[maxn],b[maxn]; LL f[maxn];
inline int ab(const int &a,const int &b) { return a==b?oo:(a>b?a-b:b-a); }
void cal()
{
	f[1]=ab(a[1],b[1]);
	if(n==1) return;
	f[2]=min(f[1]+ab(a[2],b[2]),(LL)ab(a[1],b[2])+ab(a[2],b[1]));
	if(n==2) return;
	for(int i=3;i<=n;i++)
	{
		f[i]=f[i-1]+ab(a[i],b[i]);
		f[i]=min(f[i],f[i-2]+ab(a[i],b[i-1])+ab(a[i-1],b[i]));
		f[i]=min(f[i],f[i-3]+ab(a[i],b[i-2])+ab(a[i-1],b[i-1])+ab(a[i-2],b[i]));
		f[i]=min(f[i],f[i-3]+ab(a[i],b[i-1])+ab(a[i-1],b[i-2])+ab(a[i-2],b[i]));
		f[i]=min(f[i],f[i-3]+ab(a[i],b[i-2])+ab(a[i-1],b[i])+ab(a[i-2],b[i-1]));
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+1+n); sort(b+1,b+1+n);
	if(n==1&&a[1]==b[1]) { puts("-1"); return 0; }
	cal();
	printf("%lld\n",f[n]);
	return 0;
}
