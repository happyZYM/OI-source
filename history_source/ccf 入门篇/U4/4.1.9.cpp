#include<iostream>
using namespace std;
int main()
{
	int m,t,f;
	while(true)
	{
		m=0;
		cin>>t;
		for(int i=0;i<10;i++)
		{
			cin>>f;
			if(t+30>=f) m++;
		}
		cout<<m<<endl<<endl;
	}
}
