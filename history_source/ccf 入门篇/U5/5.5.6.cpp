#include<iostream>
using namespace std;
int n;
bool sr[100][100];
bool pan()
{
	int addx=0,addy=0;
	for(int y=0;y<n;y++) 
	{
		for(int x=0;x<n;x++) if(sr[x][y]) addx++;
		if(addx%2==1) return 0;
		addx=0;
	}
	for(int x=0;x<n;x++) 
	{
		for(int y=0;y<n;y++) if(sr[x][y]) addy++;
		if(addy%2==1) return 0;
		addy=0;
	}
	return 1;
}
int main()
{
	while(true)
	{
		cin>>n;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>sr[i][j];
		if(pan()) cout<<"OK"<<endl;
		else
		{
			int x=0,y=0;
			for(y=0;y<n;y++)
			{
				for(x=0;x<n;x++)
				{
					sr[x][y]=!sr[x][y];
					if(pan())break;
					else sr[x][y]=!sr[x][y];
				}
				if(pan())break;
			}
			if(pan())cout<<"第"<<y+1<<"行,"<<"第"<<x+1<<"列"<<endl;
			else cout<<"Corrupt"<<endl;
		}
	}
}
