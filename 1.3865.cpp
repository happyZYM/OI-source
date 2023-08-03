// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,l,r;
int d[maxn][20];
int a[maxn];
void RMQ_init(int *A,int n)
{
	for(int i=0;i<n;i++) d[i][0]=A[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)-1<n;i++)
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R)
{
	int k=0;
	while((1<<(k+1))<=R-L+1) k++;
	return max(d[L][k],d[R-(1<<k)+1][k]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	RMQ_init(a,n);
	while(m-->0)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",RMQ(l-1,r-1));
	}
	return 0;
}
/*
8 8
9 3 1 7 5 6 0 8
1 6
1 5
2 7
2 6
1 8
4 8
3 7
1 8
*/
