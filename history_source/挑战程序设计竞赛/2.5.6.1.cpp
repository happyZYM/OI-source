#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
struct edge
{
	int to,cost;
	edge(){}
	edge(int t,int c)
	{
		to=t;
		cost=c;
	}
};
#define P pair<int,int>
int n,r;
vector<edge> G[5001];
int dist[5001],dist2[5001];
const int oo=1<<30;
void solve()
{
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dist,dist+n,oo);
	fill(dist2,dist2+n,oo);
	dist[0]=0;
	que.push(P(0,0));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second,d=p.first;
		if(dist2[v]<d) continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
			int d2=d+e.cost;
			if(dist[e.to]>d2)
			{
				swap(dist[e.to],d2);
				que.push(make_pair(dist[e.to],e.to));
			}
			if(dist2[e.to]>d2&&dist[e.to]<d2)
			{
				dist2[e.to]=d2;
				que.push(P(dist2[e.to],e.to));
			}
		}
	}
	printf("%d\n",dist2[n-1]);
}
void init()
{
	int f,t,c;
	scanf("%d%d",&n,&r);
	for(int i=0;i<r;i++)
	{
		scanf("%d%d%d",&f,&t,&c);
		G[f].push_back(edge(t,c));
	}
}
int main()
{
	init();
	solve();
	return 0;
}
