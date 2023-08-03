#include<iostream> 
#define MAXN 20
using namespace std;
int huan[MAXN][MAXN];
int main()
{
	int n,x,y;
	ios::sync_with_stdio(0);
	cin>>n;
	huan[n/2][0]=1;
	x=n/2;
	y=0;
	for(int i=2;i<=n*n;i++)
	{
		if(y==0&&x!=n-1)
		{
			huan[x+1][n-1]=i;
			x=x+1;
			y=n-1;
		}else if(x==n-1&&y!=0)
		{
			huan[0][y-1]=i;
			x=0;
			y=y-1;
		}else if(y==0&&x==n-1)
		{
			huan[x][y+1]=i;
			x=x;
			y=y+1;
		}else
		{
			if(huan[x+1][y-1]==0)
			{
				huan[x+1][y-1]=i;
				x=x+1;
				y=y-1;
			}
			else
			{
				huan[x][y+1]=i;
				x=x;
				y=y+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) cout<<huan[j][i]<<" ";
		cout<<"\n";
	}
	cout<<flush;
	return 0;
}

