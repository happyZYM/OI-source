#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxt=1005;
int n,x,y,tid[1000000],kase;
queue<int> Q0,Q[maxt];
char buf[50];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n),n!=0)
	{
		while(Q0.size()) Q0.pop();
		for(int i=0;i<n;i++)
		{
			while(Q[i].size()) Q[i].pop();
			scanf("%d",&x);
			for(int j=0;j<x;j++)
			{
				scanf("%d",&y);
				tid[y]=i;
			}
		}
		printf("Scenario #%d\n",++kase);
		while(scanf("%s",buf),strcmp(buf,"STOP"))
		{
			if(!strcmp(buf,"ENQUEUE"))
			{
				scanf("%d",&x);
				if(Q[tid[x]].empty()) Q0.push(tid[x]);
				Q[tid[x]].push(x);
			}
			else
			{
				printf("%d\n",Q[Q0.front()].front());
				Q[Q0.front()].pop();
				if(Q[Q0.front()].empty()) Q0.pop();
			}
		}
		puts("");
	}
	return 0;
}
