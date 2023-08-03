#ifdef wxp
	#include"all.h"
#else
	#include<bits/stdc++.h>
#endif
using namespace std;
const int maxn=505;
const int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
int n,m,a[maxn][maxn];
int vis[maxn][maxn],L[maxn][maxn],R[maxn][maxn];
#define nr (r+dr[i])
#define nc (c+dc[i])
void dfs(int r,int c)
{
	vis[r][c]=true;
	for(int i=0;i<4;i++)
	{
		if(nr<1||nr>n||nc<1||nc>m) continue;
		if(a[nr][nc]>=a[r][c]) continue;
		if(!vis[nr][nc]) dfs(nr,nc);
		L[r][c]=min(L[r][c],L[nr][nc]);
		R[r][c]=max(R[r][c],R[nr][nc]);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	memset(L,0x3f,sizeof(L));
	for(int i=1;i<=m;i++) L[n][i]=R[n][i]=i;
	for(int i=1;i<=m;i++) if(!vis[1][i]) dfs(1,i);
	int cnt=0,now=1;
	for(int i=1;i<=m;i++) cnt+=!vis[n][i];
	if(cnt) { printf("0\n%d\n",cnt); return 0; }
//	for(int i=1;i<=m;i++) printf("L[%d]=%d R[%d]=%d\n",i,L[1][i],i,R[1][i]);
	while(now<=m)
	{
		int maxr=0;
		for(int i=1;i<=m;i++) if(L[1][i]<=now) maxr=max(maxr,R[1][i]);
		cnt++;
		now=maxr+1;
	}
	printf("1\n%d\n",cnt);
	return 0;
}
