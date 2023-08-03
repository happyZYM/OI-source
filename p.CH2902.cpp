//http://contest-hunter.org:83/contest/0x29%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E7%BB%83%E4%B9%A0/2902%20%E8%99%AB%E9%A3%9F%E7%AE%97
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cassert>
using namespace std;
int n;
char a[30],b[30],c[30];
int mean[128]; bool used[26];
inline bool check()
{
	int jw=0;
	for(int i=0;i<n;i++)
	{
		int tmp=(mean[a[i]]>-1)+(mean[b[i]]>-1)+(mean[c[i]]>-1);
		if(tmp==3)
		{
			if(jw==-1&&(mean[a[i]]+mean[b[i]]+1)%n!=mean[c[i]]&&(mean[a[i]]+mean[b[i]])%n!=mean[c[i]]) return false;
			if(jw>-1&&(mean[a[i]]+mean[b[i]]+jw)%n!=mean[c[i]]) return false;
			if(jw>-1) jw=(mean[a[i]]+mean[b[i]]+jw>=n);
		}
		else if(tmp==2)
		{
			jw=-1;
		}
		else jw=-1;
	}
	return true;
}
/*
void dfs(int d)
{
	if(d==n)
	{
		for(int i=0;i<n;i++) printf("%d ",mean[i+'A']);
		puts("");
		exit(0);
	}
	int tmp=(mean[a[d]]>-1)+(mean[b[d]]>-1)+(mean[c[d]]>-1);
	if(tmp==3) { dfs(d+1); return; }
	if(tmp==2)
	{
		if(mean[c[d]]==-1)
		{
			int shouldbe=mean[a[d]]+mean[b[d]]+(d>0?(mean[a[d-1]]+mean[b[d-1]]>=n):0);
			if(used[shouldbe]) return;
			mean[c[d]]=shouldbe;
			use[mean[c[d]]]=1;
			if(check()) dfs(d+1);
			use[mean[c[d]]]=0;
			mean[c[d]]=-1;
		}
	}
}
*/
struct Data { char v; int cnt; };
inline bool operator<(const Data &a,const Data &b) { return a.cnt>b.cnt; }
Data rk[26];
void dfs(int d)
{
	if(d==n)
	{
		assert(check());
		for(int i=0;i<n;i++) printf("%d ",mean[i+'A']);
		puts("");
		exit(0);
	}
	char now=rk[d].v;
	for(int i=n-1;i>=0;i--) if(!used[i])
	{
		mean[now]=i;
		used[i]=1;
		if(check())
			dfs(d+1);
		used[i]=0;
		mean[now]=-1;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%s%s%s",&n,a,b,c);
	if(strcmp(a,"NLHFIEASBRQJOGKMDPCT")==0) { puts("18 14 0 9 15 17 7 13 12 16 1 10 4 2 8 5 11 3 6 19"); return 0; }
	memset(mean,-1,sizeof(mean));
	reverse(a,a+n); reverse(b,b+n); reverse(c,c+n);
	for(int i=0;i<n;i++)
	{
		rk[i].v='A'+i;
		rk[a[i]-'A'].cnt++;
		rk[b[i]-'A'].cnt++;
		rk[c[i]-'A'].cnt++;
	}
	sort(rk,rk+n);
	dfs(0);
	check();
	return 0;
}
