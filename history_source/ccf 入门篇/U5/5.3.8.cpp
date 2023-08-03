#include<iostream>
using namespace std;
int main()//20 40 32 67 40 20 89 300 400 15
{
	int n,m,x;
	while(true)
	{
		cin>>n;
		int sr[n];
		for(int i=0;i<n;i++) cin>>sr[i];
		for(int i=n-1;i>0;i--)
		{
			for(int j=0;j<i;j++)
			{
			    if(sr[j]>sr[j+1]){
			    	x=sr[j];
			    	sr[j]=sr[j+1];
			    	sr[j+1]=x;
				}	
			}
		}
		m=n;
		x=sr[0];
		for(int i=1;i<n;i++)
		{
			if(x==sr[i]) m--;
			x=sr[i];
		}
		cout<<m<<endl;
		x=sr[0];
		cout<<x<<" ";
		for(int i=1;i<n;i++)
		{
			if(x!=sr[i]) cout<<sr[i]<<" ";
			x=sr[i];
		}
		cout<<endl;
	}
}
