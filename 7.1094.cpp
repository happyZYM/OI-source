#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;
const int maxn=30;
int n,m,d[maxn][maxn],in[maxn];
char s[maxn][4];
int solve(int m)
{
	memset(d,0,sizeof(d));
	for(int i=1;i<=m;i++) d[s[i][0]-'A'+1][s[i][2]-'A'+1]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]|=d[i][k]&d[k][j];
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			if(d[i][j]&&d[j][i]) { printf("Inconsistency found after %d relations.\n",m); return 1; }
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&d[i][j]+d[j][i]==0) return 0;
	printf("Sorted sequence determined after %d relations: ",m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(d[i][j]) in[j]++;
	queue<int> Q;
	for(int i=1;i<=n;i++) if(in[i]==0) Q.push(i);
	assert(Q.size()==1);
	while(Q.size())
	{
		int u=Q.front(); Q.pop();
		printf("%c",char(u-1+'A'));
		for(int i=1;i<=n;i++) if(d[u][i])
		{
			d[u][i]=0;
			in[i]--;
			if(in[i]==0) Q.push(i);
		}
	}
	puts(".");
	return 1;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n+m)
	{
		for(int i=1;i<=m;i++) scanf("%s",s[i]);
		for(int i=1;i<=m;i++) if(solve(i)) goto nxt;
		puts("Sorted sequence cannot be determined.");
		nxt:continue;
	}
	return 0;
}