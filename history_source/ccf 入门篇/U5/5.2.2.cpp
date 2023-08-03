#include<iostream>
using namespace std;
int main()
{
	int d[10]={1,1,1,1,1,1,1,1,1,1};
	int a=-1;
	for(int i=1;i<=1000;i++) 
	{
		a+=i;
		d[a%10]=0;
	}
	int i;
	for(i=0;i<10;i++) if(d[i]==1) cout<<i+1<<"ºÅ ";
	while(true);
}
