#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
struct Data { int id,g,res; } it[35],pre[35][5005];
inline bool cmp1(const Data &a,const Data &b) { return a.g>b.g; }
inline bool cmp2(const Data &a,const Data &b) { return a.id<b.id; }
int n,m,f[35][5005];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) { scanf("%d",&it[i].g); it[i].id=i; }
	sort(it+1,it+n+1,cmp1);
	for(int i=1;i<=n;i++) it[i].g+=it[i-1].g;
	memset(f,0x3f,sizeof(f)); f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=m;j++)
		{
			f[i][j]=f[i][j-i]; pre[i][j]=(Data){i,j-i,1};
			int t;
			for(int k=0;k<i;k++)
				if((t=f[k][j-(i-k)]+k*(it[i].g-it[k].g))<f[i][j])
				{
					f[i][j]=t;
					pre[i][j]=(Data){k,j-(i-k),2};
				}
		}
	int pn=n,pm=m,l,r;
	while(pn||pm)
	{
		if(pre[pn][pm].res==1) l=1,r=pn;
		else l=pre[pn][pm].id+1,r=pn;
		// printf("%d %d %d %d\n",pn,pm,l,r);
		for(int i=l;i<=r;i++) it[i].res++;
		int nn=pre[pn][pm].id,nm=pre[pn][pm].g;
		pn=nn; pm=nm;
	}
	sort(it+1,it+n+1,cmp2);
	printf("%d\n",f[n][m]);
	for(int i=1;i<=n;i++) printf("%d ",it[i].res); puts("");
	return 0;
}