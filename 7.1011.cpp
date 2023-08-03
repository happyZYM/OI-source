#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cnt[100],tot;
bool dfs(int lst,int s,int goal,int maxlen)
{
//	printf("(%d,%d,%d,%d)\n",lst,s,goal,maxlen);
	if(lst==0) return true;
	if(s==goal) return dfs(lst-1,0,goal,50);
	for(int i=maxlen;i>=1;i--) if(cnt[i]&&i+s<=goal)
	{
		cnt[i]--;
		if(dfs(lst,s+i,goal,i)) { cnt[i]++; return true; }
		cnt[i]++;
		if(s==0||s+i==goal) return false;
	}
	return false;
}
inline bool check(int len)
{
	return dfs(tot/len,0,len,50);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n),n)
	{
		tot=0; memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			int x; scanf("%d",&x);
			++cnt[x]; tot+=x;
		}
		int res=tot;
		for(int i=1;i*i<=tot;i++) if(tot%i==0)
		{
			if(check(i))
			{ printf("%d\n",i); goto nxt; }
			if(check(tot/i)) res=tot/i;
		}
		printf("%d\n",res);
		nxt:;
	}
	return 0;
}
