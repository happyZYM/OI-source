#include<iostream>
using namespace std;
int main()
{
	int x,y,n;
	char sr[100][100];
	bool jl[100][100];
	while(true)
	{
		cin>>y>>x>>n;
		for(int i=0;i<100;i++) for(int j=0;j<100;j++) sr[j][i]='0';
		for(int i=0;i<y;i++) for(int j=0;j<x;j++) cin>>sr[j][i];
		for(int a=0;a<n;a++)
		{
		for(int ii=0;ii<100;ii++) for(int jj=0;jj<100;jj++) jl[jj][ii]=1;
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x-1;j++)
			{
				if((sr[j][i]!=sr[j+1][i])&&jl[j][i]&&jl[j+1][i])
				{
					switch(sr[j][i])
					{
						case 'R':
							if(sr[j+1][i]=='S') sr[j+1][i]='R';
							else sr[j][i]='P';
							jl[j][i]=jl[j+1][i]=0;
							break;
						case 'S':
							if(sr[j+1][i]=='P') sr[j+1][i]='S';
							else sr[j][i]='R';
							jl[j][i]=jl[j+1][i]=0;
							break;
						case 'P':
							if(sr[j+1][i]=='R') sr[j+1][i]='P';
							else sr[j][i]='S';
							jl[j][i]=jl[j+1][i]=0;
							break;
					}
				}
			}
		}
		for(int j=0;j<x;j++)
		{
			for(int i=0;i<y-1;i++)
			{
				if((sr[j][i]!=sr[j][i+1])&&jl[j][i]&&jl[j][i+1])
				{
					switch(sr[j][i])
					{
						case 'R':
							if(sr[j][i+1]=='S') sr[j][i+1]='R';
							else sr[j][i]='P';
							jl[j][i]=jl[j][i+1]=0;
							break;
						case 'S':
							if(sr[j][i+1]=='P') sr[j][i+1]='S';
							else sr[j][i]='R';
							jl[j][i]=jl[j][i+1]=0;
							break;
						case 'P':
							if(sr[j][i+1]=='R') sr[j][i+1]='P';
							else sr[j][i]='S';
							jl[j][i]=jl[j][i+1]=0;
							break;
					}
				}
			}
		}
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++) cout<<sr[j][i];
			cout<<endl;
		}
	    }
	}
}
