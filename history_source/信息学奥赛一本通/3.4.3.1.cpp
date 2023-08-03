#include<cstdio>
#define maxn 100
long long dis[maxn+1],oo=0x7fffffffffffffff;
int num[maxn+1],tu[maxn+1][maxn+1],w[maxn+1][maxn+1],pre[maxn+1],queue[2*maxn+5],head,tail,n,e,a,b,c,s,t,i;
bool exist[maxn+1];
const int len=2*maxn+5;
int main()
{
	freopen("msner.in","r",stdin);
	freopen("msner.out","w",stdout);
	scanf("%d%d",&n,&e);
	for(i=1;i<=n;i++) dis[i]=oo;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tu[a][num[a]++]=b;
		tu[b][num[b]++]=a;
		w[a][b]=w[b][a]=c;
	}
	s=1;
	queue[tail++]=s;
	exist[s]=1;
	dis[s]=0;
	while(head!=tail)
	{
		t=queue[head++];
		head%=len;
		exist[t]=0;
		for(i=0;i<num[t];i++)
			if(dis[tu[t][i]]>dis[t]+w[t][tu[t][i]])
			{
				dis[tu[t][i]]=dis[t]+w[t][tu[t][i]];
				pre[tu[t][i]]=t;
				if(!exist[tu[t][i]])
				{
					queue[tail++]=tu[t][i];
					tail%=len;
					exist[tu[t][i]]=1;
				}
			}
	}
	long long max=0;
	for(i=1;i<=n;i++)
	{
		if(dis[i]==oo)
		{
			printf("-1\n");
			return 0;
		}
		if(dis[i]>max) max=dis[i];
	}
	printf("%d\n",max);
	return 0;
}
