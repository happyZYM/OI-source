#include<iostream>
#include<string>
using namespace std;
int main()
{
	string max,maxn;
	char w;
	while(w=getchar(),w!='\n'&&w!='.')
	{
		if(w==' ')
		{
			if(maxn.size()>max.size()) max=maxn;
			maxn="";
		}
		else maxn+=w;
	} 
	if(maxn.size()>max.size()) max=maxn;
	cout<<max<<endl; 
	return 0;
}
