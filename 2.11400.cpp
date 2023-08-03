#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[1005],d[1005];
struct node
{
	int v,k,c,l;
};
node a[1005];
bool cmp(const node& a,const node& b)
{
	return a.v<b.v;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i].l;
		for(int i=1;i<=n;i++)
		{
			d[i]=1<<30;
			for(int j=0;j<i;j++)
				d[i]=min(d[i],d[j]+(s[i]-s[j])*a[i].c+a[i].k);
		}
		printf("%d\n",d[n]);
	}
	return 0;
}
