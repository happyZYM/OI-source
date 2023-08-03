//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1101%20%E7%81%AB%E8%BD%A6%E8%BF%9B%E6%A0%88
#include<cstdio>
#include<algorithm>
using namespace std;
int n,stk[25],top,res[25],len,cnt;
void dfs(int x)
{
	if(x==n+1)
	{
		cnt++;
		for(int i=0;i<len;i++) printf("%d",res[i]);
		for(int i=top-1;i>=0;i--) printf("%d",stk[i]); puts("");
		if(cnt==20) exit(0);
		return;
	}
	if(top)
	{
		res[len++]=stk[--top];
		dfs(x);
		stk[top++]=res[--len];
	}
	stk[top++]=x;
	dfs(x+1);
	top--;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	dfs(1);
	return 0;
}
