#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005];
int n,q,x,cnt=1,*p;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&q)==2)
	{
		if(n==0&&q==0) return 0;
		for(int i=0;i<n;i++) scanf("%d",a+i);
		printf("CASE# %d:\n",cnt++);
		sort(a,a+n);
		while(q-->0)
		{
			scanf("%d",&x);
			p=lower_bound(a,a+n,x);
			if(*p==x) printf("%d found at %d\n",x,p-a+1);
			else printf("%d not found\n",x);
		}
	}
	return 0;
}
/*
Sample Input
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
Sample Output
CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3
*/
