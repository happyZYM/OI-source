#include<iostream>
#include<string>
using namespace std;
void turn1(string &n)
{
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='a'&&n[i]<='z') n[i]=n[i]-32;
		else if(n[i]>='A'&&n[i]<='Z') n[i]=n[i]+32;
	}
}
void turn2(string &n)
{
	char li;
	for(int i=0,j=n.size()-1;i<j;i++,j--)
	{
		li=n[i];
		n[i]=n[j];
		n[j]=li;
	}
} 
void turn3(string &n)
{
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='a'&&n[i]<='z')
		{
			if(n[i]<='w') n[i]+=3;
			else n[i]-=23;
		}
		else
		{
			if(n[i]<='W') n[i]+=3;
			else n[i]-=23;
		}
	}
} 
int main()
{
	string a;
	cin>>a;
	turn1(a);
	turn2(a);
	turn3(a);
	cout<<a<<endl;
	return 0;
}

