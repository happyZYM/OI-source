#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxsize=70*150+7;
const int sigsize=26;
struct ACMachine
{
	int e[maxsize][sigsize],f[maxsize],val[maxsize],last[maxsize],cnt;
	void init() { memset(this,0,sizeof(ACMachine)); }
	void insert(char *s,int v)
	{
		int n=strlen(s),p=0;
		for(int i=0;i<n;i++)
		{
			if(!e[p][s[i]-'a']) e[p][s[i]-'a']=++cnt;
			p=e[p][s[i]-'a'];
		}
		val[p]=v;
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
				f[v]=e[k][c];
				last[v]=val[f[v]]?f[v]:last[f[v]];
			}
		}
	}
	void solve(char *s,int *cnt)
	{
		int n=strlen(s),p=0;
		for(int i=0;i<n;i++)
		{
			p=e[p][s[i]-'a'];
			for(int t=p;t;t=last[t]) ++cnt[val[t]];
		}
	}
}AC;
int n;
char s[151][71],T[1000005];
int cnt[151],rnk[151];
inline bool cmp(int a,int b) { return cnt[a]>cnt[b]||(cnt[a]==cnt[b]&&a<b); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		AC.init(); memset(cnt,0,sizeof(cnt)); for(int i=1;i<=n;i++) rnk[i]=i;
		for(int i=1;i<=n;i++) scanf("%s",s[i]),AC.insert(s[i],i);
		scanf("%s",T);
		AC.build(); AC.solve(T,cnt);
		sort(rnk+1,rnk+1+n,cmp);
		printf("%d\n%s\n",cnt[rnk[1]],s[rnk[1]]);
		for(int i=2;cnt[rnk[i]]==cnt[rnk[i-1]]&&i<=n;i++) printf("%s\n",s[rnk[i]]); 
	}
	return 0;
}
