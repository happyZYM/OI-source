#include<iostream>
using namespace std;
int main()
{
	char sr;
	long long ans,an;
	while(true)
	{
		ans=0;
		an=0;
		while(true)
		{
			sr=getchar();
			if(sr=='\n') break;
			if(sr=='+') {
				ans+=an;
				an=0;
			}
			else an=an*10+sr-'0';
		}
		ans+=an;
	    cout<<ans<<endl;
	}
}
