#include<iostream>
using namespace std;
int main()
{
	int n,m,add;
	char sr[100][100];
	while(true)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>sr[j][i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(sr[j][i]=='?')
				{
					add=0;
					if(j>0&&i>0&&sr[j-1][i-1]=='*') add++;
					if(j>0&&i<n-1&&sr[j-1][i+1]=='*') add++;
					if(j<m-1&&i>0&&sr[j+1][i-1]=='*') add++;
					if(j<m-1&&i<n-1&&sr[j+1][i+1]=='*') add++;
					if(j>0&&sr[j-1][i]=='*') add++;
					if(j<m-1&&sr[j+1][i]=='*') add++;
					if(i>0&&sr[j][i-1]=='*') add++;
					if(i<n-1&&sr[j][i+1]=='*') add++;
					sr[j][i]='0'+add;
				}
			}
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) cout<<sr[j][i];
			cout<<endl;
		}
		cout<<endl;
	}
}
