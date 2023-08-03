#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,res,now;
int main()
{
	scanf("%d%d",&n,&res); now=res;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		now=max(now+x,x);
		res=max(now,res);
	}
	printf("%d\n",res);
	return 0;
}
