#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20005;
int n,a,p[maxn],cnt,v[maxn],sg[maxn],step[maxn];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=2;i<maxn;i++) v[i]=i;
	for(int i=2;i<maxn;i++)
	{
		if(v[i]==i) { p[cnt++]=i; }
		for(int j=0;j<cnt&&p[j]*i<maxn&&p[j]<=v[i];j++) v[p[j]*i]=p[j];
	}
	for(int i=2;i<maxn;i++)
	{
		for(int j=0;j<cnt&&p[j]<=i;j++) if(sg[i-p[j]]==0) sg[i]=1;
		if(sg[i]==0) for(int j=0;j<cnt&&p[j]<=i;j++) step[i]=max(step[i-p[j]]+1,step[i]);
		else
		{
			for(int j=0;j<cnt&&p[j]<=i;j++) if(sg[i-p[j]]==0)
			{
				if(step[i]==0) step[i]=step[i-p[j]]+1;
				else step[i]=min(step[i],step[i-p[j]]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		printf("%d\n",sg[a]?step[a]:-1);
	}
	return 0;
}