#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1000000;
bool vis[maxn+5]={1,1};
int pri[80000],cnt,n;
typedef long long LL;
LL L,R,t;
int res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int m=(int)sqrt(maxn+0.5),c=0,i,j;
	for(i=2;i<=m;i++)
		if(!vis[i])
			for(j=i*i;j<=maxn;j+=i) vis[j]=1;
	for(i=2;i<=maxn;i++)
		if(!vis[i]) pri[cnt++]=i;
	scanf("%d",&n);
	while(n-->0)
	{
		scanf("%lld%lld",&L,&R);
		res=0;
		for(int i=0;i<cnt;i++)
		{
			t=(LL)pri[i]*pri[i];
			while(t<=R)
			{
				if(t>=L) res++;
				t*=pri[i];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
