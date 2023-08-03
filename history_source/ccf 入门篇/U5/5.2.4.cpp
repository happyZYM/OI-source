#include<iostream>
using namespace std;
int main()
{
	int L,M,l[100],r[100],tree[10001];
	while(true)
	{
		cin>>L>>M;
		for(int i=0;i<=L;i++)
		{
			cin>>tree[i];
		}
		for(int i=0;i<M;i++)
		{
			cin>>l[i]>>r[i];
		}
		for(int i=0;i<M;i++)
		{
			if(r[i]-l[i]>100) r[i]=l[i]+100;
		}
		for(int i=0;i<M;i++)
		{
			for(int a=0;a<r[i]-l[i]+1;a++)
			{
				cout<<tree[l[i]+a]<<" ";
			}
		}
	}
}
