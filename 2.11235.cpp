#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,q,now,x,s,l,r;
int v[maxn],cnt[maxn],num[maxn],left[maxn],right[maxn];
int d[maxn][20];
void RMQ_init(int *A,int n)
{
	for(int i=0;i<n;i++) d[i][0]=A[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)-1<n;i++)
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R)
{
	if(L>R) return 0;
	int k=0;
	while((1<<(k+1))<=R-L+1) k++;
	return max(d[L][k],d[R-(1<<k)+1][k]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&q)==2)
	{
		scanf("%d",v);
		cnt[0]=1;
		now=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&x);
			if(x==v[now]) cnt[now]++;
			else
			{
				now++;
				v[now]=x;
				cnt[now]=1;
			}
		}
		s=x=0;
		for(int i=0;i<=now;i++)
		{
			for(int j=0;j<cnt[i];j++,x++)
				num[x]=i,left[x]=s,right[x]=s+cnt[i]-1;
			s+=cnt[i];
		}
		RMQ_init(cnt,now+1);
		while(q-->0)
		{
			scanf("%d%d",&l,&r);
			l--;r--;
			if(num[l]==num[r]) printf("%d\n",r-l+1);
			else printf("%d\n",max(max(right[l]-l+1,r-left[r]+1)
					,RMQ(num[l]+1,num[r]-1)));
		}
	}
	return 0;
}
