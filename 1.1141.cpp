// luogu-judger-enable-o2
#include<cstdio>
#include<queue>
using namespace std;
const int dr[]={-1,1,0,0};
const int dc[]={0,0,-1,1};
struct node { int r,c; };
const int maxn=1005;
char mp[maxn][maxn];
int idx[maxn][maxn],cnt[maxn*maxn];
int n,m,icnt;
void bfs(int r,int c,int id)
{
	idx[r][c]=id;
	queue<node> que;
	que.push((node){r,c});
	while(que.size())
	{
		cnt[id]++;
		node u=que.front(); que.pop();
		for(int i=0;i<4;i++)
		{
			node v=(node){u.r+dr[i],u.c+dc[i]};
			if(v.r>=1&&v.r<=n&&v.c>=1&&v.c<=n&&!idx[v.r][v.c]&&mp[u.r][u.c]!=mp[v.r][v.c])
			{
				idx[v.r][v.c]=id;
				que.push(v);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",&mp[i][1]);
	int r,c;
	while(m-->0)
	{
		scanf("%d%d",&r,&c);
		if(idx[r][c]) printf("%d\n",cnt[idx[r][c]]);
		else
		{
			bfs(r,c,++icnt);
			printf("%d\n",cnt[icnt]);
		}
	}
	return 0;
}
