#include<cstdio>
#include<algorithm>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Ford(i,a,b) for(int i=(a);i>=(b);i--)
const int maxn=2005;
int n,m,a[maxn][maxn],MaxS,MaxJ,lef[maxn][maxn],rig[maxn][maxn],up[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n)
	{
		lef[i][1]=1; rig[i][m]=m;
		For(j,2,m) lef[i][j]=(a[i][j]!=a[i][j-1]?lef[i][j-1]:j);
		Ford(j,m-1,1) rig[i][j]=(a[i][j]!=a[i][j+1]?rig[i][j+1]:j);
	}
	For(i,1,n) For(j,1,m)
	{
		up[i][j]=1;
		if(i>1&&a[i][j]!=a[i-1][j])
		{
			lef[i][j]=max(lef[i][j],lef[i-1][j]);
			rig[i][j]=min(rig[i][j],rig[i-1][j]);
			up[i][j]=up[i-1][j]+1;
		}
		int wide=rig[i][j]-lef[i][j]+1,len=min(wide,up[i][j]);
		MaxS=max(MaxS,len*len);
		MaxJ=max(MaxJ,wide*up[i][j]);
	}
	printf("%d\n%d\n",MaxS,MaxJ);
	return 0;
}
