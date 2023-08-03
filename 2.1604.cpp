#include<bits/stdc++.h>
using namespace std;

//上 前
//0  1

//0 1 2 3
//E B W R
#define empty 0
#define blue  1
#define white 2
#define red   3

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,1,-1};
pair<int,int> a[5][5];
int goal[5][5],ans;

inline int other(int x,int y)
{
	return 6-(x+y);
}
inline void rotate_left_right(pair<int,int> &x)
{
	pair<int,int> temp=x;
	x.first=other(temp.first,temp.second);
	x.second=temp.second;
}
inline void rotate_up_down(pair<int,int> &x)
{
	pair<int,int> temp=x;
	x.first=temp.second;
	x.second=temp.first;
}
inline int diff()
{
	int cnt=0;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (a[i][j].first!=goal[i][j])
				cnt++;
	return cnt;
}

void dfs(int dep,int prex,int prey)
{
	int differ=diff();
	if(differ==0)
	{
		if(dep<ans) ans=dep;
		return;
	}
	if(dep+differ>ans) return;
	int x,y;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(a[i][j].first==0)
				x=i,y=j;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=1&&tx<=3&&ty>=1&&ty<=3&&!(tx==prex&&ty==prey))
		{
			pair<int,int> temp=a[tx][ty];
			if (i>1)
				rotate_left_right(a[tx][ty]);
			else
				rotate_up_down(a[tx][ty]);
			swap(a[tx][ty],a[x][y]);
			dfs(dep+1,x,y);
			a[tx][ty]=temp;
			a[x][y]={0,0};
		}
	}
}

int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int x,y;
	while(cin>>x>>y)
	{
		swap(x,y);
		if(x==0&&y==0) break;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				if(i==x&&y==j) a[i][j]={0,0};
				else a[i][j]={2,3};
			}
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				char c;
				cin>>c;
				goal[i][j]=empty;
				switch(c)
				{
					case 'B':goal[i][j]=blue;break;
					case 'W':goal[i][j]=white;break;
					case 'R':goal[i][j]=red;break;
				}
			}
		ans=31;
		dfs(0,-1,-1);
		if(ans>=31) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
