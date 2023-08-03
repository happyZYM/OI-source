#include<cstdio>
#include<queue>
using namespace std;
int n,x,res,a,b;
int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=0;i<n;i++) q.push((scanf("%d",&x),x));
		res=0;
		for(int i=0;i<n-1;i++)
		{
			a=q.top();q.pop();
			b=q.top();q.pop();
			res+=a+b;
			q.push(a+b);
		}
		printf("%d\n",res);
	}
	return 0;
}
