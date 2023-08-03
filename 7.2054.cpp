#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,r,v[maxn],vy[maxn],fa[maxn],cnt[maxn],pre[maxn],nxt[maxn];
void print(int p)
{
	int t=p;
	printf("{%d",p); p=nxt[p];
	while(p!=t) { printf(",%d",p); p=nxt[p]; }
	puts("}");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&r)==2&&!(n==0&&r==0))
	{
		memset(cnt,0,sizeof(cnt));
		memset(fa,0,sizeof(fa));
		memset(pre,0,sizeof(pre));
		memset(nxt,0,sizeof(nxt));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			cnt[i]=1; pre[i]=nxt[i]=i;
		}
		memcpy(vy,v,sizeof(vy));
		for(int i=0;i<n-1;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			fa[y]=x;
		}
		for(int i=0;i<n-1;i++)
		{
			int p=0;
			for(int j=1;j<=n;j++) if(j!=r&&cnt[j])
			{
				if(!p) p=j;
				else if(v[p]*cnt[j]<v[j]*cnt[p]) p=j;
			}
//			printf("pose %d\n",p);
			int f=fa[p];
			while(!cnt[f]) fa[p]=f=fa[f];
			int tmp=pre[p];
			pre[p]=pre[f];
			nxt[tmp]=f;
			pre[f]=tmp;
			nxt[pre[p]]=p;
			v[f]+=v[p];
			cnt[f]+=cnt[p];
			cnt[p]=0;
		}
		int res=0;
		for(int i=1,p=r;i<=n;i++,p=nxt[p]) res+=i*vy[p];
//		print(r);
		printf("%d\n",res);
	}
	return 0;
}
