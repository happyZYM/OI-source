#include<iostream>
using namespace std;
int main()
{
	char sr;
	int add;
	while(true)
	{
		add=0;
		while((sr=getchar())!='\n') add+=sr-'0';
		cout<<add<<endl;
	}
}
