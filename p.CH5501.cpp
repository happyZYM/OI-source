#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e6+5;
int n,a[maxn],Q[maxn],head,tail;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) { scanf("%d",&a[i]); a[i+n]=a[i]; }
	int res=0;
	for(int i=1;i<=n*2;i++)
	{
		while(head<tail&&Q[head]<i-n/2) head++;
		if(head<tail) res=max(res,a[i]+i+a[Q[head]]-Q[head]);
		while(head<tail&&a[i]-i>=a[Q[tail-1]]-Q[tail-1]) tail--;
		Q[tail++]=i;
	}
	printf("%d\n",res);
	return 0;
}