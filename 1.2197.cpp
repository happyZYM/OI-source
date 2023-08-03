#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,sg,x;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		n--; scanf("%d",&sg);
		while(n-->0) { scanf("%d",&x); sg^=x; }
		puts(sg?"Yes":"No");
	}
	return 0;
}
