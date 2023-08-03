#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int T,mp[5][5],kr,kc,lim;
inline int hsh()
{
	int res=0,cnt=0;
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(mp[i][j]!=-1) res|=mp[i][j]<<(cnt++);
	res<<=3;
	res|=kr*5+kc;
	return res;
}
const int sdb[5][5]={
	{1,1,1,1,1},
	{0,1,1,1,1},
	{0,0,-1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,0}
};
inline int diff()
{
	int tot=0;
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(sdb[i][j]!=mp[i][j]) tot++;
	return tot;
}
//set<int> st;
const int dr[]={-2,-2,-1,1,2,2,1,-1};
const int dc[]={-1,1,2,2,1,-1,-2,-2};
bool dfs(int d)
{
	int g=diff();
	if(d+g-1>lim) return false;
	if(!g) return true;
//	int tz=hsh();
//	if(st.find(tz)!=st.end()) return false;
//	st.insert(tz);
	for(int i=0;i<8;i++)
	{
		kr+=dr[i]; kc+=dc[i];
		if(min(kr,kc)<0||max(kr,kc)>=5) { kr-=dr[i]; kc-=dc[i]; continue; }
		swap(mp[kr][kc],mp[kr-dr[i]][kc-dc[i]]);
		if(dfs(d+1)) return true;
		swap(mp[kr][kc],mp[kr-dr[i]][kc-dc[i]]);
		kr-=dr[i]; kc-=dc[i];
	}
	return false;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		for(int i=0;i<5;i++)
		{
			char buf[6]; scanf("%s",buf);
			for(int j=0;j<5;j++) mp[i][j]=(buf[j]=='*'?(kr=i,kc=j,-1):buf[j]-'0');
		}
		for(lim=0;lim<=15;lim++)
		{
//			st.clear();
			if(dfs(0)) { printf("%d\n",lim); goto nxt; }
		}
		puts("-1");
		nxt:;
	}
	return 0;
}
