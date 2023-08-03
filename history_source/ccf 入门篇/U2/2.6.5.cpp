#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std; 
int main()
{
	srand(time(0));
	int a,b,c;
	a=rand()%1000000+1;
	b=rand()%1000000+1;
	c=rand()%1000000+1;
	cout<<a<<"-"<<b<<"+"<<c<<"+"<<c<<"*("<<a<<"-"<<b<<")="<<a-b+c+c*(a-b)<<endl;
	while(true);
}
