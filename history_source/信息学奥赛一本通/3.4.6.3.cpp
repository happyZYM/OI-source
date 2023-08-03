#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,t,fa[10005],k,maxn,len,i;
struct node
{
	int a,b,v;
};
node a[10005];
bool cmp(node a,node b)
{
	return a.v<b.v;
}
int ff(int x)
{
	static int t1,t2;
	t1=x;
	while(fa[x]!=x) x=fa[x];
	while(t1!=x)
	{
		t2=fa[t1];
		fa[t1]=x;
		t1=t2;
	}
	return x;
}
void u(int a,int b)
{
	static int aa,bb;
	aa=ff(a);
	bb=ff(b);
	k++;
	fa[bb]=aa;
}
int main()
{
	freopen("liaison.in","r",stdin);
	freopen("liaison.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&t,&a[len].a,&a[len].b,&a[len].v);
		if(t==1)
		{
			u(a[len].a,a[len].b);
			maxn+=a[len].v;
		}
		else len++;
	}
	sort(a,a+len,cmp);
	for(i=0;i<len;i++)
		if(ff(a[i].a)!=ff(a[i].b))
		{
			maxn+=a[i].v;
			u(a[i].a,a[i].b);
		}
	printf("%d\n",maxn);
	return 0;
}
