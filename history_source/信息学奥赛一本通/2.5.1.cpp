#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
char Map[25][25];
int y,x,ans=-1;
int dx[4]={0,1,0,-1},
	dy[4]={-1,0,1,0};
bool used[26]={0};
bool check(int xx,int yy)
{
	if(xx>=0&&xx<x&&yy>=0&&yy<y&&!used[Map[xx][yy]-'A']) return 1;
	return 0;
}
void dfs(int xx,int yy,int step)
{
	ans=max(ans,step);
	for(int i=0;i<4;i++)
	{
		if(check(xx+dx[i],yy+dy[i]))
		{
			used[Map[xx+dx[i]][yy+dy[i]]-'A']=1;
			dfs(xx+dx[i],yy+dy[i],step+1);
			used[Map[xx+dx[i]][yy+dy[i]]-'A']=0;
		}
	}
}
int main()
{
	cin>>y>>x;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			cin>>Map[j][i];
	used[Map[0][0]-'A']=1;
	dfs(0,0,1);
	cout<<ans<<endl;
	return 0;
}

