#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
struct node1
{
	int x1,y1,x2,y2;
};
struct node2
{
	int x,y,id;
};
int n;
node1 ps[27];
node2 po[27];
vector<int> e[27];
bool hsh[27],found;
int  res[27],ans[27];
void dfs(int pos)
{
	if(pos>n)
	{
		if(found)
		{
			printf("None\n");
			exit(0);
		}
		found=1;
		for(int i=1;i<=n;i++) ans[i]=res[i];
		return;
	}
	for(int i=e[pos].size()-1;i>=0;i--)
		if(!hsh[e[pos][i]])
		{
			hsh[e[pos][i]]=1;
			res[pos]=e[pos][i];
			dfs(pos+1);
			hsh[e[pos][i]]=0;
		}
}
int main()
{
	freopen("slides.in","r",stdin);
	freopen("slides.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&ps[i].x1,&ps[i].x2,&ps[i].y1,&ps[i].y2);
	for(int i=1;i<=n;i++)//po[i].id=i
	{
		scanf("%d%d",&po[i].x,&po[i].y);
		po[i].id=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(ps[i].x1<=po[j].x&&po[j].x<=ps[i].x2
			   &&ps[i].y1<=po[j].y&&po[j].y<=ps[i].y2)
			   e[i].push_back(j);
	}
	dfs(1);
	if(found) for(int i=1;i<=n;i++) printf("%c %d\n",i+'A'-1,ans[i]);
	else printf("None\n");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%c:",i+'A'-1);
//		for(int j=0;j<e[i].size();j++) printf(" %d",e[i][j]);
//		printf("\n");
//	}
	return 0;
}
/*
4
6 22 10 20
4 18 6 16
8 20 2 18
10 24 4 8
9 15
19 17
11 7
21 11
*/
