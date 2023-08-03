#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,r[maxn],left[maxn],right[maxn];
bool check(int p)
{
	int x=r[1],y=p-r[1];
	left[1]=x;right[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(i&1)
		{
			right[i]=min(y-right[i-1],r[i]);
			left[i]=r[i]-right[i];
		}
		else
		{
			left[i]=min(x-left[i-1],r[i]);
			right[i]=r[i]-left[i];
		}
	}
	return left[n]==0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d",&r[i]);
		if(n==1) { printf("%d\n",r[1]); continue; }
		r[n+1]=r[1];
		
		int L=0,R=0;
		for(int i=1;i<=n;i++) L=max(L,r[i]+r[i+1]);
		if(n&1)
		{
			for(int i=1;i<=n;i++) R=max(R,r[i]*3);
			while(L<R)
			{
				int M=(L+R)>>1;
				if(check(M)) R=M;
				else L=M+1;
			}
		}
		printf("%d\n",L);
	}
	return 0;
}
