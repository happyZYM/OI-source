#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=500005;
struct Edge { int v; Edge *next; };
Edge mem[maxn],*G[maxn],*ecnt=mem;
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
char s[maxn]; int n,pos=1;
void build()
{
	if(s[pos]==0) { pos++; return; }
	int u=pos++;
//	printf("add %d -> %d\n",u,pos);
	AddEdge(u,pos); build();
	if(s[u]==1) return;
//	printf("add %d -> %d\n",u,pos);
	AddEdge(u,pos); build();
}
int mx[maxn][3],mi[maxn][3];
void dp(int u)
{
	if(s[u]==0)
	{
		mx[u][0]=mx[u][2]=0; mx[u][1]=1;
		mi[u][0]=mi[u][2]=0; mi[u][1]=1;
	}
	if(s[u]==1)
	{
		int v=G[u]->v;
		dp(v);
		mx[u][0]=max({mx[v][1],mx[v][2]});
		mx[u][1]=1+max({mx[v][0],mx[v][2]});
		mx[u][2]=max({mx[v][1],mx[v][0]});
		mi[u][0]=min({mi[v][1],mi[v][2]});
		mi[u][1]=1+min({mi[v][0],mi[v][2]});
		mi[u][2]=min({mi[v][1],mi[v][0]});
	}
	if(s[u]==2)
	{
		int v1=G[u]->v,v2=G[u]->next->v;
		dp(v1); dp(v2);
		mx[u][0]=max({mx[v1][1]+mx[v2][2],mx[v1][2]+mx[v2][1]});
		mx[u][1]=1+max({mx[v1][0]+mx[v2][2],mx[v1][2]+mx[v2][0]});
		mx[u][2]=max({mx[v1][0]+mx[v2][1],mx[v1][1]+mx[v2][0]});
		mi[u][0]=min({mi[v1][1]+mi[v2][2],mi[v1][2]+mi[v2][1]});
		mi[u][1]=1+min({mi[v1][0]+mi[v2][2],mi[v1][2]+mi[v2][0]});
		mi[u][2]=min({mi[v1][0]+mi[v2][1],mi[v1][1]+mi[v2][0]});
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) s[i]-='0';
	build();
	dp(1);
//	for(int i=1;i<=n;i++)
//		printf("mx[%d][0]=%d mx[%d][1]=%d mx[%d][2]=%d\n",i,mx[i][0],i,mx[i][1],i,mx[i][2]);
//	printf("\n");
//	for(int i=1;i<=n;i++)
//		printf("mi[%d][0]=%d mi[%d][1]=%d mi[%d][2]=%d\n",i,mi[i][0],i,mi[i][1],i,mi[i][2]);
//	printf("\n");
	printf("%d %d\n",max({mx[1][0],mx[1][1],mx[1][2]}),min({mi[1][0],mi[1][1],mi[1][2]}));
	return 0;
}
