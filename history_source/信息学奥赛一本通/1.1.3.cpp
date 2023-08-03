#include<iostream>
using namespace std;
void print(int n)
{
	if(n<10) cout<<"       ";
	else if(n<100) cout<<"      ";
	else if(n<1000) cout<<"     ";
	else if(n<10000) cout<<"    ";
	else if(n<100000) cout<<"   ";
	else if(n<1000000) cout<<"  ";
	else if(n<10000000) cout<<" ";
	cout<<n;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	print(a);
	cout<<" ";
	print(b);
	cout<<" ";
	print(c);
	return 0;
}
