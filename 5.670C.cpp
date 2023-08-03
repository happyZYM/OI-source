#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,m,a[maxn],b[maxn],c[maxn],d[maxn*3],dc,cnt[maxn*3];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	for(int i=0;i<m;i++) scanf("%d",&c[i]);
	for(int i=0;i<n;i++) d[dc++]=a[i];
	for(int i=0;i<m;i++) { d[dc++]=b[i]; d[dc++]=c[i]; }
	sort(d,d+dc);
	dc=unique(d,d+dc)-d;
	for(int i=0;i<n;i++) a[i]=lower_bound(d,d+dc,a[i])-d;
	for(int i=0;i<m;i++)
	{
		b[i]=lower_bound(d,d+dc,b[i])-d;
		c[i]=lower_bound(d,d+dc,c[i])-d;
	}
	for(int i=0;i<n;i++) cnt[a[i]]++;
	int res=0;
	for(int i=1;i<m;i++)
	{
		if(cnt[b[i]]>cnt[b[res]]) res=i;
		else if(cnt[b[i]]==cnt[b[res]]&&cnt[c[i]]>cnt[c[res]]) res=i;
	}
	printf("%d\n",res+1);
	return 0;
}
