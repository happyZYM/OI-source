#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int n,m,a[105][105],f[105][105],pre[105][105];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++) f[1][i]=a[1][i];
	for(int i=2;i<=n;i++)
		for(int j=i;j<=m;j++)
			for(int k=i-1;k<j;k++)
				if(f[i-1][k]+a[i][j]>f[i][j])
				{
					pre[i][j]=k;
					f[i][j]=f[i-1][k]+a[i][j];
				}
	int id=n;
	for(int i=n+1;i<=m;i++) if(f[n][i]>f[n][id]) id=i;
	printf("%d\n",f[n][id]);
	int p=id; stack<int> stk;
	for(int i=n;i>=1;i--)
	{
		stk.push(p);
		p=pre[i][p];
	}
	while(stk.size()) { printf("%d ",stk.top()); stk.pop(); } puts("");
	return 0;
}