#include<iostream>
using namespace std;
char su[105][105];
bool s[105][105];
int n;
void cop()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(su[j][i]=='@') s[j][i]=1;
			else s[j][i]=0;
}
int main()
{
	int dx[]={0,1,0,-1};
	int dy[]={-1,0,1,0};
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>su[j][i];
			if(su[j][i]=='@') s[j][i]=1;
			else s[j][i]=0;
		}
	int m;
	cin>>m;
	for(int i=2;i<=m;i++)
	{
		for(int x=0;x<n;x++)
			for(int y=0;y<n;y++)
				if(su[x][y]=='@'&&s[x][y])
					for(int j=0;j<4;j++)
						if(x+dx[j]>=0&&x+dx[j]<n
						&&y+dy[j]>=0&&y+dy[j]<n
						&&su[x+dx[j]][y+dy[j]]=='.')
							su[x+dx[j]][y+dy[j]]='@';
		cop();
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(su[j][i]=='@') ans++;
	cout<<ans<<endl<<endl;
	return 0;
}
/*
5
....#
.#.@.
.#@..
#....
.....
4
*/
