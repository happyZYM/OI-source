#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d,n,f[105];
struct Data { int t,f,h; };
Data a[105];
inline bool cmp(const Data &a,const Data &b) { return a.t<b.t; }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	f[0]=10;
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].t,&a[i].f,&a[i].h);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) for(int j=d;j>=0;j--) if(f[j]>=a[i].t)
	{
		if(j+a[i].h>=d) { printf("%d\n",a[i].t); return 0; }
		f[j+a[i].h]=max(f[j+a[i].h],f[j]);
		f[j]+=a[i].f;
	}
	printf("%d\n",f[0]);
	return 0;
}