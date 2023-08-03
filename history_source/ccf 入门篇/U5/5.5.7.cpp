#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(true)
	{
		cin>>n>>m;
		int picture[m][n];
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>picture[j][i];
		cout<<endl;
		for(int i=0;i<m;i++) 
		{
			for(int j=0;j<n;j++) cout<<picture[i][n-1-j]<<" ";
			cout<<endl;
		}
	}
}
