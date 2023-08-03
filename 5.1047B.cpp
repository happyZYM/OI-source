#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0) scanf("%d%d",&x,&y),res=max(res,x+y);
	printf("%d\n",res);
	return 0;
}
