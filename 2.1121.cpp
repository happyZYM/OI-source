#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,S,b[maxn],x;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&S)==2)
	{
		b[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			b[i]=b[i-1]+x;
		}
		int res=n+1,i=1;
		for(int j=1;j<=n;j++)
		{
			if(b[i-1]+S>b[j]) continue;
			while(b[i]+S<=b[j]) i++;
			res=min(res,j-i+1);
		}
		printf("%d\n",res==n+1?0:res);
	}
	return 0;
}
