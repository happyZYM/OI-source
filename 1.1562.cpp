#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
int n,tot,inv,lg[1<<15]; char mp[15][15];
void dfs(int dep,int M,int L,int R)
{
	if(dep==n) { tot++; return; }
	int can=M|L|R;
	for(int it=inv&(can^inv);it;it-=it&-it)
	{
		int i=lg[it&-it];
		if(mp[dep][i]!='.') dfs(dep+1,M|(1<<i),(L|(1<<i))<<1,(R|(1<<i))>>1);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",mp[i]);
	inv=(1<<n)-1;
	for(int i=0;i<n;i++) lg[1<<i]=i;
	dfs(0,0,0,0);
	printf("%d\n",tot);
	return 0;
}
