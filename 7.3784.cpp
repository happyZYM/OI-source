#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T,x,n;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&x,&n);
		printf("%d %d\n",x,(n+1)/2);
		priority_queue<int> l;
		priority_queue<int,vector<int>,greater<int> > r;
		scanf("%d",&x); r.push(x);
		printf("%d ",x);
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			if(x<r.top()) l.push(x);
			else r.push(x);
			int s=l.size();
			if(s>i/2) { r.push(l.top()); l.pop(); }
			if(s<i/2) { l.push(r.top()); r.pop(); }
			if(i&1)
			{
				if(cnt%10==0) puts("");
				printf("%d ",r.top());
				cnt++;
			}
			
		}
		puts("");
	}
	return 0;
}
