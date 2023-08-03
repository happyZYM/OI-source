#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int x[20005],d[20005];
int pos,res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2&&!(n==0&&m==0))
	{
		for(int i=0;i<n;i++) scanf("%d",d+i);
		for(int i=0;i<m;i++) scanf("%d",x+i);
		sort(d,d+n);
		sort(x,x+m);
		pos=res=0;
		for(int i=0;i<m;i++)
			if(x[i]>=d[pos])
			{
				res+=x[i];
				if(++pos>=n) break;
			}
		if(pos<n) printf("Loowater is doomed!\n");
		else printf("%d\n",res);
	}
	return 0;
}
