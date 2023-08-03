#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500005;
int T,n,x;
int a[2][maxn],cnt[2];
int cal(int d)//d +first
{
	if(cnt[d]==0) return 0;
	int res=1,now=a[d][0],p[2],np;
	p[d]=1;p[d^1]=0;
	while(true)
	{
		np=(res&1)^d;
		if(p[np]>=cnt[np]) break;
		while(p[np]<cnt[np]&&now>=a[np][p[np]])
			p[np]++;
		if(p[np]>=cnt[np]) break;
		res++;
		now=a[np][p[np]];
		p[np]++;
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x>0][cnt[x>0]++]=(x>0?x:-x);
		}
		sort(a[0],a[0]+cnt[0]);
		sort(a[1],a[1]+cnt[1]);
		printf("%d\n",max(cal(1),cal(0)));
	}
	return 0;
}
