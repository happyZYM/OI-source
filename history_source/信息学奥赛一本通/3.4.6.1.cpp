#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x,y,v;
	bool operator<(node &b)
	{return v<b.v;}
};
node a[1005];
int fa[105],sum,minn,n,k,s,m;
int ff(int x)
{
	static int t1,t2;
	t1=x;
	while(fa[x]!=x) x=fa[x];
	while(t1!=x) t2=fa[t1],fa[t1]=x,t1=t2;
	return x;
}
int main()
{
	freopen("net.in","r",stdin);
	freopen("net.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
		sum+=a[i].v;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a,a+k);
	for(int i=0;s<n-1;i++)
		if(ff(a[i].x)!=ff(a[i].y))
		{
			minn+=a[i].v;
			fa[ff(a[i].y)]=ff(a[i].x);
			s++;
		}
	printf("%d\n",sum-minn);
	return 0;
}
