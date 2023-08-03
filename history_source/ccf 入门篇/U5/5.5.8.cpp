#include<iostream>
using namespace std;
int n,m,k,a[100][100],b[100][100],c[100][100];
int add(int x,int y)
{
	int an=0;
	for(int i=0;i<m;i++) an+=a[i][y]*b[x][i];
	return an;
}
int main()
{
	while(true)
	{
		cin>>n>>m>>k;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[j][i];
		for(int i=0;i<m;i++) for(int j=0;j<k;j++) cin>>b[j][i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<k;j++)
			{
				c[j][i]=add(j,i);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<k;j++) cout<<c[j][i]<<" ";
			cout<<endl;
		}
	}
}
