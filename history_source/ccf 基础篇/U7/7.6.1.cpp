#include<iostream>
#include<string>
using namespace std;
string p,q,r;
long long ten(string sr,int j)
{
	long long add=0;
	for(int i=0;i<sr.size();i++)
	{
		add*=j;
		add+=sr[i]-'0';
	}
	return add;
}
int main()
{
	int b;
	while(true)
	{
		cin>>p>>q>>r;
		for(b=2;b<=16;b++)
		{
			if(ten(p,b)*ten(q,b)==ten(r,b)) break;
		}
		if(ten(p,b)*ten(q,b)==ten(r,b)) cout<<b<<endl;
		else cout<<0<<endl;
	}
} 

