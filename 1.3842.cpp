#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=20005;
int n,L[maxn],R[maxn],f[maxn][2];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]);
	f[1][0]=R[1]-1+R[1]-L[1]; f[1][1]=R[1]-1;
	for(int i=2;i<=n;i++)
	{
		f[i][0]=min(f[i-1][0]+abs(L[i-1]-R[i])+1+R[i]-L[i],f[i-1][1]+abs(R[i-1]-R[i])+1+R[i]-L[i]);
		f[i][1]=min(f[i-1][0]+abs(L[i-1]-L[i])+1+R[i]-L[i],f[i-1][1]+abs(R[i-1]-L[i])+1+R[i]-L[i]);
	}
//	for(int i=1;i<=n;i++)
//		printf("f[%d][0]=%d f[%d][1]=%d\n",i,f[i][0],i,f[i][1]);
	printf("%d\n",min(f[n][0]+abs(n-L[n]),f[n][1])+abs(n-R[n]));
	return 0;
}
