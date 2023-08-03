#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxnode=20*25;
const int sigsize=62;
int n, tot, L;
int E[maxnode][sigsize],v[maxnode],f[maxnode],vis[maxnode][105];
double d[maxnode][105],p[sigsize];
char s[25],ch[sigsize][5];
int id[128];
inline void insert(char *s)
{
	int len = strlen(s), o = 1;
	for(int i = 0; i < len; i ++)
	{
		int t = id[s[i]];
		if(!E[o][t]) E[o][t] = ++ tot;
		o = E[o][t];
	}
	v[o] = 1;
}
inline void build()
{
	queue<int> q;
	for(int i = 0; i < 62; i ++) E[0][i] = 1; q.push(1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < 62; i ++)
			if(E[u][i])
			{
				f[E[u][i]] = E[f[u]][i];
				q.push(E[u][i]);
				v[E[u][i]] |= v[f[E[u][i]]];
			}
			else E[u][i] = E[f[u]][i];
	}
}
inline double dp(int u, int L)
{
	if(L == 0) return 1;
	if(!u) u = 1;
	if(vis[u][L]) return d[u][L];
	vis[u][L] = 1;
	double res = 0;
	for(int i = 1; i <= n; i ++)
	{
		int t = id[ch[i][0]];
		if(!v[E[u][t]]) res += p[t]*dp(E[u][t], L-1);
	}
	d[u][L] = res;
	return res;
}
int main()
{
	for(char i='0';i<='9';i++) id[i]=tot++;
	for(char i='A';i<='Z';i++) id[i]=tot++;
	for(char i='a';i<='z';i++) id[i]=tot++;
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d", &T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d", &n);
		tot = 1;
		memset(E, 0, sizeof E);
		memset(f, 0, sizeof f);
		memset(v, 0, sizeof v);
		for(int i = 1; i <= n; i ++) { scanf("%s", s); insert(s); }
		build();
		memset(p, 0, sizeof p);
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) { scanf("%s", ch[i]); scanf("%lf", &p[id[ch[i][0]]]); }
		scanf("%d", &L);
		memset(d, 0, sizeof d);
		memset(vis, 0, sizeof vis);
		printf("Case #%d: %.6lf\n",kase, dp(1, L));
	}
	return 0;
}
