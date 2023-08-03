#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int i=0;
	double a,b;
	while(true){
		cin>>a>>b;
		if(a<b)cout<<a<<" % "<<b<<"="<<a;
		else{
			if(a==b)cout<<a<<" % "<<b<<"="<<0;
			else{
			for(i=1;i*b<a;i++);
			cout<<a<<" % "<<b<<"="<<a-b*(i-1);
		}
		}
		cout<<endl;
	}
}
