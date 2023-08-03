#include<iostream>
using namespace std;
int main()
{
	int answer,fm,fz,m,n,sr[100][100],li;
	while(true)
	{
		cin>>m>>n;
		for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>sr[j][i];
		fm=m*n;
		fz=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>li;
				if(li==sr[j][i]) fz++;
			}
		}
		answer=fz*10000/fm;
		cout<<answer/100.0<<endl;
	}
}
