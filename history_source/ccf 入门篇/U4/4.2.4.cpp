#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string j;
	stringstream num;
	int s,b,n;
	while(true)
	{
		cin>>s>>b;
		n=0;
		num.flush();
		for(int i=0;i<b-s+1;i++) num<<s+i;
		num>>j;
		for(int i=0;i<j.size();i++) if(j[i]=='2') n++;
		cout<<n<<endl;
	}
}
