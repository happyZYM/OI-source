#include<iostream>
#include<string>
using namespace std;
void eraseZero(string &a)
{
	while(a[0]=='0'&&a.size()>1) a.erase(0,1);
}
int main()
{
	string a,b,c;
	cin>>a>>b;
	int x,j=0,ai,bi;
	for(ai=a.size()-1,bi=b.size()-1;bi>=0;ai--,bi--)
	{
		x=(a[ai]-'0')-(b[bi]-'0')-j;
		if(x<0) j=1,x+=10;
		else j=0;
		c=char('0'+x)+c;
	}
	while(ai>=0)
	{
		x=a[ai]-'0'-j;
		if(x<0) j=1,x+=10;
		else j=0;
		c=char('0'+x)+c;
		ai--;
	}
	eraseZero(c);
	cout<<c<<endl;
	return 0;
}
