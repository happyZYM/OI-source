#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,c[100005];
void upd(int p,int v)
{
	for(;p<=n;p+=(p&-p)) c[p]^=v;
}
int qry(int p)
{
	int v=0;
	for(;p;p-=(p&-p)) v^=c[p];
	return v;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		int op,l,r; scanf("%d%d",&op,&l);
		if(op==1)
		{
			scanf("%d",&r);
			upd(l,1);
			upd(r+1,1);
		}
		else printf("%d\n",qry(l));
	}
	return 0;
}