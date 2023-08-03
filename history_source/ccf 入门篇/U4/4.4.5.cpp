#include<iostream>
using namespace std;
int main()
{
	int n,s,r,w,a;
	while(true)
	{
		cin>>n;
		a=0;
		for(w=0;w<=n/50;w++)
		{
			for(r=0;r<=n/20;r++)
			{
				for(s=0;s<=100/10;s++) if(w*50+r*20+s*10==n) a++;
			}
		}
		cout<<a<<endl;
	}
}
