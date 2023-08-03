#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,x,k_max,k_min;
priority_queue<int,vector<int>,greater<int>> Q;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		k_max=max(k_max,x);
		Q.push(x);
	}
	k_max+=m;
	while(m-->0)
	{
		x=Q.top(); Q.pop();
		x++;
		Q.push(x);
	}
	while(n-->1) Q.pop();
	k_min=Q.top();
	printf("%d %d\n",k_min,k_max);
	return 0;
}
