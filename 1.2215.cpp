#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
const int maxm=1005;
const int oo=0x3f3f3f3f;
int n,a[maxn],m,f[maxn],len[maxn],b[maxn];
void solve(int L)
{
	if(lower_bound(f,f+n+1,oo)-f<L) { printf("Impossible\n"); return; }
	//for(int i=0;i<n;i++) printf("len[%d]=%d\n",i,len[i]);
	int mv=-oo,p=0;
	for(int i=0;i<n;i++)
		if(a[i]>mv&&len[i]>=L-p)
		{
			printf("%d ",a[i]);
			mv=a[i];
			p++;
			if(p==L) break;
		}
	printf("\n");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) b[i]=-a[i];
	memset(f,oo,sizeof(f));
	for(int i=n-1;i>=0;i--)
	{
		len[i]=lower_bound(f,f+n+1,b[i])-f+1;
		*lower_bound(f,f+n+1,b[i])=b[i];
	}
	scanf("%d",&m);
	while(m-->0)
	{
		int L; scanf("%d",&L);
		solve(L);
	}
	return 0;
}
