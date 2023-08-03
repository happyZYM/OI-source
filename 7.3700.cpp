#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100],lim,up[100],cu,down[100],cd;
bool dfs(int d)
{
	if(cu+cd>lim) return false;
	if(d==n) return true;
	int idx=-1;
	for(int i=0;i<cu;i++) if(a[d]>up[i])
	{
		if(idx==-1) idx=i;
		else if(up[i]>up[idx]) idx=i;
	}
	if(idx>-1)
	{
		int bk=up[idx];
		up[idx]=a[d];
		if(dfs(d+1)) return true;
		up[idx]=bk;
	}
	else
	{
		up[cu++]=a[d];
		if(dfs(d+1)) return true;
		cu--;
	}
	idx=-1;
	for(int i=0;i<cd;i++) if(a[d]<down[i])
	{
		if(idx==-1) idx=i;
		else if(down[i]<down[idx]) idx=i;
	}
	if(idx>-1)
	{
		int bk=down[idx];
		down[idx]=a[d];
		if(dfs(d+1)) return true;
		down[idx]=bk;
	}
	else
	{
		down[cd++]=a[d];
		if(dfs(d+1)) return true;
		cd--;
	}
	return false;
}
inline int solve()
{
	for(int i=1;i<=n;i++)
	{
		lim=i;
		cu=cd=0;
		if(dfs(0)) return i;
	}
	return n;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		printf("%d\n",solve());
	}
	return 0;
}
