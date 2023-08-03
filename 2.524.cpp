#include<cstdio>
#include<cstring>
using namespace std;
bool isp[40],used[20];
int n,res[20];
bool ISP(int n)
{
	if(n<=1) return 0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return 0;
	return 1;
}
void dfs(int pos)
{
	if(pos>=n)
	{
		if(isp[1+res[pos-1]])
		{
			printf("1");
			for(int i=1;i<pos;i++) printf(" %d",res[i]);
			printf("\n");
		}
		return;
	}
	for(int i=2;i<=n;i++)
		if(!used[i]&&isp[res[pos-1]+i])
		{
			res[pos]=i;
			used[i]=1;
			dfs(pos+1);
			used[i]=0;
		}
} 
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=0;i<40;i++) isp[i]=ISP(i);
	int cnt=0;
	while(scanf("%d",&n)==1)
	{
		if(cnt) printf("\n");
		printf("Case %d:\n",++cnt);
		memset(used,0,sizeof(used));
		res[0]=1;
		dfs(1);
	}
	return 0;
}
