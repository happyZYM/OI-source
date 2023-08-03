#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int n,k,a[maxn],q1[maxn],h1,t1,q2[maxn],h2,t2,r1[maxn],r2[maxn];
inline void insert(int p)
{
	while(h1<t1&&a[p]<=a[q1[t1-1]]) t1--;
	q1[t1++]=p;
	while(h2<t2&&a[p]>=a[q2[t2-1]]) t2--;
	q2[t2++]=p;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<k-1;i++) insert(i);
	for(int i=k-1;i<n;i++)
	{
		while(h1<t1&&i-q1[h1]+1>k) h1++;
		while(h2<t2&&i-q2[h2]+1>k) h2++;
		insert(i);
		r1[i-k+1]=a[q1[h1]];
		r2[i-k+1]=a[q2[h2]];
	}
	for(int i=0;i<n-k+1;i++) printf("%d ",r1[i]); puts("");
	for(int i=0;i<n-k+1;i++) printf("%d ",r2[i]); puts("");
	return 0;
}
