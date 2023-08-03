#include<cstdio>
#include<algorithm>
using namespace std;
const int oo=1<<30;
int ML,MD,N;
int AL[10001],BL[10001],DL[10001];
int AD[10001],BD[10001],DD[10001];
int d[10001];
void solve()
{
	fill(d,d+N,oo);
	d[0]=0;
	for(int k=0;k<N;k++)
	{
		for(int i=0;i+1<N;i++)
			if(d[i+1]<oo) d[i]=min(d[i],d[i+1]);
		for(int i=0;i<ML;i++)
			if(d[AL[i]-1]<oo) d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
		for(int i=0;i<MD;i++)
			if(d[BD[i]-1]<oo) d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
	}
	int res=d[N-1];
	if(d[0]<0) res=-1;
	else if(res==oo) res=-2;
	printf("%d\n",res);
}
void init()
{
	scanf("%d%d%d",&N,&ML,&MD);
	int a,b,c;
	for(int i=0;i<ML;i++)
		scanf("%d%d%d",AL+i,BL+i,DL+i);
	for(int i=0;i<MD;i++)
		scanf("%d%d%d",AD+i,BD+i,DD+i);
}
int main()
{
	init();
	solve();
	return 0;
}
