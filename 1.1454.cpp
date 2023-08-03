#include<iostream>
using namespace std;
int y,x;
char mp[105][105];
int dx[12]={0,0,1,-1,1,-1,-1,1,0,0,2,-2};//各个位置
int dy[12]={1,-1,0,0,1,-1,1,-1,2,-2,0,0};
void dfs(int xs,int ys)
{
	if(mp[xs][ys]!='#') return;
	mp[xs][ys]=0;
	for(int i=0;i<12;i++)
		dfs(xs+dx[i],ys+dy[i]);
}
int main()
{
	cin>>y>>x;
	for(int i=2;i<=y+1;i++)
		for(int j=2;j<=x+1;j++)
			cin>>mp[j][i];
	int cnt=0;
	for(int i=2;i<=y+1;i++)
		for(int j=2;j<=x+1;j++)
			if(mp[j][i]=='#')
			{
				cnt++;
				dfs(j,i);
			}
	cout<<cnt<<endl;
	return 0;
}
