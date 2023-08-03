#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	int q,d;
};
inline bool operator<(const node &a,const node &b)
{
	return a.d!=b.d?a.d<b.d:a.q<b.q;
}
int n;
node a[800005];
int main()
{
#ifdef local
//	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&a[i].q,&a[i].d);
		sort(a,a+n);
		priority_queue<int> q;
		int res=0,now=0;
		for(int i=0;i<n;i++)
			if(now+a[i].q<=a[i].d)
			{
				now+=a[i].q;
				q.push(a[i].q);
			}
			else if(q.size()>0&&q.top()>a[i].q&&now-q.top()+a[i].q<=a[i].d)
			{
				now-=q.top();
				q.pop();
				now+=a[i].q;
				q.push(a[i].q);
			}
		printf("%d\n",q.size());
		if(T) printf("\n");
	}
	return 0;
}
