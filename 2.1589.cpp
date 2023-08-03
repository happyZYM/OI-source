#include<iostream>
#include<cstring>
using namespace std;
#define che 1
#define ma  2
#define pao 3
#define hei 4
#define hong 5
int mp[15][15];
bool can[15][15];
int n,rx,ry,bx,by;
void Che(int x,int y)
{
	int dx[]={0,0,-1,1};
	int dy[]={-1,1,0,0};
	for(int i=0;i<4;i++)
		for(int k=1;x+dx[i]*k>=1&&x+dx[i]*k<=9&&y+dy[i]*k>=1&&y+dy[i]*k<=10;k++)
			{
				can[x+dx[i]*k][y+dy[i]*k]=0;
				if(mp[x+dx[i]*k][y+dy[i]*k]) break;
			}
}
void Ma(int x,int y)
{
	int dx[]={-1,+1,+2,+2,+1,-1,-2,-2};
	int dy[]={-2,-2,-1,+1,+2,+2,+1,-1};
	int mx[]={+0,+0,+1,+1,+0,+0,-1,-1};
	int my[]={-1,-1,+0,+0,+1,+1,+0,+0};
	for(int i=0;i<8;i++)
		if(x+dx[i]>=1&&x+dx[i]<=9&&y+dy[i]>=1&&y+dy[i]<=10
			&&mp[x+mx[i]][y+my[i]]==0)
			can[x+dx[i]][y+dy[i]]=0;
}
void Pao(int x,int y)
{
	int dx[]={0,0,-1,1};
	int dy[]={-1,1,0,0};
	bool flag=0;
	for(int i=0;i<4;i++)
		for(int k=1;x+dx[i]*k>=1&&x+dx[i]*k<=9&&y+dy[i]*k>=1&&y+dy[i]*k<=10;k++)
		{
			if(!flag&&mp[x+dx[i]*k][y+dy[i]*k])
			{
				flag=1;
				continue;
			}
			if(flag&&mp[x+dx[i]*k][y+dy[i]*k]) break;
			if(flag) can[x+dx[i]*k][y+dy[i]*k]=0;
		}
}
void solve()
{
	can[rx][ry--]=0;
	while(ry>0)
	{
		can[rx][ry]=0;//½«
		if(mp[rx][ry]) break;
		ry--;
	}
	for(int i=1;i<=10;i++)
		for(int j=1;j<=9;j++)
			switch(mp[j][i])
			{
				case che:
					Che(j,i);
					break;
				case ma:
					Ma(j,i);
					break;
				case pao:
					Pao(j,i);
					break;
			}
	int dx[]={0,0,-1,1};
	int dy[]={-1,1,0,0};
	for(int i=0;i<4;i++)
		if(bx+dx[i]>=4&&bx+dx[i]<=6&&by+dy[i]>=1&&by+dy[i]<=3
			&&can[bx+dx[i]][by+dy[i]])
			{
				printf("NO\n");
				return;
			}
	printf("YES\n");
}
int main()
{
	while(cin>>n>>by>>bx)
	{
		if(n==0&&bx==0&&by==0) break;
		memset(mp,0,sizeof(mp));
		memset(can,1,sizeof(can));
		mp[by][bx]=hei;
		int a,b;
		char t;
		for(int i=0;i<n;i++)
		{
			cin>>t>>a>>b;
			switch(t)
			{
				case 'G':
					mp[b][a]=hong;
					rx=b;
					ry=a;
					break;
				case 'R':
					mp[b][a]=che;
					break;
				case 'H':
					mp[b][a]=ma;
					break;
				case 'C':
					mp[b][a]=pao;
					break;
			}
		}
		solve();
	}
	return 0;
}
/*
2 1 4
G 10 5
R 6 4
3 1 5
H 4 5
G 10 5
C 7 5
0 0 0
*/
