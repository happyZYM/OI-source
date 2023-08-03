#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	string a;
	char f;
	while(true)
	{
		cin>>a;
		for(int i=0;i<a.size();i++)
		{
			f=a[i];
			if(f>='A'&&f<='Z') f=(f-'A'+3)%26+'A';
			if(f>='a'&&f<='z') f=(f-'a'+3)%26+'a'; 
		    cout<<f;
		}
		cout<<endl<<endl;
	}
}
