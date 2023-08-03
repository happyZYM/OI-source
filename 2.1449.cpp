#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
const int sigsize=26;
const int maxnode=150*75;
map<string,int> ms;
struct ACmachine
{
	int E[maxnode][sigsize];
	int val[maxnode];
	int f[maxnode];
	int last[maxnode];
	int cnt[151];
	int sz;
	ACmachine()
	{
		sz=1;
	}
	void clear()
	{
		memset(this,0,sizeof(ACmachine));
		ms.clear();
		sz=1;
	}
	inline int idx(char a) { return a-'a'; }
	void insert(char *s,int v)
	{
		if(ms.count(string(s))) return;
		int len=strlen(s),u=0;
		for(int i=0,v;i<len;i++)
		{
			if(!E[u][idx(s[i])])
				E[u][idx(s[i])]=sz++;
			u=E[u][idx(s[i])];
		}
		val[u]=v;
		ms[string(s)]=v;
	}
	void print(int j)
	{
begin:
		if(j)
		{
			cnt[val[j]]++;
			j=last[j];
			goto begin;
		}
	}
	void find(char *T)
	{
		int n=strlen(T);
		int j=0;
		for(int i=0;i<n;i++)
		{
			int c=idx(T[i]);
			j=E[j][c];
			if(val[j]) print(j);
			else if(last[j]) print(last[j]);
		}
	}
	void getFail()
	{
		queue<int> q;
		f[0]=0;
		for(int c=0;c<sigsize;c++)
		{
			int u=E[0][c];
			if(u)
				q.push((last[u]=f[u]=0,u));
		}
		while(q.size())
		{
			int r=q.front();q.pop();
			for(int c=0;c<sigsize;c++)
			{
				int u=E[r][c];
				if(!u)
				{
					E[r][c]=E[f[r]][c];
					continue;
				}
				q.push(u);
				int v=f[r];
//				while(v&&!E[v][c]) v=f[v];
				f[u]=E[v][c];
				last[u]=val[f[u]]?f[u]:last[f[u]];
			}
		}
	}
} ac;
char text[1000005],p[151][80];
int n,T;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		ac.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",p[i]);
			ac.insert(p[i],i);
		}
		ac.getFail();
		scanf("%s",text);
		ac.find(text);
		int best=-1;
		for(int i=1;i<=n;i++)
			if(ac.cnt[i]>best) best=ac.cnt[i];
		printf("%d\n",best);
		for(int i=1;i<=n;i++)
			if(ac.cnt[ms[string(p[i])]]==best) printf("%s\n",p[i]);
	}
	return 0;
}
