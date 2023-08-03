//http://acm.hdu.edu.cn/showproblem.php?pid=4261
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;
typedef long long LL;
const int maxn=2005;
const int maxm=30;
int n,m,a[maxn];
LL f[maxm][maxn],b[maxn][maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&m)==2&&!(n==0&&m==0))
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			priority_queue<LL> L; priority_queue<LL,vector<LL>,greater<LL> > R;
			L.push(a[i]);
			LL SL=a[i],SR=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]>L.top()) { R.push(a[j]); SR+=a[j]; }
				else { L.push(a[j]); SL+=a[j]; }
				while((int)L.size()-(int)R.size()>=2) { SL-=L.top(); SR+=L.top(); R.push(L.top()); L.pop(); }
				while((int)R.size()-(int)L.size()>=1) { SR-=R.top(); SL+=R.top(); L.push(R.top()); R.pop(); }
				b[i][j]=L.top()*L.size()-SL+SR-L.top()*R.size();
				// printf("zws(%d,%d)=%d\n",i,j,L.top());
				// printf("b(%d,%d)=%d\n",i,j,b[i][j]);
			}
		}
		memset(f,0x3f,sizeof(f));
		f[0][0]=0;
		for(int i=1;i<=m;i++)
			for(int j=i;j<=n;j++)
				for(int k=i-1;k<j;k++)
					f[i][j]=min(f[i][j],f[i-1][k]+b[k+1][j]);
		printf("%lld\n",f[m][n]);
	}
	return 0;
}