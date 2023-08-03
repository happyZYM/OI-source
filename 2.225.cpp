#include<cstdio>
#include<cstring>
#include<conio.h>
int vis[800][800],res[50],n,k,cnt;
char nc[]={'e','n','s','w'};
const int dx[]={+1,+0,+0,-1};
const int dy[]={+0,+1,-1,+0};
const int n1[]={1,0,0,1};
const int n2[]={2,3,3,2};
void init()
{
	memset(vis,0,sizeof(vis));
	cnt=0;
	scanf("%d%d",&n,&k);
	int x,y;
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		x+=400;y+=400;
		if(x>=0&&x<800&&y>=0&&y<800)
		{
//			printf("stone in(%d,%d)\n",x,y);
			vis[x][y]=1;
		}
	}
}
void dfs(int step,int nx,int ny,int np)
{
//	for(int i=0;i<step;i++) printf("    ");
//	printf("vis(%d,%d,%d)!\n",nx,ny,np);
	if(step>=n)
	{
		if(nx==400&&ny==400)
		{
			for(int i=0;i<n;i++) printf("%c",nc[res[i]]);
			printf("\n");
			cnt++;
//			for(int i=0;i<step;i++) printf("    ");
//			printf("    found!\n");
//			getch();
		}
		return;
	}
//	if(vis[nx][ny]) return;
	bool ok;
	res[step]=n1[np];
	ok=1;
	for(int i=0;i<=step+1;i++)
		if(vis[nx+dx[n1[np]]*i][ny+dy[n1[np]]*i])
		{
			ok=0;
			break;
		}
	if(ok) dfs(step+1,nx+dx[n1[np]]*(step+1),ny+dy[n1[np]]*(step+1),n1[np]);
	
	res[step]=n2[np];
	ok=1;
	for(int i=0;i<=step+1;i++)
		if(vis[nx+dx[n2[np]]*i][ny+dy[n2[np]]*i])
		{
			ok=0;
			break;
		}
	if(ok) dfs(step+1,nx+dx[n2[np]]*(step+1),ny+dy[n2[np]]*(step+1),n2[np]);
}
void solve()
{
	if(vis[0][0]) printf("Found 0 golygon(s).\n\n");
	else
	{
		for(int i=0;i<4;i++)
		{
			res[0]=i;
			dfs(1,400+dx[i],400+dy[i],i);
		}
		printf("Found %d golygon(s).\n\n",cnt);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		init();
		solve();
	}
	return 0;
}
