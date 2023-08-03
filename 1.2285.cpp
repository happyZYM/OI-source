#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=10005;
int n,m,t[maxm],x[maxm],y[maxm],f[maxm],res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&t[i],&x[i],&y[i]);
	for(int i=1;i<=m;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]))
				f[i]=max(f[i],f[j]+1);
		res=max(res,f[i]);
	}
	printf("%d\n",res);
	return 0;
}
{0,1,0,0,0,0,0,1},
{1,0,1,0,0,0,0,0},
{0,1,0 1,0,0,0,0},
{0,0,1 0,0,0,0,0},
{0,0,0 1,0,1,0,0},
{0,0,0 0,0,0,1,0},
{0,0,0 0,0,1,0,1},
{1,0,0 0,0,0,1,0}
