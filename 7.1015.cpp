#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int f[25][805];
int d[205][25][805];
int n,m,a[205],b[205],SA,SB,T;
vector<int> Q;
void GetPath(int i,int j,int k)
{
	if(j==0) return;
	int last=d[i][j][k];
	GetPath(last-1,j-1,k-(a[last]-b[last]));
	Q.push_back(last);
	SA+=a[last]; SB+=b[last];
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		memset(f,0xcf,sizeof(f));
		f[0][400]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++) for(int k=0;k<=800;k++) d[i][j][k]=d[i-1][j][k];
			for(int j=m;j;j--)
				for(int k=0;k<=800;k++)
				{
					if(k-(a[i]-b[i])<0||k-(a[i]-b[i])>800) continue;
					if(f[j][k]<f[j-1][k-(a[i]-b[i])]+a[i]+b[i])
					{
						f[j][k]=f[j-1][k-(a[i]-b[i])]+a[i]+b[i];
						d[i][j][k]=i;
					}
				}
		}
		int res=0;
		for(int k=0;k<=400;k++)
		{
			if(f[m][400+k]>=0&&f[m][400+k]>=f[m][400-k]) { res=k+400; break; }
			if(f[m][400-k]>=0) { res=400-k; break; }
		}
		Q.clear();
		SA=SB=0;
		GetPath(n,m,res);
		printf("Jury #%d\n",++T);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",SA,SB);
		for(int i=0;i<Q.size();i++) printf(" %d",Q[i]);
		printf("\n\n");
	}
	return 0;
}