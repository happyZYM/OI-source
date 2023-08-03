#include<cstdio>
#include<cstring>
#define maxn 105
bool vis[maxn];
int n,m,be_smaller[maxn][maxn],num2[maxn],be_bigger[maxn][maxn],num1[maxn],queue[maxn],head,tail;
//int lit[maxn],big[maxn];
int f1(int a)
{
//	if(lit[a]>-1) return lit[a];
	head=tail=0;
	queue[tail++]=a;
	memset(vis,1,sizeof(vis));
	static int i;
	while(head<tail)
	{
		for(i=0;i<num1[queue[head]];i++)
			if(vis[be_bigger[queue[head]][i]])
			{
				vis[be_bigger[queue[head]][i]]=0;
				queue[tail++]=be_bigger[queue[head]][i];
			}
		head++;
	}
//	lit[a]=tail-1;
	return tail-1;
}
int f2(int a)
{
//	if(big[a]>-1) return big[a];
	head=tail=0;
	queue[tail++]=a;
	memset(vis,1,sizeof(vis));
	static int i;
	while(head<tail)
	{
		for(i=0;i<num2[queue[head]];i++)
			if(vis[be_smaller[queue[head]][i]])
			{
				vis[be_smaller[queue[head]][i]]=0;
				queue[tail++]=be_smaller[queue[head]][i];
			}
		head++;
	}
//	big[a]=tail-1;
	return tail-1;
}
//void print()
//{
//	for(int i=1;i<=n;i++) printf("lit[%d]=%d ",i,lit[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++) printf("big[%d]=%d ",i,big[i]);
//	printf("\n");
//}
int main()
{
//	memset(lit,-1,sizeof(lit));
//	memset(big,-1,sizeof(big));
	freopen("BEAD.in","r",stdin);
	freopen("BEAD.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j,k,a,b,ans=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		be_bigger[a][num1[a]++]=b;
		be_smaller[b][num2[b]++]=a;
	}
	for(i=1;i<=n;i++)
		if(f1(i)>=(n+1)/2||f2(i)>=(n+1)/2) ans++;
	printf("%d\n",ans);
//	print();
	return 0;
}
