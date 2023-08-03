#include<cstdio>
#define maxn 2500
long long dis[maxn+1],oo=0x7fffffffffffffff;
int num[maxn+1],tu[maxn+1][maxn+1],w[maxn+1][maxn+1],pre[maxn+1],queue[2*maxn+5],head,tail,n,e,a,b,c,s,t,i;
bool exist[maxn+1];
const int len=2*maxn+5;
int main()
{
	freopen("heatwv.in","r",stdin);
	freopen("heatwv.out","w",stdout);
	int ts,te;
	scanf("%d%d%d%d",&n,&e,&ts,&te);
	for(i=1;i<=n;i++) dis[i]=oo;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tu[a][num[a]++]=b;
		tu[b][num[b]++]=a;
		w[a][b]=w[b][a]=c;
	}
	s=ts;
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
	printf("%d\n",dis[te]);
	return 0;
}
/*
4 6
1 2 15
1 3 2
1 4 10
2 4 4
2 3 4
3 4 7
4
*/
