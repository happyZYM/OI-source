#include<iostream>
using namespace std;
int main()
{
	int j[13],a;
	while(true)
	{
		for(int i=0;i<13;i++) j[i]=0;
		for(int i=0;i<25;i++){
			cin>>a;
			j[a-1]=j[a-1]+1;
		} 
		for(int i=0;i<13;i++) if(j[i]<2) cout<<i+1;
	}
}
