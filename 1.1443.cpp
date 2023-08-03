// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=405;
const int dr[]={-2,-2,-1,1,2,2,1,-1};
const int dc[]={-1,1,2,2,1,-1,-2,-2};
struct node { int r,c; };
int dis[maxn][maxn];
int n,m,r,c;
int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&c);
	memset(dis,-1,sizeof(dis));
	queue<node> que;
	que.push((node){r,c});
	dis[r][c]=0;
	while(que.size())
	{
		node u=que.front(); que.pop();
		for(int i=0;i<8;i++)
		{
			node v=(node){u.r+dr[i],u.c+dc[i]};
			if(v.r>=1&&v.r<=n&&v.c>=1&&v.c<=m&&dis[v.r][v.c]==-1)
			{
				dis[v.r][v.c]=dis[u.r][u.c]+1;
				que.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%-5d",dis[i][j]);
		printf("\n");
	} 
	return 0;
}
