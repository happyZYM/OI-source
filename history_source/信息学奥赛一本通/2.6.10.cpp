#include<cstdio>
#include<algorithm>
using std::sort;
#define maxTest 20
#define maxN 1000
#define min(a,b) ((a)<(b)?(a):(b))
int times[maxN];
int ans[maxTest];
int main()
{
	int n,t,t1,t2,j;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++) scanf("%d",times+j);
		sort(times,times+n);
		ans[i]=0;
		for(j=n;j>3;j-=2)
			ans[i]+=
			min(2*times[1]+times[0]+times[j-1],
			2*times[0]+times[j-2]+times[j-1]);
		if(j==3) ans[i]+=times[0]+times[1]+times[2];
		if(j==2) ans[i]+=times[1];
		if(j==1) ans[i]+=times[0];
	}
	for(int i=0;i<t;i++) printf("%d\n",ans[i]);
	return 0;
}
