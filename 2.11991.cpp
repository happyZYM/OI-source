#include<cstdio>
#include<vector>
#include<map>
using namespace std;
map<int,vector<int>> mp;
int n,m,x,y;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		mp.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			mp[x].push_back(i+1);
		}
		while(m--)
		{
			scanf("%d%d",&x,&y);
			if(!mp.count(y)||mp[y].size()<x) printf("0\n");
			else printf("%d\n",mp[y][x-1]);
		}
	}
	return 0;
}
