#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
#define non 0
#define black 1
#define white -1 
int mp[10][10],tmp[10][10];
vector<pair<int,int> > cmd;
bool flag=0;
void print()
{
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
			switch(mp[i][j])
			{
				case non:
					putchar('-');
					break;
				case black:
					putchar('B');
					break;
				case white:
					putchar('W');
					break;
			}
		putchar('\n');
	}
}
int dx[]={+0,+1,+1,+1,+0,-1,-1,-1};
int dy[]={-1,-1,+0,+1,+1,+1,+0,-1};
bool put(int x,int y,int id,int st)
{
	int i,k,j;
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
			tmp[i][j]=mp[i][j];
	if(tmp[y][x]) return 0;
	bool flag=0;
	for(i=0;i<8;i++)
	{
		for(k=1;x+dx[i]*k>=1&&x+dx[i]*k<=8&&y+dy[i]*k>=1&&y+dy[i]*k<=8&&tmp[y+dy[i]*k][x+dx[i]*k]==-id;k++);
		if(tmp[y+dy[i]*k][x+dx[i]*k]==id&&k>=2)
		{
			flag=1;
			for(j=1;j<k;j++)
				tmp[y+dy[i]*j][x+dx[i]*j]=id;
			tmp[y][x]=id;
		}
	}
	if(st)
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				mp[i][j]=tmp[i][j];
	return flag;
}
void solve()
{
	if(flag) printf("\n");
	flag=1;
	char t;
	int a,b,bl,wh;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
		{
			cin>>t;
			switch(t)
			{
				case '-':
					mp[i][j]=0;
					break;
				case 'B':
					mp[i][j]=black;
					break;
				case 'W':
					mp[i][j]=white;
					break;
			}
		}
	int now;
	cin>>t;
	if(t=='W') now=white;
	else now=black;
	while(1)
	{
		cin>>t;
		if(t=='Q')
		{
			print();
			return;
		}
		if(t=='L')
		{
			cmd.clear();
			for(int i=1;i<=8;i++)
				for(int j=1;j<=8;j++)
					if(put(j,i,now,0)) cmd.push_back(make_pair(i,j));
			if(cmd.empty()) printf("No legal move.");
			else for(int i=0;i<cmd.size();i++)
			{
				if(i) printf(" ");
				printf("(%d,%d)",cmd[i].first,cmd[i].second);
			}
			printf("\n");
		}
		else
		{
			a=getchar()-'0';
			b=getchar()-'0';
			if(!put(b,a,now,1)) put(b,a,now=-now,1);
			now=-now;
			bl=wh=0;
			for(int i=1;i<=8;i++)
				for(int j=1;j<=8;j++)
					if(mp[i][j]==black) bl++;
					else if(mp[i][j]==white) wh++;
			printf("Black - %2d White - %2d\n",bl,wh);
		}
	}
}
int main()
{
//	freopen("pro.in","r",stdin);
	int n;
	cin>>n;
	while(n-->0)
	{
		memset(mp,0,sizeof(mp));
		solve();
	}
	return 0;
}
/*
Sample Input
2
--------
--------
--------
---WB---
---BW---
--------
--------
--------
W
L
M35
L
Q
WWWWB---
WWWB----
WWB-----
WB------
--------
--------
--------
--------
B
L
M25
L
Q
Sample Output
(3,5) (4,6) (5,3) (6,4)
Black -  1 White -  4
(3,4) (3,6) (5,6)
--------
--------
----W---
---WW---
---BW---
--------
--------
--------
No legal move.
Black -  3 White - 12
(3,5)
WWWWB---
WWWWW---
WWB-----
WB------
--------
--------
--------
--------
*/
