#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,res,now,v;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&x);
	res=now=1; v=x;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==v+1) { v=x; now++; }
		else { v=x; now=1; }
		res=max(res,now);
	}
	printf("%d\n",res);
	return 0;
}
