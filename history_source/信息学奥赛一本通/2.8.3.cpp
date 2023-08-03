#include<cstdio> 
int x,y,sum=0,maxn=-1;
#define up 0
#define down 2
#define left 3
#define right 1
int dx[]={ 0,1,0,-1},
	dy[]={-1,0,1, 0};
struct Node
{
	bool can[4],v=1;
};
Node Map[55][55];
void ope(Node &n,int p)
{
	n.can[left]=!(p&1);
	n.can[up]=!(p&2);
	n.can[right]=!(p&4);
	n.can[down]=!(p&8);
}
bool check(int xs,int ys)
{
	if(xs<0||xs>=x) return 0;
	if(ys<0||ys>=y) return 0;
	return Map[xs][ys].v;
}
int tuo(int xs,int ys)
{
	int ans=0;
	Map[xs][ys].v=0;
	for(int i=0;i<4;i++)
		if(Map[xs][ys].can[i]&&check(xs+dx[i],ys+dy[i]))
			ans+=tuo(xs+dx[i],ys+dy[i])+1;
	return ans;
}
int main()
{
	scanf("%d%d",&y,&x);
	int p,anss;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
		{
			scanf("%d",&p);
			ope(Map[j][i],p);
		}
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			if(Map[j][i].v)
			{
				anss=tuo(j,i);
				if(anss>maxn) maxn=anss;
				sum++;
			}
	printf("%d\n%d",sum,maxn+1);
	return 0;
}
