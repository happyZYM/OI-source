#include<cstdio>
#include<queue>
using namespace std;
int ans[133334]={0},n,k,x;
int main()
{
	queue<int>q;
	scanf("%d%d",&n,&k);
	q.push(n);
	ans[n]=1;
	do
	{
		x=q.front();
		if(x>0&&ans[x-1]==0)
		{
			ans[x-1]=ans[x]+1;
			q.push(x-1);
		}
		if(x<k&&ans[x+1]==0)
		{
			ans[x+1]=ans[x]+1;
			q.push(x+1);
		}
		if(x*3<=k*2&&ans[x*2]==0)
		{
			ans[x*2]=ans[x]+1;
			q.push(x*2);
		}
		q.pop();
	}
	while(ans[k]==0);
	printf("%d\n",ans[k]-1);
	return 0;
} 
