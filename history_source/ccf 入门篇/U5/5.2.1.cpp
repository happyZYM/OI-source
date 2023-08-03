#include<iostream>
using namespace std;
int main()
{
	int n,sr[10000],li,w;
	while(true)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>sr[i];
		w=0;
		for(int i=1;i<n;i++) if(sr[i]<sr[w]) w=i;
		li=sr[w];
		for(int i=w;i>0;i--) sr[i]=sr[i-1];
		sr[0]=li;
		for(int i=0;i<n;i++) cout<<sr[i]<<" ";
		cout<<endl<<endl;
	}
}
