#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
const int maxsize=30000+7;
const int sigsize=2;
struct ACMachine
{
	int e[maxsize][sigsize],f[maxsize],val[maxsize],last[maxsize],cnt;
	bool visiting[maxsize],visited[maxsize];
	void insert(char *s)
	{
		int n=strlen(s),p=0;
		for(int i=0;i<n;i++)
		{
			if(!e[p][s[i]-'0']) e[p][s[i]-'0']=++cnt;
			p=e[p][s[i]-'0'];
		}
		val[p]=true;
	}
	void build()
	{
		queue<int> Q;
		for(int c=0;c<sigsize;c++) if(e[0][c]) Q.push(e[0][c]);
		while(Q.size())
		{
			int u=Q.front(); Q.pop();
			for(int c=0;c<sigsize;c++)
				if(e[u][c])
				{
					Q.push(e[u][c]);
					int t=f[u];
					while(t&&!e[t][c]) t=f[t];
					if(!e[t][c]) f[e[u][c]]=0;
					else
					{
						f[e[u][c]]=e[t][c];
						if(val[e[t][c]]) val[e[u][c]]=true;
					}
				}
				else e[u][c]=e[f[u]][c];
		}
	}
	void dfs(int p)
	{
		visiting[p]=true;
		for(int c=0;c<sigsize;c++)
		{
			int v=e[p][c];
			if(visiting[v]) { puts("TAK"); exit(0); }
			else if(!val[v]&&!visited[v])
			{
				visited[v]=true;
				dfs(v);
			}
		}
		visiting[p]=false;
	}
}AC;
int n;
char s[maxsize];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0) scanf("%s",s),AC.insert(s);
	AC.build(); 
	AC.dfs(0);
	puts("NIE");
	return 0;
}
