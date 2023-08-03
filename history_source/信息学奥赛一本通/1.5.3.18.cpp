#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int len=s.size();
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	return 0;
}
