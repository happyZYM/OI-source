#include<iostream>
using namespace std;
int main()
{
	int jv[5][5];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>jv[j][i];
	int n,m;
	cin>>n>>m;
	n--;
	m--;
	for(int i=0;i<5;i++)
	{
		if(i!=n&&i!=m) 
			for(int j=0;j<5;j++)
				cout<<jv[j][i]<<" ";
		else
		{
			if(i==m)
				for(int j=0;j<5;j++)
					cout<<jv[j][n]<<" ";
			else
				for(int j=0;j<5;j++)
					cout<<jv[j][m]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

