#include<iostream>
using namespace std;
int main()
{
	bool p[52];
	for(int i=0;i<52;i++) p[i]=1;
	for(int i=2;i<=52;i++)
	{
		for(int a=1;a*i<=52;a++) p[a*i-1]=!p[a*i-1];
	}
	for(int i=0;i<52;i++) if(p[i]) cout<<i+1<<" ";
	while(true);
}
