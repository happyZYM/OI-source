#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int f,i,s,a;
	while(true)
	{
		i=0;
		s=0;
		cin>>f;
		while(true)
		{
			a=f;
			a=a/pow(10,i);
			if(a==0) break;
			else
			{
			a=a%10;
			s=s+a;
			i++;	
			}
		}
		cout<<s<<endl;
	}
}
