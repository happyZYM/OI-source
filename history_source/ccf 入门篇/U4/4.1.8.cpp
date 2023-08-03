#include<iostream>
using namespace std;
int main()
{
	int a,b,s,f;
	while(true)
	{
		cin>>s;
		b=s+1;
		a=a+s;
		for(int i=0;i<9;i++)
		{
			cin>>f;
			if(f>b) b=f;
			if(f<s) s=f;
			a=a+f;
		}
		cout<<(a-b-s)/8.0<<endl<<endl;
	}
}
