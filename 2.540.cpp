#include<cstdio>
#include<queue>
#include<map>
using namespace std;
const int maxt=1010;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
	int t,kase=0;
	while(scanf("%d",&t)==1&&t)
	{
		printf("Scenario #%d\n",++kase);
		map<int,int> team;
		for(int i=0;i<t;i++)
		{
			int n,x;
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&x);
				team[x]=i;
			}
		}
		queue<int> q,q2[maxt];
		while(1)
		{
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D')
			{
				int t=q.front();
				printf("%d\n",q2[t].front());
				q2[t].pop();
				if(q2[t].empty()) q.pop();
			}
			else if(cmd[0]=='E')
			{
				scanf("%d",&x);
				int t=team[x];
				if(q2[t].empty()) q.push(t);
				q2[t].push(x);
			}
		}
		printf("\n");
	}
	return 0;
}
/*
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0
Sample Output
Scenario #1
101
102
103
201
202
203
Scenario #2
259001
259002
259003
259004
259005
260001
*/
