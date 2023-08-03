#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
//#include"conio.h"
using namespace std;
long long e[85][85],dis[85],t,oo=1ll<<50;
int n,s;
char str[100];
bool vi[85];
queue<int> que;
int main()
{
	freopen("shopth.in","r",stdin);
	freopen("shopth.out","w",stdout);
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%s",str);
			if(strcmp(str,"-")!=0)
			{
				sscanf(str,"%lld",&t);
				e[i][j]=t;
			}
			else e[i][j]=oo;
//			fprintf(stderr,"%s ",str);
		}
//		fprintf(stderr,"\n");
	}
	for(int i=1;i<=n;i++) dis[i]=oo;
	dis[s]=0;
	vi[s]=1;
	que.push(s);
//	int es[]={12,13,14,15,12};
//	fprintf(stderr,"oo=%lld\n",oo);
//	long long sum=0;
//	for(int i=0;i<5;i++)
//	{
//		fprintf(stderr,"%d - %d = %lld\n",es[i],es[i+1],e[es[i]][es[i+1]]);
//		sum+=e[es[i]][es[i+1]];
//	}
//	fprintf(stderr,"sum=%lld\n",sum);
//	getch();
	while(que.size())
	{
		t=que.front();
//		fprintf(stderr,"head=%d dis is %lld\n",que.front(),dis[t]);
		vi[t]=0;
		for(int i=1;i<=n;i++)
			if(t!=i&&e[t][i]<oo&&dis[t]+e[t][i]<dis[i])
			{
				dis[i]=dis[t]+e[t][i];
				if(!vi[i])
				{
					vi[i]=1;
					que.push(i);
				}
//				fprintf(stderr,"\tinsert %d  father is %lld val=%lld=%lld+%lld\n",i,t,dis[i],dis[t],e[t][i]);
			}
		que.pop();
	}
	for(int i=1;i<=n;i++)
		if(i!=s) printf("(%d -> %d) = %lld\n",s,i,dis[i]);
	return 0;
}
