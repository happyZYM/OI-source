#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxsize=1e6+5;
const int sigsize=26;
int n; char str[maxsize];
struct ACMachine
{
	int e[maxsize][sigsize],f[maxsize],val[maxsize],last[maxsize],cnt;
	void insert(char *s)
	{
		int n=strlen(s),p=0;
		for(int i=0;i<n;i++)
		{
			if(!e[p][s[i]-'a']) e[p][s[i]-'a']=++cnt;
			p=e[p][s[i]-'a'];
		}
		++val[p];
	}
	void build()
	{
		queue<int> Q;
		for(int c=0;c<sigsize;c++) if(e[0][c]) Q.push(e[0][c]);
		while(Q.size())
		{
			int u=Q.front(),k=f[u]; Q.pop();
			for(int c=0;c<sigsize;c++)
			{
				int &v=e[u][c];
				if(!v) { v=e[k][c]; continue; }
				Q.push(v);
				f[v]=e[k][c]; last[v]=val[f[v]]?f[v]:last[f[v]];
			}
		}
	}
	int query(char *s)
	{
		int n=strlen(s),p=0,res=0;
		for(int i=0;i<n;i++)
		{
			p=e[p][s[i]-'a'];
			res+=val[p]; val[p]=0;
			int v=p;
			while(last[v])
			{
				v=last[v];
				res+=val[v]; val[v]=0;
			}
		}
		return res;
	}
}AC;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0) scanf("%s",str),AC.insert(str);
	AC.build();
	scanf("%s",str);
	printf("%d\n",AC.query(str));
	return 0;
}
